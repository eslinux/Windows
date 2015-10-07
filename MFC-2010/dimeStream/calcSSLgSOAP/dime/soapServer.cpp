/* soapServer.cpp
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
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapServer.cpp ver 2.8.23 2015-10-07 02:34:03 GMT")


extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:putData"))
		return soap_serve_ns__putData(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:getData"))
		return soap_serve_ns__getData(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:getImage"))
		return soap_serve_ns__getImage(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:add"))
		return soap_serve_ns__add(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__putData(struct soap *soap)
{	struct ns__putData soap_tmp_ns__putData;
	struct ns__putDataResponse soap_tmp_ns__putDataResponse;
	arrayOfName soap_tmp_arrayOfName;
	soap_default_ns__putDataResponse(soap, &soap_tmp_ns__putDataResponse);
	soap_tmp_arrayOfName.soap_default(soap);
	soap_tmp_ns__putDataResponse.names = &soap_tmp_arrayOfName;
	soap_default_ns__putData(soap, &soap_tmp_ns__putData);
	if (!soap_get_ns__putData(soap, &soap_tmp_ns__putData, "ns:putData", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__putData(soap, soap_tmp_ns__putData.data, soap_tmp_ns__putDataResponse.names);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__putDataResponse(soap, &soap_tmp_ns__putDataResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__putDataResponse(soap, &soap_tmp_ns__putDataResponse, "ns:putDataResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__putDataResponse(soap, &soap_tmp_ns__putDataResponse, "ns:putDataResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__getData(struct soap *soap)
{	struct ns__getData soap_tmp_ns__getData;
	struct ns__getDataResponse soap_tmp_ns__getDataResponse;
	arrayOfData soap_tmp_arrayOfData;
	soap_default_ns__getDataResponse(soap, &soap_tmp_ns__getDataResponse);
	soap_tmp_arrayOfData.soap_default(soap);
	soap_tmp_ns__getDataResponse.data = &soap_tmp_arrayOfData;
	soap_default_ns__getData(soap, &soap_tmp_ns__getData);
	if (!soap_get_ns__getData(soap, &soap_tmp_ns__getData, "ns:getData", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__getData(soap, soap_tmp_ns__getData.names, soap_tmp_ns__getDataResponse.data);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__getDataResponse(soap, &soap_tmp_ns__getDataResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getDataResponse(soap, &soap_tmp_ns__getDataResponse, "ns:getDataResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getDataResponse(soap, &soap_tmp_ns__getDataResponse, "ns:getDataResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__getImage(struct soap *soap)
{	struct ns__getImage soap_tmp_ns__getImage;
	struct ns__getImageResponse soap_tmp_ns__getImageResponse;
	soap_default_ns__getImageResponse(soap, &soap_tmp_ns__getImageResponse);
	soap_default_ns__getImage(soap, &soap_tmp_ns__getImage);
	if (!soap_get_ns__getImage(soap, &soap_tmp_ns__getImage, "ns:getImage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__getImage(soap, soap_tmp_ns__getImage.name, soap_tmp_ns__getImageResponse.image);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__getImageResponse(soap, &soap_tmp_ns__getImageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getImageResponse(soap, &soap_tmp_ns__getImageResponse, "ns:getImageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getImageResponse(soap, &soap_tmp_ns__getImageResponse, "ns:getImageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__add(struct soap *soap)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse soap_tmp_ns__addResponse;
	float soap_tmp_float;
	soap_default_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	soap_default_float(soap, &soap_tmp_float);
	soap_tmp_ns__addResponse.ret = &soap_tmp_float;
	soap_default_ns__add(soap, &soap_tmp_ns__add);
	if (!soap_get_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__add(soap, soap_tmp_ns__add.a, soap_tmp_ns__add.b, soap_tmp_ns__addResponse.ret);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.cpp */
