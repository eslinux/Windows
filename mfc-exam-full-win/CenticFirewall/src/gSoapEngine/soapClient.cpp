/* soapClient.cpp
   Generated by gSOAP 2.8.23 from ctSoap.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "stdafx.h"
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.23 2015-10-29 07:26:57 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__putData(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<std::string >*nameList, arrayOfData *data, arrayOfName *names)
{	struct ns__putData soap_tmp_ns__putData;
	struct ns__putDataResponse *soap_tmp_ns__putDataResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__putData.nameList = nameList;
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getData(struct soap *soap, const char *soap_endpoint, const char *soap_action, arrayOfName *names, arrayOfData *data)
{	struct ns__getData soap_tmp_ns__getData;
	struct ns__getDataResponse *soap_tmp_ns__getDataResponse;
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getImage(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *name, ns__Data &image)
{	struct ns__getImage soap_tmp_ns__getImage;
	struct ns__getImageResponse *soap_tmp_ns__getImageResponse;
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__login(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *username, char *passwd, bool *ret)
{	struct ns__login soap_tmp_ns__login;
	struct ns__loginResponse *soap_tmp_ns__loginResponse;
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getRuntimeInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, void *_param_9, RuntimeInfo_t *ret)
{	struct ns__getRuntimeInfo soap_tmp_ns__getRuntimeInfo;
	struct ns__getRuntimeInfoResponse *soap_tmp_ns__getRuntimeInfoResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getRuntimeInfo._param_9 = _param_9;
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
	ret->soap_default(soap);
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getSysHomeInterface(struct soap *soap, const char *soap_endpoint, const char *soap_action, void *_param_10, NetInterface_t *ret)
{	struct ns__getSysHomeInterface soap_tmp_ns__getSysHomeInterface;
	struct ns__getSysHomeInterfaceResponse *soap_tmp_ns__getSysHomeInterfaceResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getSysHomeInterface._param_10 = _param_10;
	soap_serializeheader(soap);
	soap_serialize_ns__getSysHomeInterface(soap, &soap_tmp_ns__getSysHomeInterface);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getSysHomeInterface(soap, &soap_tmp_ns__getSysHomeInterface, "ns:getSysHomeInterface", NULL)
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
	 || soap_put_ns__getSysHomeInterface(soap, &soap_tmp_ns__getSysHomeInterface, "ns:getSysHomeInterface", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getSysHomeInterfaceResponse = soap_get_ns__getSysHomeInterfaceResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getSysHomeInterfaceResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getSysHomeInterfaceResponse->ret)
		*ret = *soap_tmp_ns__getSysHomeInterfaceResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__SysBackupHandle(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum ns__SysBackupEvent in, char *path, SysBackupRet_t *ret)
{	struct ns__SysBackupHandle soap_tmp_ns__SysBackupHandle;
	struct ns__SysBackupHandleResponse *soap_tmp_ns__SysBackupHandleResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__SysBackupHandle.in = in;
	soap_tmp_ns__SysBackupHandle.path = path;
	soap_serializeheader(soap);
	soap_serialize_ns__SysBackupHandle(soap, &soap_tmp_ns__SysBackupHandle);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__SysBackupHandle(soap, &soap_tmp_ns__SysBackupHandle, "ns:SysBackupHandle", NULL)
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
	 || soap_put_ns__SysBackupHandle(soap, &soap_tmp_ns__SysBackupHandle, "ns:SysBackupHandle", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__SysBackupHandleResponse = soap_get_ns__SysBackupHandleResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__SysBackupHandleResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__SysBackupHandleResponse->ret)
		*ret = *soap_tmp_ns__SysBackupHandleResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getSysSysInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, void *_param_11, SysInfo_t *ret)
{	struct ns__getSysSysInfo soap_tmp_ns__getSysSysInfo;
	struct ns__getSysSysInfoResponse *soap_tmp_ns__getSysSysInfoResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getSysSysInfo._param_11 = _param_11;
	soap_serializeheader(soap);
	soap_serialize_ns__getSysSysInfo(soap, &soap_tmp_ns__getSysSysInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getSysSysInfo(soap, &soap_tmp_ns__getSysSysInfo, "ns:getSysSysInfo", NULL)
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
	 || soap_put_ns__getSysSysInfo(soap, &soap_tmp_ns__getSysSysInfo, "ns:getSysSysInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getSysSysInfoResponse = soap_get_ns__getSysSysInfoResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getSysSysInfoResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getSysSysInfoResponse->ret)
		*ret = *soap_tmp_ns__getSysSysInfoResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__SysShutdownHandle(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum ns__SysShutdownEvent in, struct ns__noResponse *out)
{	struct ns__SysShutdownHandle soap_tmp_ns__SysShutdownHandle;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__SysShutdownHandle.in = in;
	soap_serializeheader(soap);
	soap_serialize_ns__SysShutdownHandle(soap, &soap_tmp_ns__SysShutdownHandle);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__SysShutdownHandle(soap, &soap_tmp_ns__SysShutdownHandle, "ns:SysShutdownHandle", NULL)
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
	 || soap_put_ns__SysShutdownHandle(soap, &soap_tmp_ns__SysShutdownHandle, "ns:SysShutdownHandle", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!out)
		return soap_closesock(soap);
	soap_default_ns__noResponse(soap, out);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns__noResponse(soap, out, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusSystemGraph(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum SysGraphMode_t mode, SystemData_t *ret)
{	struct ns__getStatusSystemGraph soap_tmp_ns__getStatusSystemGraph;
	struct ns__getStatusSystemGraphResponse *soap_tmp_ns__getStatusSystemGraphResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusSystemGraph.mode = mode;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusSystemGraph(soap, &soap_tmp_ns__getStatusSystemGraph);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusSystemGraph(soap, &soap_tmp_ns__getStatusSystemGraph, "ns:getStatusSystemGraph", NULL)
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
	 || soap_put_ns__getStatusSystemGraph(soap, &soap_tmp_ns__getStatusSystemGraph, "ns:getStatusSystemGraph", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusSystemGraphResponse = soap_get_ns__getStatusSystemGraphResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusSystemGraphResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusSystemGraphResponse->ret)
		*ret = *soap_tmp_ns__getStatusSystemGraphResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusNetworkExternal(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum SysGraphMode_t mode, NetworkData_t *ret)
{	struct ns__getStatusNetworkExternal soap_tmp_ns__getStatusNetworkExternal;
	struct ns__getStatusNetworkExternalResponse *soap_tmp_ns__getStatusNetworkExternalResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusNetworkExternal.mode = mode;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusNetworkExternal(soap, &soap_tmp_ns__getStatusNetworkExternal);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusNetworkExternal(soap, &soap_tmp_ns__getStatusNetworkExternal, "ns:getStatusNetworkExternal", NULL)
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
	 || soap_put_ns__getStatusNetworkExternal(soap, &soap_tmp_ns__getStatusNetworkExternal, "ns:getStatusNetworkExternal", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusNetworkExternalResponse = soap_get_ns__getStatusNetworkExternalResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusNetworkExternalResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusNetworkExternalResponse->ret)
		*ret = *soap_tmp_ns__getStatusNetworkExternalResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusNetworkInternal(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum SysGraphMode_t mode, NetworkData_t *ret)
{	struct ns__getStatusNetworkInternal soap_tmp_ns__getStatusNetworkInternal;
	struct ns__getStatusNetworkInternalResponse *soap_tmp_ns__getStatusNetworkInternalResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusNetworkInternal.mode = mode;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusNetworkInternal(soap, &soap_tmp_ns__getStatusNetworkInternal);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusNetworkInternal(soap, &soap_tmp_ns__getStatusNetworkInternal, "ns:getStatusNetworkInternal", NULL)
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
	 || soap_put_ns__getStatusNetworkInternal(soap, &soap_tmp_ns__getStatusNetworkInternal, "ns:getStatusNetworkInternal", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusNetworkInternalResponse = soap_get_ns__getStatusNetworkInternalResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusNetworkInternalResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusNetworkInternalResponse->ret)
		*ret = *soap_tmp_ns__getStatusNetworkInternalResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusNetworkOther(struct soap *soap, const char *soap_endpoint, const char *soap_action, enum SysGraphMode_t mode, NetworkData_t *ret)
{	struct ns__getStatusNetworkOther soap_tmp_ns__getStatusNetworkOther;
	struct ns__getStatusNetworkOtherResponse *soap_tmp_ns__getStatusNetworkOtherResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusNetworkOther.mode = mode;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusNetworkOther(soap, &soap_tmp_ns__getStatusNetworkOther);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusNetworkOther(soap, &soap_tmp_ns__getStatusNetworkOther, "ns:getStatusNetworkOther", NULL)
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
	 || soap_put_ns__getStatusNetworkOther(soap, &soap_tmp_ns__getStatusNetworkOther, "ns:getStatusNetworkOther", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	ret->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusNetworkOtherResponse = soap_get_ns__getStatusNetworkOtherResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusNetworkOtherResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusNetworkOtherResponse->ret)
		*ret = *soap_tmp_ns__getStatusNetworkOtherResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusServices(struct soap *soap, const char *soap_endpoint, const char *soap_action, void *_param_12, std::vector<StatusServices_t >*ret)
{	struct ns__getStatusServices soap_tmp_ns__getStatusServices;
	struct ns__getStatusServicesResponse *soap_tmp_ns__getStatusServicesResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusServices._param_12 = _param_12;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusServices(soap, &soap_tmp_ns__getStatusServices);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusServices(soap, &soap_tmp_ns__getStatusServices, "ns:getStatusServices", NULL)
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
	 || soap_put_ns__getStatusServices(soap, &soap_tmp_ns__getStatusServices, "ns:getStatusServices", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	soap_default_StatusServicesList_t(soap, ret);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusServicesResponse = soap_get_ns__getStatusServicesResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusServicesResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusServicesResponse->ret)
		*ret = *soap_tmp_ns__getStatusServicesResponse->ret;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getStatusConnection(struct soap *soap, const char *soap_endpoint, const char *soap_action, void *_param_13, std::vector<ConnTrack_t >*ret)
{	struct ns__getStatusConnection soap_tmp_ns__getStatusConnection;
	struct ns__getStatusConnectionResponse *soap_tmp_ns__getStatusConnectionResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://localhost:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__getStatusConnection._param_13 = _param_13;
	soap_serializeheader(soap);
	soap_serialize_ns__getStatusConnection(soap, &soap_tmp_ns__getStatusConnection);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatusConnection(soap, &soap_tmp_ns__getStatusConnection, "ns:getStatusConnection", NULL)
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
	 || soap_put_ns__getStatusConnection(soap, &soap_tmp_ns__getStatusConnection, "ns:getStatusConnection", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	soap_default_StatusConnList_t(soap, ret);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__getStatusConnectionResponse = soap_get_ns__getStatusConnectionResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__getStatusConnectionResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__getStatusConnectionResponse->ret)
		*ret = *soap_tmp_ns__getStatusConnectionResponse->ret;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */
