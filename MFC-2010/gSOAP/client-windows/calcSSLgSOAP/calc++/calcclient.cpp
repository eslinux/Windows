/*
	calcclient.cpp

	Example calculator service client in C++

	Service definitions in calc.h (not generated by wsdl2h, but similar)

	$ soapcpp2 -i calc.h
	$ cc -o calcclient calcclient.cpp stdsoap2.cpp soapC.cpp soapcalcProxy.cpp
	where stdsoap2.cpp is in the 'gsoap' directory, or use libgsoap++:
	$ cc -o calcclient calcclient.cpp soapC.cpp soapcalcProxy.cpp -lgsoap++

--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2001-2008, Robert van Engelen, Genivia, Inc. All Rights Reserved.
This software is released under one of the following two licenses:
GPL or Genivia's license for commercial use.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapcalcProxy.h"
#include "calc.nsmap"

#include <stdio.h>

#define WITH_OPENSSL 1
const char server[] = "https://10.49.46.201:2012";

int main(int argc, char **argv)
{
	if (argc < 4)
	{ fprintf(stderr, "Usage: [add|sub|mul|div|pow] num num\n");
		exit(0);
	}


	double a, b, result;
	a = strtod(argv[2], NULL);
	b = strtod(argv[3], NULL);


	calcProxy calc;
	calc.soap_endpoint = server;

#ifdef WITH_OPENSSL

	soap_ssl_init();

	if (soap_ssl_client_context(&calc,
								//SOAP_SSL_DEFAULT,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								NULL, 		/* keyfile: required only when client must authenticate to server (see SSL docs on how to obtain this file) */
								NULL, 		/* password to read the keyfile */
								"cacert.pem",	/* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
								NULL,		/* optional capath to directory with trusted certificates */
								NULL		/* if randfile!=NULL: use a file with random data to seed randomness */
								))
	{
		soap_print_fault(&calc, stderr);
		exit(1);
	}

	calc.connect_timeout = 60;	/* try to connect for 1 minute */
	calc.send_timeout = calc.recv_timeout = 30;	/* if I/O stalls, then timeout after 30 seconds */

#endif



	switch (*argv[1])
	{
	case 'a':
		printf("start add \n");
		calc.add(a, b, &result);
		printf("stop add \n");
		break;
	case 's':
		calc.sub(a, b, &result);
		break;
	case 'm':
		calc.mul(a, b, &result);
		break;
	case 'd':
		calc.div(a, b, &result);
		break;
	case 'p':
		calc.pow(a, b, &result);
		break;
	default:
		fprintf(stderr, "Unknown command\n");
		exit(0);
	}


	if (calc.error){
		printf("soap_stream_fault \n", result);
		calc.soap_stream_fault(std::cerr);
	}
	else{
		printf("result = %g\n", result);
	}


	return 0;
}

