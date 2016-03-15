#ifndef SERVICESDLG_H
#define SERVICESDLG_H
#include "common.h"

#include "servicesdynamicdns.h"
#include "servicesids.h"
#include "servicesipsecvpn.h"
#include "servicesqos.h"
#include "servicessslvpn.h"
#include "servicestimeserver.h"


class ServicesDlg
{
public:
	ServicesDlg();
	virtual ~ServicesDlg();


	ServicesDynamicDNS m_ServicesDynamicDNS;
	ServicesIDS m_ServicesIDS;
	ServicesIPSecVPN m_ServicesIPSecVPN;
	ServicesQoS m_ServicesQoS;
	ServicesSslVpn m_ServicesSslVpn;
	ServicesTimeServer m_ServicesTimeServer;
};

#endif // SERVICESDLG_H
