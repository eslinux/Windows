
#include "soapH.h"
#include "ctSoap.nsmap"

#include "stdio.h"
#include <sys/stat.h>	// use fstat() for streaming DIME
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>
#ifdef _POSIX_THREADS
#include <pthread.h>	// use Pthreads
#endif

#include <stdlib.h>
#include <time.h>


#include "firewalldlg.h"
#include "logindlg.h"
#include "logsdlg.h"
#include "networkdlg.h"
#include "servicesdlg.h"
#include "settingdlg.h"
#include "statusdlg.h"
#include "systemdlg.h"
#include "centicfirewallruntime.h"


#define BACKLOG			(100)	// max request backlog
#define MAX_FILE_SIZE	(10000)	// max file size when buffering file for HTTP 1.0 and file size cannot be determined

////////////////////////////////////////////////////////////////////////////////
//
//	Forward decls
//
////////////////////////////////////////////////////////////////////////////////

static void *process_request(void*);
static int getdata(struct soap*, const char*, ns__Data&);
static void saveData(ns__Data&, const char*);
static void sigpipe_handle(int);

////////////////////////////////////////////////////////////////////////////////
//
//	Streaming DIME attachment content handlers
//
////////////////////////////////////////////////////////////////////////////////

static void *dime_read_open(struct soap*, void*, const char*, const char*, const char*);
static void dime_read_close(struct soap*, void*);
static size_t dime_read(struct soap*, void*, char*, size_t);
static void *dime_write_open(struct soap*, const char*, const char*, const char*);
static void dime_write_close(struct soap*, void*);
static int dime_write(struct soap*, void*, const char*, size_t);

////////////////////////////////////////////////////////////////////////////////
//
//	Data for streaming DIME write handler
//
////////////////////////////////////////////////////////////////////////////////

struct dime_write_handle
{ char *name;	// file name
	FILE *fd;	// file fd
};

////////////////////////////////////////////////////////////////////////////////
//
//	Static data
//
////////////////////////////////////////////////////////////////////////////////

static const char *TMPDIR = ".";



static LoginDlg m_loginDlg;
static CenticFirewallRuntime m_firewallRuntime;
static SettingDlg m_settingDlg;

static SystemDlg m_systemDlg;
static StatusDlg m_statusDlg;
static NetworkDlg m_networkDlg;
static ServicesDlg m_servicesDlg;
static FirewallDlg m_firewallDlg;
static LogsDlg m_logsDlg;

////////////////////////////////////////////////////////////////////////////////
//
//	Interrupt signal
//
////////////////////////////////////////////////////////////////////////////////
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
static bool is_main_running = true;
void signalhandler_func(int signo)
{
	if(signo != SIGINT){
		return;
	}
	FATAL("Ctrl + C \n");

	is_main_running = false;

	exit(1);
}


////////////////////////////////////////////////////////////////////////////////
//
//	Main
//
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{

	(void) signal(SIGINT, signalhandler_func);

#if 1
	struct soap soap;
	char *s = getenv("TMPDIR");
	if (s)
		TMPDIR = s;
	// use HTTP chunking when possible
	// chunking allows streaming of DIME content without requiring DIME attachment size to be set
	// DIME attachments can be streamed without chunking only if the attachment size is set
	soap_init1(&soap, SOAP_IO_KEEPALIVE | SOAP_IO_CHUNK);
	// set DIME callbacks
	soap.fdimereadopen = dime_read_open;
	soap.fdimereadclose = dime_read_close;
	soap.fdimeread = dime_read;
	soap.fdimewriteopen = dime_write_open;
	soap.fdimewriteclose = dime_write_close;
	soap.fdimewrite = dime_write;


#ifdef _POSIX_THREADS
	pthread_t tid;
#endif
	struct soap *tsoap;
	int port = 8085;
	int m, sk, i;


	if (soap_ssl_server_context(&soap,
								SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK,	/* use SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION to verify clients: client must provide a key file e.g. "client.pem" and "password" */
								"server.pem",	/* keyfile (cert+key): see README.txt to create this file */
								"password",		/* password to read the private key in the key file */
								"cacert.pem",	/* cacert file to store trusted certificates (to authenticate clients), see README.txt */
								NULL,		/* capath */
								"dh2048.pem",	/* DH file name or DH param key len bits in string (e.g. "2048"), if NULL then RSA with 2048 bits is used instead (bits defined by SOAP_SSL_RSA_BITS) */
								NULL,		/* if randfile!=NULL: use a file with random data to seed randomness */
								"sslserver"		/* server identification for SSL session cache (unique server name, e.g. use argv[0]) */
								))
	{
		soap_print_fault(&soap, stderr);
		exit(1);
	}



	// Unix SIGPIPE, this is OS dependent:
	// soap.accept_flags = SO_NOSIGPIPE;	// some systems like this
	// soap.socket_flags = MSG_NOSIGNAL;	// others need this
	// signal(SIGPIPE, sigpipe_handle);		// or a sigpipe handler (portable)

	// port is first command line argument
	//port = atoi(argv[1]);
	// bind to current host and specified port
	m = soap_bind(&soap, NULL, port, BACKLOG);
	// if we could not bind, exit
	if (m < 0)
	{ soap_print_fault(&soap, stderr);
		exit(1);
	}

	fprintf(stderr, "Socket connection successful %d, port %d \n", m, port);
	// die after 24 hrs waiting for activity on port
	soap.accept_timeout = 24*60*60;
	// IO timeouts
	soap.send_timeout = 30;
	soap.recv_timeout = 30;
	// loop through requests
	//for (i = 1; ; i++)
	while(is_main_running)
	{ // accept request
		sk = soap_accept(&soap);
		// if timeout or error, report
		if (sk < 0)
		{ if (soap.errnum)
				soap_print_fault(&soap, stderr);
			else
				fprintf(stderr, "Server timed out\n");
			break;
		}

		fprintf(stderr, "Thread %d accepts socket %d connection from IP %d.%d.%d.%d\n", i, s, (int)(soap.ip>>24)&0xFF, (int)(soap.ip>>16)&0xFF, (int)(soap.ip>>8)&0xFF, (int)soap.ip&0xFF);
		// copy soap environment and spawn thread (if Pthreads is installed)
		tsoap = soap_copy(&soap);
#ifdef _POSIX_THREADS
		pthread_create(&tid, NULL, (void*(*)(void*))process_request, (void*)tsoap);
#else
		process_request((void*)tsoap);
#endif
	}

	// detach
	soap_done(&soap);

#endif

	return 0;
}


