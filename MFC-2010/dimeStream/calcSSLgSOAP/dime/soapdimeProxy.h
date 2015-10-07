/* soapdimeProxy.h
   Generated by gSOAP 2.8.23 from dime.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapdimeProxy_H
#define soapdimeProxy_H
#include "soapH.h"

class SOAP_CMAC dimeProxy : public soap
{ public:
	/// Endpoint URL of service 'dimeProxy' (change as needed)
	const char *soap_endpoint;
	/// Variables globally declared in dime.h (non-static)
	/// Constructor
	dimeProxy();
	/// Construct from another engine state
	dimeProxy(const struct soap&);
	/// Constructor with endpoint URL
	dimeProxy(const char *url);
	/// Constructor with engine input+output mode control
	dimeProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	dimeProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	dimeProxy(soap_mode imode, soap_mode omode);
	/// Destructor deletes deserialized data and engine context
	virtual	~dimeProxy();
	/// Initializer used by constructors
	virtual	void dimeProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to default
	virtual	void reset();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'putData' (returns error code or SOAP_OK)
	virtual	int putData(arrayOfData *data, arrayOfName *names) { return this->putData(NULL, NULL, data, names); }
	virtual	int putData(const char *endpoint, const char *soap_action, arrayOfData *data, arrayOfName *names);

	/// Web service operation 'getData' (returns error code or SOAP_OK)
	virtual	int getData(arrayOfName *names, arrayOfData *data) { return this->getData(NULL, NULL, names, data); }
	virtual	int getData(const char *endpoint, const char *soap_action, arrayOfName *names, arrayOfData *data);

	/// Web service operation 'getImage' (returns error code or SOAP_OK)
	virtual	int getImage(char *name, ns__Data &image) { return this->getImage(NULL, NULL, name, image); }
	virtual	int getImage(const char *endpoint, const char *soap_action, char *name, ns__Data &image);
};
#endif