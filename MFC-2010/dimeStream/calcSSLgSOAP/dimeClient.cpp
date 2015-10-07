#include "StdAfx.h"
#include "dimeClient.h"

#include "dime/soapH.h"
#include "dime/dime.nsmap"
#include <assert.h>
#include "stdio.h"


// use the default endpoint set in dime.h for demo:
const char *endpoint = "https://10.49.46.199:8085";
// use the localhost for -p and -g (put and get):
const char *localhost = "https://10.49.46.199:8085";

static struct soap dime;

////////////////////////////////////////////////////////////////////////////////
//
//	Forward decls
//
////////////////////////////////////////////////////////////////////////////////

static void putData(struct soap*, int, char**);
static void getData(struct soap*, int, char**);
static void getImage(struct soap*, char*);
static void saveData(ns__Data&, const char*);

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




dimeClient::dimeClient(void)
{
	soap_init1(&dime, SOAP_IO_CHUNK);
	// set DIME callbacks
	dime.fdimereadopen = dime_read_open;
	dime.fdimereadclose = dime_read_close;
	dime.fdimeread = dime_read;
	dime.fdimewriteopen = dime_write_open;
	dime.fdimewriteclose = dime_write_close;
	dime.fdimewrite = dime_write;
	// connect timeout value (not supported by Linux)
	dime.connect_timeout = 10;
	// IO timeouts
	dime.send_timeout = 30;
	dime.recv_timeout = 30;


	soap_ssl_init();

	if (soap_ssl_client_context(&dime,
								//SOAP_SSL_DEFAULT,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								NULL, 		/* keyfile: required only when client must authenticate to server (see SSL docs on how to obtain this file) */
								NULL, 		/* password to read the keyfile */
								"cacert.pem",	/* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
								NULL,		/* optional capath to directory with trusted certificates */
								NULL		/* if randfile!=NULL: use a file with random data to seed randomness */
								))
	{
		TRACE(traceAppMsg, 0, "soap_ssl_client_context FAIL \n");
		soap_print_fault(&dime, stderr);		
		return ;
	}

	
}


dimeClient::~dimeClient(void)
{
	// detach
	soap_done(&dime);
}


void dimeClient::dimePush(void)
{
	//static void putData(dimeProxy *soap, int, char**);
	char *fileName[] = {{"push"}, {"-p"}, {"myfile.png"}};

	putData(&dime, 3, fileName);
	
}


void dimeClient::dimeGet(void)
{
	//static void getData(dimeProxy *soap, int, char**);
	char *fileName[] = {{"push"}, {"-p"}, {"datayuRbpJ"}};

	getData(&dime, 3, fileName);
}



////////////////////////////////////////////////////////////////////////////////
//
//	Helper functions
//
////////////////////////////////////////////////////////////////////////////////

static void putData(struct soap *soap, int argc, char **argv)
{
	arrayOfData data;
	arrayOfName names;
	data.resize(argc - 2);
	for (int i = 2; i < argc; i++)
	{ data[i - 2].__ptr = (unsigned char*)argv[i];
		// MUST set id or type to enable DIME
		// zero size indicates streaming DIME (this requires HTTP chunking)
		data[i - 2].type = (char*)"";
	}
	if (soap_call_ns__putData(soap, endpoint, NULL, &data, &names))
		soap_print_fault(soap, stderr);
	else
	{
		printf("Data stored with keys:\n");
		for (int j = 0; j < names.size(); j++)
			printf("\t%s\n", names[j]);
		printf("Use these keys to retrieve the data\n");
	}
}

static void getData(struct soap *soap, int argc, char **argv)
{ arrayOfData data;
	arrayOfName names;
	names.resize(argc - 2);
	for (int i = 2; i < argc; i++)
		names[i - 2] = argv[i];
	soap->user = (void*)names.__ptr;
	if (soap_call_ns__getData(soap, endpoint, NULL, &names, &data))
		soap_print_fault(soap, stderr);
	else
	{ for (int j = 0; j < data.size(); j++)
			if (!data[j].id)
				saveData(data[j], argv[j + 2]);
		printf("Data retrieved\n");
	}
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

static void saveData(ns__Data& data, const char *name)
{
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
	char *name;
	// get file name from options (not '\0' terminated)
	if (options)
	{ size_t len = ((unsigned char)options[2] << 8) | ((unsigned char)options[3]); // option string length
		name = (char*)soap_malloc(soap, len + 1);
		strncpy(name, options + 4, len);
		name[len] = '\0';
		handle = fopen(name, "wb");
		if (!handle)
		{ soap->error = SOAP_EOF; // could not open file for writing
			soap->errnum = errno; // get reason
			return NULL;
		}
	}
	else
		soap->error = soap_receiver_fault(soap, "Cannot save to file, because no file name was present in attachment", NULL);
	return (void*)handle;
}

static void dime_write_close(struct soap *soap, void *handle)
{ fclose((FILE*)handle);
}

static int dime_write(struct soap *soap, void *handle, const char *buf, size_t len)
{ while (len)
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



float dimeClient::dimeAdd(float a, float b)
{


	float result;

	if (soap_call_ns__add(&dime, endpoint, NULL, a, b, &result))
		soap_print_fault(&dime, stderr);
	else
	{
		return result;
	}

	return 0;
}
