/* soapClient.cpp
   Generated by gSOAP 2.8.23 from dime.h

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

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.23 2015-10-07 02:34:03 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__putData(struct soap *soap, const char *soap_endpoint, const char *soap_action, arrayOfData *data, arrayOfName *names)
{	struct ns__putData soap_tmp_ns__putData;
	struct ns__putDataResponse *soap_tmp_ns__putDataResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://10.49.46.199:8085";
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getData(struct soap *soap, const char *soap_endpoint, const char *soap_action, arrayOfName *names, arrayOfData *data)
{	struct ns__getData soap_tmp_ns__getData;
	struct ns__getDataResponse *soap_tmp_ns__getDataResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://10.49.46.199:8085";
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
		soap_endpoint = "https://10.49.46.199:8085";
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

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, float a, float b, float *ret)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse *soap_tmp_ns__addResponse;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://10.49.46.199:8085";
	soap_begin(soap);
	soap->encodingStyle = "";
	soap_tmp_ns__add.a = a;
	soap_tmp_ns__add.b = b;
	soap_serializeheader(soap);
	soap_serialize_ns__add(soap, &soap_tmp_ns__add);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
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
	 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ret)
		return soap_closesock(soap);
	soap_default_float(soap, ret);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__addResponse = soap_get_ns__addResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__addResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (ret && soap_tmp_ns__addResponse->ret)
		*ret = *soap_tmp_ns__addResponse->ret;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */