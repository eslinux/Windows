#ifndef STATUSDLG_H
#define STATUSDLG_H
#include "common.h"

#include "statusconnection.h"
#include "statusipsecvpn.h"
#include "statusnettraffic.h"
#include "statusnetworkexternal.h"
#include "statusnetworkinternal.h"
#include "statusnetworkother.h"
#include "statusservices.h"
#include "statussslvpn.h"
#include "statussystem.h"

class StatusDlg
{
public:
	StatusDlg();
	virtual ~StatusDlg();


	StatusConnection m_StatusConnection;
	StatusIPSecVPN m_StatusIPSecVPN;
	StatusNetTraffic m_StatusNetTraffic;
	StatusNetworkExternal m_StatusNetworkExternal;
	StatusNetworkInternal m_StatusNetworkInternal;
	StatusNetworkOther m_StatusNetworkOther;
	StatusServices m_StatusServices;
	StatusSslVpn m_StatusSslVpn;
	StatusSystem m_StatusSystem;
};

#endif // STATUSDLG_H
