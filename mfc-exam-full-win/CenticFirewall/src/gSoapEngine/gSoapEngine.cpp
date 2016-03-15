#include "StdAfx.h"
#include "gSoapEngine.h"


#include "soapH.h"
#include "ctSoap.nsmap"
#include <assert.h>
#include "stdio.h"

#include <string.h>

// use the default endpoint set in ctSoap.h for demo:
const char *endpoint = "https://10.49.46.199:8085";


static struct soap ctSoapMainEngine;



////////////////////////////////////////////////////////////////////////////////
//
//	Helper functions
//
////////////////////////////////////////////////////////////////////////////////

static void saveData(ns__Data& data, const char *name)
{
	fprintf(stderr, "saveData save file %s\n", name);

	char *buf = (char*)data.__ptr;
	int len = data.__size;
	FILE *fd = fopen(name, "wb");
	if (!fd)
	{ fprintf(stderr, "Cannot save file %s\n", name);
		return;
	}
	while (len)
	{
		size_t nwritten = fwrite(buf, 1, len, fd);
		if (!nwritten)
		{ fprintf(stderr, "Cannot write to %s\n", name);
			return;
		}
		len -= nwritten;
		buf += nwritten;
	}
	printf("Saved file %s\n", name);
}


static bool putData(struct soap *soap, std::vector<std::string> *nameList)
{
	TRACE(traceAppMsg, 0, "gSoapEngine putData \n");
	arrayOfData data;
	arrayOfName names;

	data.resize(nameList->size());
	for (int i = 0; i < (int)nameList->size(); i++)
	{ 
		data[i].__ptr = (unsigned char*)nameList->at(i).c_str();
		
		// MUST set id or type to enable DIME
		// zero size indicates streaming DIME (this requires HTTP chunking)
		data[i].type = (char*)"";
	}
	if (soap_call_ns__putData(soap, endpoint, NULL, nameList, &data, &names))
		soap_print_fault(soap, stderr);
	
	else
	{
		printf("Data stored with keys:\n");
		for (int j = 0; j < names.size(); j++){
			//printf("\t%s\n", names[j]);
			TRACE(traceAppMsg, 0, "\t%s\n", names[j]);
		}
		printf("Use these keys to retrieve the data\n");

		return true;
	}

	return false;
}

static bool getData(struct soap *soap, std::vector<std::string> *nameList, 
	std::vector<std::string> *saveList) 
{ 
	
	arrayOfData data;
	arrayOfName names;
	names.resize(nameList->size());
	for (int i = 0; i < nameList->size(); i++)
		names[i] = (char*)nameList->at(i).c_str();

	soap->user = (void*)names.__ptr;

	if (soap_call_ns__getData(soap, endpoint, NULL, &names, &data))
		soap_print_fault(soap, stderr);
	else
	{ 
		for (int j = 0; j < data.size(); j++){
			if (!data[j].id){
				saveData(data[j], nameList->at(j).c_str());
				//printf("gSoapEngine getData %s\n", saveList->at(j).c_str());

			}
		}
		
		
		return true;
	}

	return false;
}

static void getImage(struct soap *soap, char *name)
{
	ns__Data image;
	arrayOfName temp;
	temp.resize(1);
	temp[0] = name;
	soap->user = (void*)temp.__ptr;
	if (soap_call_ns__getImage(soap, endpoint, NULL, name, image))
		soap_print_fault(soap, stderr);
	else if (image.id)
	{ if (image.__size)
			printf("Got image %s size=%d type=%s through streaming DIME\n", name, image.__size, image.type?image.type:"");
		else
			printf("Got image %s type=%s through chunked streaming DIME\n", name, image.type?image.type:"");
	}
	else
	{ printf("Got image %s\n", name);
		saveData(image, name);
	}
}

////////////////////////////////////////////////////////////////////////////////
//
//	Streaming DIME attachment content handlers
//
////////////////////////////////////////////////////////////////////////////////

static void *dime_read_open(struct soap *soap, void *handle, const char *id, const char *type, const char *options)
{ FILE *fd;
	// we should return NULL without setting soap->error if we don't want to use the streaming callback for this DIME attachment. The handle contains the non-NULL __ptr field value which should have been set in the application.
	// return value of this function will be passed on to the fdimeread and fdimereadclose callbacks. The return value will not affect the __ptr field.
	fd = fopen((char*)handle, "rb");
	return (void*)fd;
}

static void dime_read_close(struct soap *soap, void *handle)
{ fclose((FILE*)handle);
}

static size_t dime_read(struct soap *soap, void *handle, char *buf, size_t len)
{ return fread(buf, 1, len, (FILE*)handle);
}

static void *dime_write_open(struct soap *soap, const char *id, const char *type, const char *options)
{ // we can return NULL without setting soap->error if we don't want to use the streaming callback for this DIME attachment
	FILE *handle = NULL;
	char name[64];
	// get file name from options (not '\0' terminated)
	if (options)
	{ 
		size_t len = ((unsigned char)options[2] << 8) | ((unsigned char)options[3]); // option string length
		//name = (char*)soap_malloc(soap, len + 1);
		memset(name, '\0', sizeof(name));
		strncpy(name, options + 4, len);
		name[len] = '\0';
		handle = fopen(name, "wb");
		if (!handle)
		{ 
			soap->error = SOAP_EOF; // could not open file for writing
			soap->errnum = errno; // get reason
			return NULL;
		}
	}
	else
		soap->error = soap_receiver_fault(soap, "Cannot save to file, because no file name was present in attachment", NULL);
	return (void*)handle;
}

static void dime_write_close(struct soap *soap, void *handle)
{ 
	fclose((FILE*)handle);
}

static int dime_write(struct soap *soap, void *handle, const char *buf, size_t len)
{ 
	while (len)
	{ size_t nwritten = fwrite(buf, 1, len, (FILE*)handle);
		if (!nwritten)
		{ soap->errnum = errno; // get reason
			return SOAP_EOF;
		}
		len -= nwritten;
		buf += nwritten;
	}
	return SOAP_OK;
}

////////////////////////////////////////////////////////////////////////////////
//
//	ns__Data class
//
////////////////////////////////////////////////////////////////////////////////

ns__Data::ns__Data()
{ __ptr = NULL;
	__size = 0;
	id = NULL;
	type = NULL;
	options = NULL;
	soap = NULL;
}

////////////////////////////////////////////////////////////////////////////////
//
//	arrayOfData class
//
////////////////////////////////////////////////////////////////////////////////

arrayOfData::arrayOfData()
{ __ptr = NULL;
	__size = 0;
	soap = NULL;
}

arrayOfData::arrayOfData(struct soap *soap, int n)
{ __ptr = NULL;
	__size = 0;
	this->soap = soap;
	resize(n);
}

arrayOfData::~arrayOfData()
{ resize(0);
}

int arrayOfData::size()
{ return __size;
}

void arrayOfData::resize(int n)
{ if (__ptr)
	{ if (soap) // if created by soap environment
			soap_delete(soap, __ptr); // then delete
		else
			delete[] __ptr;
	}
	__size = n;
	if (n <= 0)
		__ptr = NULL;
	else if (soap)
		__ptr = soap_new_ns__Data(soap, n);
	else
		__ptr = new ns__Data[n];
}

ns__Data& arrayOfData::operator[](int i) const
{ assert(__ptr && i >= 0 && i < __size);
	return __ptr[i];
}

////////////////////////////////////////////////////////////////////////////////
//
//	arrayOfName class
//
////////////////////////////////////////////////////////////////////////////////

arrayOfName::arrayOfName()
{ __ptr = NULL;
	__size = 0;
	soap = NULL;
}

arrayOfName::arrayOfName(struct soap *soap, int n)
{ __ptr = NULL;
	__size = 0;
	this->soap = soap;
	resize(n);
}

arrayOfName::~arrayOfName()
{ resize(0);
}

int arrayOfName::size()
{ return __size;
}

void arrayOfName::resize(int n)
{ if (__ptr)
	{ if (soap) // if created by soap environment
			soap_delete(soap, __ptr); // then delete
		else
			free(__ptr);
	}
	__size = n;
	if (n <= 0)
		__ptr = NULL;
	else
	{ if (soap)
			__ptr = (char**)soap_malloc(soap, sizeof(char*) * n);
		else
			__ptr = (char**)malloc(sizeof(char*) * n);
		memset(__ptr, 0, n);
	}
}

