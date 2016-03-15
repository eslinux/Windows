#pragma once
#include <list>
#include <vector>
#include "soapStub.h"
#include "afxmt.h"

#define FREEX(x) {if((x)) free((x)); (x)=NULL;}


class gSoapEngine
{
public:
	gSoapEngine(void);
	~gSoapEngine(void);
	//CCriticalSection m_gsoapSection;

	//LOGIN and RUNTIME
	bool login(char * username, char * passwd);
	bool getRuntimeInfo(RuntimeInfo_t * ret);

	//SYSTEM
	bool getSysHomeInterface(NetInterface_t * ret);
	bool SysBackupHandle(enum ns__SysBackupEvent in, char *path);
	bool getSysSysInfo(SysInfo_t * ret);
	bool SysShutdownHandle(enum ns__SysShutdownEvent action);

	//STATUS
	bool getStatusSystemGraph(enum SysGraphMode_t mode, SystemData_t *ret);
	bool getStatusServices(StatusServicesList_t *ret);
	bool getStatusNetworkExternal(enum SysGraphMode_t mode, NetworkData_t * ret);
	bool getStatusNetworkInternal(enum SysGraphMode_t mode, NetworkData_t * ret);
	bool getStatusNetworkOther(enum SysGraphMode_t mode, NetworkData_t * ret);
	//NETWORK


	//SERVICES


	//FIREWALL


	//LOGS

	
	bool getStatusConnection(StatusConnList_t * ret);
	CCriticalSection m_gsoapSection;
};

extern gSoapEngine ctSoapEngine;