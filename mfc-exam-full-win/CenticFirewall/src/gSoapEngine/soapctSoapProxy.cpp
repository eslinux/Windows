/* soapctSoapProxy.cpp
   Generated by gSOAP 2.8.23 from ctSoap.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapctSoapProxy.h"

ctSoapProxy::ctSoapProxy() : soap(SOAP_IO_DEFAULT)
{	ctSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ctSoapProxy::ctSoapProxy(const struct soap &_soap) : soap(_soap)
{ }

ctSoapProxy::ctSoapProxy(const char *url) : soap(SOAP_IO_DEFAULT)
{	ctSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

ctSoapProxy::ctSoapProxy(soap_mode iomode) : soap(iomode)
{	ctSoapProxy_init(iomode, iomode);
}

ctSoapProxy::ctSoapProxy(const char *url, soap_mode iomode) : soap(iomode)
{	ctSoapProxy_init(iomode, iomode);
	soap_endpoint = url;
}

ctSoapProxy::ctSoapProxy(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	ctSoapProxy_init(imode, omode);
}

ctSoapProxy::~ctSoapProxy()
{
	this->destroy();
	}

void ctSoapProxy::ctSoapProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:ctSoap", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void ctSoapProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void ctSoapProxy::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	ctSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void ctSoapProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *ctSoapProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *ctSoapProxy::soap_fault()
{	return this->fault;
}

const char *ctSoapProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *ctSoapProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int ctSoapProxy::soap_close_socket()
{	return soap_closesock(this);
}

int ctSoapProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void ctSoapProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void ctSoapProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *ctSoapProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int ctSoapProxy::putData(const char *endpoint, const char *soap_action, arrayOfData *data, arrayOfName *names)
{	struct soap *soap = this;
	struct ns__putData soap_tmp_ns__putData;
	struct ns__putDataResponse *soap_tmp_ns__putDataResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__putData.data = data;
	soap_serializeheader(soap);
	soap_serialize_ns__putData(soap, &soap_tmp_ns__putData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__putData(soap, &soap_tmp_ns__putData, "ns:putData", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__putData(soap, &soap_tmp_ns__putData, "ns:putData", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!names)
		return soap_closesock(soap);
	names->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__putDataResponse = soap_get_ns__putDataResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__putDataResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (names && soap_tmp_ns__putDataResponse->names)
		*names = *soap_tmp_ns__putDataResponse->names;
	return soap_closesock(soap);
}

int ctSoapProxy::getData(const char *endpoint, const char *soap_action, arrayOfName *names, arrayOfData *data)
{	struct soap *soap = this;
	struct ns__getData soap_tmp_ns__getData;
	struct ns__getDataResponse *soap_tmp_ns__getDataResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getData.names = names;
	soap_serializeheader(soap);
	soap_serialize_ns__getData(soap, &soap_tmp_ns__getData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getData(soap, &soap_tmp_ns__getData, "ns:getData", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getData(soap, &soap_tmp_ns__getData, "ns:getData", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!data)
		return soap_closesock(soap);
	data->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getDataResponse = soap_get_ns__getDataResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getDataResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (data && soap_tmp_ns__getDataResponse->data)
		*data = *soap_tmp_ns__getDataResponse->data;
	return soap_closesock(soap);
}

int ctSoapProxy::getImage(const char *endpoint, const char *soap_action, char *name, ns__Data &image)
{	struct soap *soap = this;
	struct ns__getImage soap_tmp_ns__getImage;
	struct ns__getImageResponse *soap_tmp_ns__getImageResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getImage.name = name;
	soap_serializeheader(soap);
	soap_serialize_ns__getImage(soap, &soap_tmp_ns__getImage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getImage(soap, &soap_tmp_ns__getImage, "ns:getImage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getImage(soap, &soap_tmp_ns__getImage, "ns:getImage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&image)
		return soap_closesock(soap);
	image.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getImageResponse = soap_get_ns__getImageResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getImageResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	image = soap_tmp_ns__getImageResponse->image;
	return soap_closesock(soap);
}

int ctSoapProxy::login(const char *endpoint, const char *soap_action, char *username, char *passwd, bool *ret)
{	struct soap *soap = this;
	struct ns__login soap_tmp_ns__login;
	struct ns__loginResponse *soap_tmp_ns__loginResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__login.username = username;
	soap_tmp_ns__login.passwd = passwd;
	soap_serializeheader(soap);
	soap_serialize_ns__login(soap, &soap_tmp_ns__login);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__login(soap, &soap_tmp_ns__login, "ns:login", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__login(soap, &soap_tmp_ns__login, "ns:login", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	soap_default_bool(soap, ret);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__loginResponse = soap_get_ns__loginResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__loginResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__loginResponse->ret)
		*ret = *soap_tmp_ns__loginResponse->ret;
	return soap_closesock(soap);
}

int ctSoapProxy::getRuntimeInfo(const char *endpoint, const char *soap_action, void *_param_10, struct _Struct_9 *ret)
{	struct soap *soap = this;
	struct ns__getRuntimeInfo soap_tmp_ns__getRuntimeInfo;
	struct ns__getRuntimeInfoResponse *soap_tmp_ns__getRuntimeInfoResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getRuntimeInfo._param_10 = _param_10;
	soap_serializeheader(soap);
	soap_serialize_ns__getRuntimeInfo(soap, &soap_tmp_ns__getRuntimeInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getRuntimeInfo(soap, &soap_tmp_ns__getRuntimeInfo, "ns:getRuntimeInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getRuntimeInfo(soap, &soap_tmp_ns__getRuntimeInfo, "ns:getRuntimeInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	soap_default_RuntimeInfo_t(soap, ret);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getRuntimeInfoResponse = soap_get_ns__getRuntimeInfoResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getRuntimeInfoResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getRuntimeInfoResponse->ret)
		*ret = *soap_tmp_ns__getRuntimeInfoResponse->ret;
	return soap_closesock(soap);
}
/* End of client proxy code */