char*& arrayOfName::operator[](int i) const
{ assert(__ptr && i >= 0 && i < __size);
	return __ptr[i];
}

//==============================================================================
// Main gSoapEngine
//==============================================================================
gSoapEngine::gSoapEngine(void)
{
#if 1
	soap_init1(&ctSoapMainEngine, SOAP_IO_CHUNK);
	// set ctSoapMainEngine callbacks
	ctSoapMainEngine.fdimereadopen = dime_read_open;
	ctSoapMainEngine.fdimereadclose = dime_read_close;
	ctSoapMainEngine.fdimeread = dime_read;
	ctSoapMainEngine.fdimewriteopen = dime_write_open;
	ctSoapMainEngine.fdimewriteclose = dime_write_close;
	ctSoapMainEngine.fdimewrite = dime_write;
	// connect timeout value (not supported by Linux)
	ctSoapMainEngine.connect_timeout = 2;
	// IO timeouts
	ctSoapMainEngine.send_timeout = 2;
	ctSoapMainEngine.recv_timeout = 2;


	soap_ssl_init();

	if (soap_ssl_client_context(&ctSoapMainEngine,
								//SOAP_SSL_DEFAULT,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								NULL, 		/* keyfile: required only when client must authenticate to server (see SSL docs on how to obtain this file) */
								NULL, 		/* password to read the keyfile */
								"cacert.pem",	/* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
								NULL,		/* optional capath to directory with trusted certificates */
								NULL		/* if randfile!=NULL: use a file with random data to seed randomness */
								))
	{
		TRACE(L"soap_ssl_client_context FAIL \n");
		soap_print_fault(&ctSoapMainEngine, stderr);		
		return ;
	}
#endif
}


gSoapEngine::~gSoapEngine(void)
{
	// detach
	soap_done(&ctSoapMainEngine);
}