void *process_request(void *soap)
{


#ifdef _POSIX_THREADS
	pthread_detach(pthread_self());
#endif
	soap_ssl_accept((struct soap*)soap);

	// serve request (or multiple requests with keep-alive enabled)
	soap_serve((struct soap*)soap);
	// cleanup class instances
	soap_destroy((struct soap*)soap);
	// cleanup
	soap_end((struct soap*)soap);
	// detach and free thread's copy of soap environment
	soap_free((struct soap*)soap);
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////
//
//	Server methods
//
////////////////////////////////////////////////////////////////////////////////
int ns__putData(struct soap *soap, std::vector<std::string> *nameList, arrayOfData *data, arrayOfName *names)
{
	DBG("\n");

	// gSOAP switches to SOAP_IO_STORE when SOAP_IO_CHUNK (HTTP chunking) is not supported by the client
	// Since it is undesirable to use SOAP_IO_STORE with streaming, we reset it to SOAP_IO_BUFFER
	if ((soap->omode & SOAP_IO) == SOAP_IO_STORE)
		soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_BUFFER;
	// return name (key) for each data item
	names->resize(data->size());


	//	for(int j = 0; j < nameList->size(); j++){
	//		DBG("file name server: %s\n", nameList->at(j).c_str());
	//	}

	for (int i = 0; i < data->size(); i++)
	{
		char *s, *name;
		// the id field is set when DIME was used so the dime_write callbacks already saved the file
		if ((*data)[i].id)
		{
			assert((*data)[i].__ptr);
			name = ((struct dime_write_handle*)(*data)[i].__ptr)->name;


		}
		else
		{
			name = tempnam(TMPDIR, "data");

			saveData((*data)[i], name);
		}
		s = strrchr(name, '/');
		if (!s)
			s = strrchr(name, '\\');
		if (!s)
			s = name;
		else
			s++;
		(*names)[i] = soap_strdup(soap, s);
		if (!(*data)[i].id)
		{ // free data alloced with tempnam()
			free(name);
		}
	}
	return SOAP_OK;
}

int ns__getData(struct soap *soap, arrayOfName *names, arrayOfData *data)
{

	DBG("\n");
	// gSOAP switches to SOAP_IO_STORE when SOAP_IO_CHUNK (HTTP chunking) is not supported by the client.
	// Since it is undesirable to use SOAP_IO_STORE, we reset it to SOAP_IO_BUFFER
	if ((soap->omode & SOAP_IO) == SOAP_IO_STORE)
		soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_BUFFER;
	if (!names)
		return soap_sender_fault(soap, "Names required", NULL);
	data->resize(names->size());
	for (int i = 0; i < names->__size; i++)
	{ if (!(*names)[i])
			return soap_sender_fault(soap, "Name required", NULL);
		if (getdata(soap, (*names)[i], (*data)[i]))
			return soap_sender_fault(soap, "Access denied", NULL);
	}
	return SOAP_OK;
}

int ns__getImage(struct soap *soap, char *name, ns__Data& image)
{

	if (!name)
		return soap_sender_fault(soap, "Name required", NULL);
	if (getdata(soap, name, image))
		return soap_sender_fault(soap, "Access denied", NULL);
	image.type = (char*)"image/jpeg";
	image.options = soap_dime_option(soap, 0, name);
	return SOAP_OK;
}


////////////////////////////////////////////////////////////////////////////////
//
//	Helper functions
//
////////////////////////////////////////////////////////////////////////////////

static int getdata(struct soap *soap, const char *name, ns__Data& data)
{

	struct stat sb;
	FILE *fd = NULL;
	if (name && !strchr(name, '/') && !strchr(name, '\\') && !strchr(name, ':'))
	{ char *s = (char*)soap_malloc(soap, strlen(TMPDIR) + strlen(name) + 2);
		strcpy(s, TMPDIR);
		strcat(s, "/");
		strcat(s, name);
		fd = fopen(s, "rb");
		if (!fd)
		{ strcpy(s, name);
			fd = fopen(s, "rb");
		}
	}
	if (!fd)
		return SOAP_EOF;
	if ((soap->omode & SOAP_IO) == SOAP_IO_CHUNK) // chunked response is possible
	{ data.__ptr = (unsigned char*)fd; // must set to non-NULL (this is our fd handle which we need in the callbacks)
		data.__size = 0; // zero size streams data with HTTP chunking
	}
	else if (!fstat(fileno(fd), &sb) && sb.st_size > 0)
	{ // since we can get the length of the file, we can stream it
		data.__ptr = (unsigned char*)fd; // must set to non-NULL (this is our fd handle which we need in the callbacks)
		data.__size = sb.st_size;
	}
	else // we can't use HTTP chunking and we don't know the size, so buffer it
	{ int i;
		data.__ptr = (unsigned char*)soap_malloc(soap, MAX_FILE_SIZE);
		for (i = 0; i < MAX_FILE_SIZE; i++)
		{ int c;
			if ((c = fgetc(fd)) == EOF)
				break;
			data.__ptr[i] = c;
		}
		fclose(fd);
		data.__size = i;
	}
	data.type = (char*)""; // specify non-NULL id or type to enable DIME
	data.options = soap_dime_option(soap, 0, name);
	return SOAP_OK;
}

static void saveData(ns__Data& data, const char *name)
{

	char *buf = (char*)data.__ptr;
	int len = data.__size;
	FILE *fd = fopen(name, "wb");
	if (!fd)
	{
		fprintf(stderr, "Cannot save file %s\n", name);
		return;
	}
	while (len)
	{
		size_t nwritten = fwrite(buf, 1, len, fd);
		if (!nwritten)
		{
			fprintf(stderr, "Cannot write to %s\n", name);
			return;
		}
		len -= nwritten;
		buf += nwritten;
	}
}

static void sigpipe_handle(int x) { }

////////////////////////////////////////////////////////////////////////////////
//
//	Streaming DIME attachment content handlers
//
////////////////////////////////////////////////////////////////////////////////

static void *dime_read_open(struct soap *soap, void *handle, const char *id, const char *type, const char *options)
{
	DBG("\n");
	// we should return NULL without setting soap->error if we don't want to use the streaming callback for this DIME attachment. The handle contains the non-NULL __ptr field value which should have been set in the application.
	// return value of this function will be passed on to the fdimeread and fdimereadclose callbacks. The return value will not affect the __ptr field.
	return handle;
}

static void dime_read_close(struct soap *soap, void *handle)
{
	DBG("\n");
	fclose((FILE*)handle);
}

static size_t dime_read(struct soap *soap, void *handle, char *buf, size_t len)
{

	return fread(buf, 1, len, (FILE*)handle);
}

static ns__SysBackupEvent bkev = EVENT_NONE;
static void *dime_write_open(struct soap *soap, const char *id, const char *type, const char *options)
{
	DBG("\n");
	// we can return NULL without setting soap->error if we don't want to use the streaming callback for this DIME attachment
	struct dime_write_handle *handle = (struct dime_write_handle*)soap_malloc(soap, sizeof(struct dime_write_handle));
	if (!handle)
	{
		soap->error = SOAP_EOM;
		return NULL;
	}


#if 0
	char *name = tempnam(TMPDIR, "data");
	fprintf(stderr, "Saving file %s\n", name);
	handle->name = soap_strdup(soap, name);
	free(name);
#else
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	char name[64];
	memset(name, '\0', sizeof(name));

	switch(bkev){
	case EVENT_SET_FILENAME_CONFIG:
		sprintf(name, "configuration-%d-%d-%d-%d-%d-%d.conf",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour,	tm.tm_min, tm.tm_sec);
		break;
	case EVENT_SET_FILENAME_FIRMWARE:
		sprintf(name, "firmware-%d-%d-%d-%d-%d-%d.ctfw",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour,	tm.tm_min, tm.tm_sec);
		break;
	default:
		sprintf(name, "%d-%d-%d-%d-%d-%d",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour,	tm.tm_min, tm.tm_sec);
		break;
	}

	DBG("tmpname: %s\n", name);

	handle->name = soap_strdup(soap, name);
#endif


	handle->fd = fopen(handle->name, "wb");
	if (!handle->fd)
	{
		soap->error = SOAP_EOF; // could not open file for writing
		soap->errnum = errno; // get reason
		return NULL;
	}
	return (void*)handle;
}

static void dime_write_close(struct soap *soap, void *handle)
{
	DBG("\n");
	fclose(((struct dime_write_handle*)handle)->fd);
}

static int dime_write(struct soap *soap, void *handle, const char *buf, size_t len)
{

	while (len)
	{
		size_t nwritten = fwrite(buf, 1, len, ((struct dime_write_handle*)handle)->fd);
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
{ 
	__ptr = NULL;
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
int ns__login(struct soap *soap, char *username, char *passwd, bool *ret)
{

	DBG("username: %s, passwd: %s\n", username, passwd);

	*ret = true;

	return SOAP_OK;
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
int ns__getRuntimeInfo(struct soap *soap, void *, RuntimeInfo_t *ret)
{
	DBG("\n");

	//for test
	ret->inSpeed = 425;
	ret->outSpeed = 100;
	ret->isConnected = true;

	return SOAP_OK;
}




//==============================================================================
// system
//==============================================================================
// System::Home
// Get list of interface
int ns__getSysHomeInterface(struct soap *soap, void *, NetInterface_t *ret){


	DBG("\n");

	ret->dns = "8.8.8.8";
	ret->gw =  "10.49.46.1";

#if 0
	IfInfot_t *netIf;
	netIf = new IfInfot_t;
	netIf->ifname = strdup("red");
	netIf->ip  = strdup("10.49.46.200");
	netIf->netmask  = strdup("255.255.255.0");
	netIf->mac  = strdup("c8:1f:66:0e:8c:0c");
	netIf->mtu  = 65000;

	ret->netIfList.push_back(*netIf);

	IfInfot_t *lanIf;
	lanIf = new IfInfot_t;
	lanIf->ifname = strdup("green0");
	lanIf->ip  = strdup("192.168.1.2");
	lanIf->netmask  = strdup("255.255.255.0");
	lanIf->mac  = strdup("0e:8c:0c:c8:1f:66");
	lanIf->mtu  = 65000;

	ret->lanIfList.push_back(*lanIf);
#else
	IfInfot_t netIf;
	netIf.ifname = "red";
	netIf.ip  = "10.49.46.200";
	netIf.netmask  = "255.255.255.0";
	netIf.mac  = "c8:1f:66:0e:8c:0c";
	netIf.mtu  = 65000;
	ret->netIfList.push_back(netIf);

	IfInfot_t lanIf;
	lanIf.ifname = "green0";
	lanIf.ip  = "192.168.1.1";
	lanIf.netmask  = "255.255.255.0";
	lanIf.mac  = "0e:8c:0c:c8:1f:66";
	lanIf.mtu  = 65000;
	ret->lanIfList.push_back(lanIf);

	IfInfot_t lanIf2;
	lanIf2.ifname = "green1";
	lanIf2.ip  = "192.168.1.2";
	lanIf2.netmask  = "255.255.255.0";
	lanIf2.mac  = "0e:8c:0c:c8:1f:67";
	lanIf2.mtu  = 65000;
	ret->lanIfList.push_back(lanIf2);

#endif


	return SOAP_OK;
}



// System::Backup
// Backup and restore configuration & firmware
int ns__SysBackupHandle(struct soap *soap, enum ns__SysBackupEvent in, char *path, SysBackupRet_t *ret)
{
	bkev = in;
	switch (in) {
	//set file name: save new file name to setting database
	case EVENT_SET_FILENAME_CONFIG:

		break;
	case EVENT_SET_FILENAME_FIRMWARE:

		break;

		//get file name: current file name saved in setting database
	case EVENT_GET_FILENAME_CONFIG:
		ret->filename = "configuration-2015-10-26-14-59-40.conf";
		break;
	case EVENT_GET_FILENAME_FIRMWARE:
		ret->filename = "firmware-2015-10-26-15-34-5.ctfw";
		break;

		//configuration handle
	case EVENT_BACKUP_CONFIGURATION:

		break;
	case EVENT_UPDATE_CONFIGURATION:

		break;

		//firmware handle
	case EVENT_BACKUP_FIRMWARE:

		break;
	case EVENT_UPDATE_FIRMWARE:

		break;
	default:
		break;
	}

	DBG("path<%d>: %s \n", in, path);

	return SOAP_OK;
}


// System::SystemInformation
// Get system information
int ns__getSysSysInfo(struct soap *soap, void *, SysInfo_t *ret)
{
	DBG("\n");
	ret->ctfw_version = "1.0.0";
	ret->cpu = "ARM";
	ret->memory = "DDR3 1GB";

	return SOAP_OK;
}



// System::Shutdown
// Logout, reboot, shutdown
int ns__SysShutdownHandle(struct soap *soap, enum ns__SysShutdownEvent in, struct ns__noResponse *out)
{
	DBG(" %d \n", in);
	switch (in) {
	case EVENT_SHUTDOWN:

		break;
	case EVENT_REBOOT:

		break;
	case EVENT_LOGOUT:

		break;
	default:
		break;
	}

	return SOAP_OK;
}




//==============================================================================
// status
//==============================================================================
// Status::system
// get CPU and Memory percent list
int ns__getStatusSystemGraph(struct soap *soap, enum SysGraphMode_t mode, SystemData_t *ret)
{
	DBG("\n");
	int i,randnum, loop;

	switch (mode) {
	case GRAPH_MODE_HOUR:
		loop = NUMS_POINT_HOUR;
		break;
	case GRAPH_MODE_DAY:
		loop = NUMS_POINT_DAY;
		break;
	case GRAPH_MODE_WEEK:
		loop = NUMS_POINT_WEEK;
		break;
	case GRAPH_MODE_MONTH:
		loop = NUMS_POINT_MONTH;
		break;
	case GRAPH_MODE_YEAR:
		loop = NUMS_POINT_YEAR;
		break;
	default:
		break;
	}


	GraphData_t cpu, memory;

	for(i = 0; i < loop; i++){
		randnum = rand() % 100 + 1;
		cpu.grapData.push_back(randnum);

		randnum = rand() % 100 + 1;
		memory.grapData.push_back(randnum);
	}

	ret->cpuData.push_back(cpu);
	ret->memoryData.push_back(memory);


	DBG("ret->cpuData size %d\n", ret->cpuData.size());
	DBG("ret->memoryData size %d\n", ret->memoryData.size());
	DBG("cpu size %d\n", cpu.grapData.size());
	DBG("memory size %d\n", memory.grapData.size());

	return SOAP_OK;
}

// Status::Services
// Get services running status
int ns__getStatusServices(struct soap *soap, void *, StatusServicesList_t *ret)
{
	DBG("\n");

	int i,randnum;

	for(i = 0; i < 10; i++){
		StatusServices_t sv;
		randnum = rand() % 100 + 1;
		if(randnum %2 == 0){
			sv.isRunning = true;
		}else{
			sv.isRunning = false;
		}

		sv.name = "my sv";
		sv.pid = i;
		sv.memory = i*10;

		ret->push_back(sv);
	}




	return SOAP_OK;
}


int ns__getStatusNetworkExternal(struct soap *soap, enum SysGraphMode_t mode, NetworkData_t *ret)
{
	DBG("\n");
	int i,randnum, loop;

	switch (mode) {
	case GRAPH_MODE_HOUR:
		loop = NUMS_POINT_HOUR;
		break;
	case GRAPH_MODE_DAY:
		loop = NUMS_POINT_DAY;
		break;
	case GRAPH_MODE_WEEK:
		loop = NUMS_POINT_WEEK;
		break;
	case GRAPH_MODE_MONTH:
		loop = NUMS_POINT_MONTH;
		break;
	case GRAPH_MODE_YEAR:
		loop = NUMS_POINT_YEAR;
		break;
	default:
		break;
	}


	GraphData_t in, out;
	for(i = 0; i < loop; i++){
		randnum = rand() % 100 + 1;
		in.grapData.push_back(randnum);

		randnum = rand() % 100 + 1;
		out.grapData.push_back(randnum);
	}


	ret->graphListData.push_back(in);
	ret->graphListData.push_back(out);

	NetTraffic_t inTra, outTra;
	inTra.max = 123;
	inTra.avg = 50;
	inTra.min = 10;
	inTra.current = 100;

	outTra.max = 321;
	outTra.avg = 90;
	outTra.min = 50;
	outTra.current = 110;

	ret->netListTraffic.push_back(inTra);
	ret->netListTraffic.push_back(outTra);

//	DBG("ret->graphListData size %d\n", ret->graphListData.size());
//	DBG("ret->netListTraffic size %d\n", ret->netListTraffic.size());
//	DBG("in size %d\n", in.grapData.size());
//	DBG("out size %d\n", out.grapData.size());
	return SOAP_OK;
}

int ns__getStatusNetworkInternal(struct soap *soap, enum SysGraphMode_t mode, NetworkData_t *ret)
{
	DBG("\n");
	int i,randnum, loop;

	switch (mode) {
	case GRAPH_MODE_HOUR:
		loop = NUMS_POINT_HOUR;
		break;
	case GRAPH_MODE_DAY:
		loop = NUMS_POINT_DAY;
		break;
	case GRAPH_MODE_WEEK:
		loop = NUMS_POINT_WEEK;
		break;
	case GRAPH_MODE_MONTH:
		loop = NUMS_POINT_MONTH;
		break;
	case GRAPH_MODE_YEAR:
		loop = NUMS_POINT_YEAR;
		break;
	default:
		break;
	}


	GraphData_t in, out;
	for(i = 0; i < loop; i++){
		randnum = rand() % 100 + 1;
		in.grapData.push_back(randnum);

		randnum = rand() % 100 + 1;
		out.grapData.push_back(randnum);
	}


	ret->graphListData.push_back(in);
	ret->graphListData.push_back(out);

	NetTraffic_t inTra, outTra;
	inTra.max = 123;
	inTra.avg = 50;
	inTra.min = 10;
	inTra.current = 100;

	outTra.max = 321;
	outTra.avg = 90;
	outTra.min = 50;
	outTra.current = 110;

	ret->netListTraffic.push_back(inTra);
	ret->netListTraffic.push_back(outTra);

//	DBG("ret->graphListData size %d\n", ret->graphListData.size());
//	DBG("ret->netListTraffic size %d\n", ret->netListTraffic.size());
//	DBG("in size %d\n", in.grapData.size());
//	DBG("out size %d\n", out.grapData.size());

	return SOAP_OK;
}

int ns__getStatusNetworkOther(struct soap *soap, enum SysGraphMode_t mode, NetworkData_t *ret)
{
	DBG("\n");
	int i,randnum, loop;

	switch (mode) {
	case GRAPH_MODE_HOUR:
		loop = NUMS_POINT_HOUR;
		break;
	case GRAPH_MODE_DAY:
		loop = NUMS_POINT_DAY;
		break;
	case GRAPH_MODE_WEEK:
		loop = NUMS_POINT_WEEK;
		break;
	case GRAPH_MODE_MONTH:
		loop = NUMS_POINT_MONTH;
		break;
	case GRAPH_MODE_YEAR:
		loop = NUMS_POINT_YEAR;
		break;
	default:
		break;
	}


	GraphData_t in, out, fw;
	for(i = 0; i < loop; i++){
		randnum = rand() % 100 + 1;
		in.grapData.push_back(randnum);

		randnum = rand() % 100 + 1;
		out.grapData.push_back(randnum);

		randnum = rand() % 100 + 1;
		fw.grapData.push_back(randnum);
	}


	ret->graphListData.push_back(in);
	ret->graphListData.push_back(fw);
	ret->graphListData.push_back(out);

	NetTraffic_t inTra, outTra, forwardTra;
	inTra.max = 123;
	inTra.avg = 50;
	inTra.min = 10;
	inTra.current = 100;

	forwardTra.max = 321;
	forwardTra.avg = 90;
	forwardTra.min = 50;
	forwardTra.current = 110;

	outTra.max = 321;
	outTra.avg = 90;
	outTra.min = 50;
	outTra.current = 110;

	ret->netListTraffic.push_back(inTra);
	ret->netListTraffic.push_back(forwardTra);
	ret->netListTraffic.push_back(outTra);

//	DBG("ret->graphListData size %d\n", ret->graphListData.size());
//	DBG("ret->netListTraffic size %d\n", ret->netListTraffic.size());
//	DBG("in size %d\n", in.grapData.size());
//	DBG("out size %d\n", out.grapData.size());

	return SOAP_OK;
}


int ns__getStatusConnection(struct soap *soap, void *, StatusConnList_t *ret)
{
	DBG("\n");

	int i, randnum;
	for(i = 0; i < 10; i++){
		ConnTrack_t conn;
		randnum = rand() % 100 + 1;
		if(randnum % 2 == 0){
			conn.protocol = 6;//tcp
			conn.sip = "10.49.46.12";
			conn.sport = 123;
			conn.dip = "10.49.46.13";
			conn.dport = 123;
			conn.downSpeed = 123;
			conn.upSpeed = 90;
			conn.connStatus = 1;
			conn.expires = 120;
			conn.slegend = 0;
			conn.dlegend = 1;


		}else{
			conn.protocol = 17;//udp
			conn.sip = "10.49.46.14";
			conn.sport = 123;
			conn.dip = "10.49.46.15";
			conn.dport = 123;
			conn.downSpeed = 123;
			conn.upSpeed = 90;
			conn.connStatus = 1;
			conn.slegend = 2;
			conn.dlegend = 3;

		}

		ret->push_back(conn);
	}

	return SOAP_OK;
}

//==============================================================================
// network
//==============================================================================


//==============================================================================
// services
//==============================================================================


//==============================================================================
// firewall
//==============================================================================


//==============================================================================
// logs
//==============================================================================



//==============================================================================
// settings
//==============================================================================

