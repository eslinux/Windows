/*
	calcserver.cpp

	Example calculator service in C++

	$ soapcpp2 -i calc.h
	$ cc -o calcserver++ calcserver.cpp stdsoap2.cpp soapC.cpp soapcalcService.cpp
	where stdsoap2.cpp is in the 'gsoap' directory, or use libgsoap++:
	$ cc -o calcserver++ calcserver.cpp soapC.cpp soapcalcService.cpp -lgsoap++

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

#include "soapcalcService.h"
#include "calc.nsmap"

#include <stdio.h>
#define WITH_OPENSSL 1


int main(int argc, char **argv)
{


	calcService calc;

#ifdef WITH_OPENSSL
	SOAP_SOCKET m;
	struct soap *tsoap;

	if (soap_ssl_server_context(&calc,
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
		soap_print_fault(&calc, stderr);
		exit(1);
	}


	calc.accept_timeout = 60;	/* server times out after 1 minute inactivity */
	calc.send_timeout = calc.recv_timeout = 30;	/* if I/O stalls, then timeout after 30 seconds */

	m = soap_bind(&calc, NULL, 2012, 100);
	if (!soap_valid_socket(m))
	{
		soap_print_fault(&calc, stderr);
		exit(1);
	}

	fprintf(stderr, "Bind successful: socket = %d\n", m);

#if 0
	if (calc.run(2012))
	{
		calc.soap_stream_fault(std::cerr);
		exit(-1);
	}

#else
	for (;;)
	{
		SOAP_SOCKET s = soap_accept(&calc);
		if (!soap_valid_socket(s))
		{
			if (calc.errnum)
				soap_print_fault(&calc, stderr);
			else
				fprintf(stderr, "Server timed out (timeout set to %d seconds)\n", calc.accept_timeout);
			break;
		}

		fprintf(stderr, "Socket %d connection from IP %d.%d.%d.%d\n", s, (int)(calc.ip>>24)&0xFF, (int)(calc.ip>>16)&0xFF, (int)(calc.ip>>8)&0xFF, (int)calc.ip&0xFF);
//		tsoap = soap_copy(&calc);
//		if (!tsoap)
//		{
//			soap_closesock(&calc);
//			printf("continue ... \n");
//			continue;
//		}


		if (soap_ssl_accept(&calc) != SOAP_OK)
		{ /* when soap_ssl_accept() fails, socket is closed and SSL data reset */
			printf("continue 1 ... \n");
			soap_print_fault(&calc, stderr);
			fprintf(stderr, "SSL request failed, continue with next call...\n");
		}

		printf("continue 2 ... \n");


	}
#endif

#else

	if (argc < 2)
		calc.serve();	/* serve as CGI application */
	else
	{
		int port = atoi(argv[1]);
		if (!port)
		{ fprintf(stderr, "Usage: calcserver++ <port>\n");
			exit(0);
		}
		/* run iterative server on port until fatal error */
		if (calc.run(port))
		{
			calc.soap_stream_fault(std::cerr);
			exit(-1);
		}
	}
#endif




	return 0;
} 

int calcService::add(double a, double b, double *result)
{
	*result = a + b;
	return SOAP_OK;
} 

int calcService::sub(double a, double b, double *result)
{ *result = a - b;
	return SOAP_OK;
} 

int calcService::mul(double a, double b, double *result)
{ *result = a * b;
	return SOAP_OK;
} 

int calcService::div(double a, double b, double *result)
{ if (b)
		*result = a / b;
	else
	{ char *s = (char*)soap_malloc(this, 1024);
		(SOAP_SNPRINTF(s, 1024, 100), "<error xmlns=\"http://tempuri.org/\">Can't divide %f by %f</error>", a, b);
		return soap_senderfault("Division by zero", s);
	}
	return SOAP_OK;
} 

int calcService::pow(double a, double b, double *result)
{ *result = ::pow(a, b);
	if (soap_errno == EDOM)	/* soap_errno is like errno, but compatible with Win32 */
	{ char *s = (char*)soap_malloc(this, 1024);
		(SOAP_SNPRINTF(s, 1024, 100), "<error xmlns=\"http://tempuri.org/\">Can't take power of %f to %f</error>", a, b);
		return soap_senderfault("Power function domain error", s);
	}
	return SOAP_OK;
}