//==============================================================================
// login
//==============================================================================
///
/// \brief ns__login
/// \param soap
/// \param username
/// \param passwd
/// \param ret
/// \return
///
bool gSoapEngine::login(char * username, char * passwd)
{

	TRACE(traceAppMsg, 0, "gSoapEngine::login user: %s, passwd: %s \n", username, passwd);
	bool ret = false;
	
	m_gsoapSection.Lock();
	if (soap_call_ns__login(&ctSoapMainEngine, endpoint, NULL, username, passwd, &ret)){
		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{
		m_gsoapSection.Unlock();
		return ret;
	}
	m_gsoapSection.Unlock();
	return false;
}

//==============================================================================
// CenticFirewallRuntime
// Get runtime information: connection status to device, traffic info (in/out speed)
//==============================================================================
///
/// \brief ns__getRuntimeInfo
/// \param soap
/// \param ret
/// \return
///
bool gSoapEngine::getRuntimeInfo(RuntimeInfo_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getRuntimeInfo(&ctSoapMainEngine, endpoint, NULL, NULL, ret)){
		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{

		m_gsoapSection.Unlock();
		return true;
	}
	m_gsoapSection.Unlock();

	return false;
}


//==============================================================================
// system
//==============================================================================
// System::Home
// Get list of interface
bool gSoapEngine::getSysHomeInterface(NetInterface_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getSysHomeInterface(&ctSoapMainEngine, endpoint, NULL, NULL, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{
		m_gsoapSection.Unlock();
		return true;
	}
	m_gsoapSection.Unlock();

	return false;
}


bool gSoapEngine::SysBackupHandle(enum ns__SysBackupEvent in, char *path)
{
	TRACE(traceAppMsg, 0, "gSoapEngine::SysBackupHandle in: %d, path: %s \n", in, path);
	std::vector<std::string> nameList;
	std::vector<std::string> saveList;
	bool ret = false;
	SysBackupRet_t retfilename;

	m_gsoapSection.Lock();

	switch(in){
	case EVENT_BACKUP_CONFIGURATION:
	case EVENT_BACKUP_FIRMWARE :

		//get filename
		if (soap_call_ns__SysBackupHandle(&ctSoapMainEngine, endpoint, NULL, 
			(in == EVENT_BACKUP_CONFIGURATION) ? EVENT_GET_FILENAME_CONFIG:EVENT_GET_FILENAME_FIRMWARE, path, &retfilename)){
			soap_print_fault(&ctSoapMainEngine, stderr);
			break;
		}
	
		

		nameList.push_back(retfilename.filename);
		saveList.push_back(path);

		TRACE(traceAppMsg, 0, "retfilename: %s \n", nameList.at(0).c_str());
		TRACE(traceAppMsg, 0, "saveList: %s \n", saveList.at(0).c_str());

		//get file from board
		if(getData(&ctSoapMainEngine, &nameList, &saveList)){
			if (soap_call_ns__SysBackupHandle(&ctSoapMainEngine, endpoint, NULL, in, path, NULL)){
				soap_print_fault(&ctSoapMainEngine, stderr);
			}else{		
				ret = true;				
			}
		}
		break;
	case EVENT_UPDATE_CONFIGURATION:
	case EVENT_UPDATE_FIRMWARE:

		//set filename
		if (soap_call_ns__SysBackupHandle(&ctSoapMainEngine, endpoint, NULL, 
			(in == EVENT_UPDATE_CONFIGURATION) ? EVENT_SET_FILENAME_CONFIG:EVENT_SET_FILENAME_FIRMWARE, path, NULL)){
			soap_print_fault(&ctSoapMainEngine, stderr);
			break;
		}
		nameList.push_back(path);

		//put file to board
		if(putData(&ctSoapMainEngine, &nameList)){
			if (soap_call_ns__SysBackupHandle(&ctSoapMainEngine, endpoint, NULL, in, path, NULL)){

				soap_print_fault(&ctSoapMainEngine, stderr);
			}else{		
				ret = true;				
			}
		}
		break;
	default:
		break;
	}
	m_gsoapSection.Unlock();
	//TRACE(traceAppMsg, 0, "gSoapEngine::SysBackupHandle Done %s \n", ret?"OK":"FAIL");
	return ret;
}


bool gSoapEngine::getSysSysInfo(SysInfo_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getSysSysInfo(&ctSoapMainEngine, endpoint, NULL, NULL, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}


bool gSoapEngine::SysShutdownHandle(enum ns__SysShutdownEvent action)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__SysShutdownHandle(&ctSoapMainEngine, endpoint, NULL, action, NULL)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}


//==============================================================================
// status
//==============================================================================
// Status::system
// get CPU and Memory percent list
/// \param mode : hour, day, week, month, year

bool gSoapEngine::getStatusSystemGraph(enum SysGraphMode_t mode, SystemData_t *ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusSystemGraph(&ctSoapMainEngine, endpoint, NULL, mode, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();

	return false;
}

bool gSoapEngine::getStatusServices(StatusServicesList_t *ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusServices(&ctSoapMainEngine, endpoint, NULL, NULL, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}

	m_gsoapSection.Unlock();
	return false;
}


bool gSoapEngine::getStatusNetworkExternal(enum SysGraphMode_t mode, NetworkData_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusNetworkExternal(&ctSoapMainEngine, endpoint, NULL, mode, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	


		//TRACE(traceAppMsg, 0, "graphListData->size() <%d> \n", ret->graphListData.size());
		//TRACE(traceAppMsg, 0, "netListTraffic->size() <%d> \n", ret->netListTraffic.size());
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}


bool gSoapEngine::getStatusNetworkInternal(enum SysGraphMode_t mode, NetworkData_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusNetworkInternal(&ctSoapMainEngine, endpoint, NULL, mode, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}


bool gSoapEngine::getStatusNetworkOther(enum SysGraphMode_t mode, NetworkData_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusNetworkOther(&ctSoapMainEngine, endpoint, NULL, mode, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}

bool gSoapEngine::getStatusConnection(StatusConnList_t * ret)
{
	m_gsoapSection.Lock();
	if (soap_call_ns__getStatusConnection(&ctSoapMainEngine, endpoint, NULL, NULL, ret)){

		soap_print_fault(&ctSoapMainEngine, stderr);
	}else{	
		m_gsoapSection.Unlock();
		return true;				
	}
	m_gsoapSection.Unlock();
	return false;
}


//==============================================================================
// MAIN GSOAP ENGINE
//==============================================================================
gSoapEngine ctSoapEngine;