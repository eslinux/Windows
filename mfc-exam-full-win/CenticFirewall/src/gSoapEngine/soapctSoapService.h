/* soapctSoapService.h
   Generated by gSOAP 2.8.23 from ctSoap.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapctSoapService_H
#define soapctSoapService_H
#include "soapH.h"
class SOAP_CMAC ctSoapService : public soap
{ public:
	/// Variables globally declared in ctSoap.h (non-static)
	/// Constructor
	ctSoapService();
	/// Construct from another engine state
	ctSoapService(const struct soap&);
	/// Constructor with engine input+output mode control
	ctSoapService(soap_mode iomode);
	/// Constructor with engine input and output mode control
	ctSoapService(soap_mode imode, soap_mode omode);
	/// Destructor deletes deserialized data and engine context
	virtual ~ctSoapService();
	/// Delete all deserialized data (with soap_destroy() and soap_end())
	virtual	void destroy();
	/// Delete all deserialized data and reset to defaults
	virtual	void reset();
	/// Initializer used by constructor
	virtual	void ctSoapService_init(soap_mode imode, soap_mode omode);
	/// Create a copy
	virtual	ctSoapService *copy() SOAP_PURE_VIRTUAL;
	/// Close connection (normally automatic)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Return sender-related fault to sender
	virtual	int soap_senderfault(const char *string, const char *detailXML);
	/// Return sender-related fault with SOAP 1.2 subcode to sender
	virtual	int soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML);
	/// Return receiver-related fault to sender
	virtual	int soap_receiverfault(const char *string, const char *detailXML);
	/// Return receiver-related fault with SOAP 1.2 subcode to sender
	virtual	int soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML);
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
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Run simple single-thread (iterative, non-SSL) service on port until a connection error occurs (returns error code or SOAP_OK), use this->bind_flag = SO_REUSEADDR to rebind for a rerun
	virtual	int run(int port);
	/// Bind service to port (returns master socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET bind(const char *host, int port, int backlog);
	/// Accept next request (returns socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET accept();
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
	/// Then accept SSL handshake, when SSL is used
	virtual	int ssl_accept();
#endif
	/// Serve this request (returns error code or SOAP_OK)
	virtual	int serve();
	/// Used by serve() to dispatch a request (returns error or SOAP_OK)
	virtual	int dispatch();

	///
	/// Service operations (you should define these):
	/// Note: compile with -DWITH_PURE_VIRTUAL for pure virtual methods
	///

	/// Web service operation 'putData' (returns error code or SOAP_OK)
	virtual	int putData(arrayOfData *data, arrayOfName *names) SOAP_PURE_VIRTUAL;

	/// Web service operation 'getData' (returns error code or SOAP_OK)
	virtual	int getData(arrayOfName *names, arrayOfData *data) SOAP_PURE_VIRTUAL;

	/// Web service operation 'getImage' (returns error code or SOAP_OK)
	virtual	int getImage(char *name, ns__Data &image) SOAP_PURE_VIRTUAL;

	/// Web service operation 'login' (returns error code or SOAP_OK)
	virtual	int login(char *username, char *passwd, bool *ret) SOAP_PURE_VIRTUAL;

	/// Web service operation 'getRuntimeInfo' (returns error code or SOAP_OK)
	virtual	int getRuntimeInfo(void *_param_10, struct _Struct_9 *ret) SOAP_PURE_VIRTUAL;
};
#endif
