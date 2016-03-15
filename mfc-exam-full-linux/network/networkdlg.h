#ifndef NETWORKDLG_H
#define NETWORKDLG_H
#include "common.h"

#include "networkconnectionscheduler.h"
#include "networkdhcpserver.h"
#include "networkdlg.h"
#include "networkdnsforwarding.h"
#include "networkdnsserver.h"
#include "networkedithosts.h"
#include "networkrouting.h"
#include "networkurlfilter.h"
#include "networkwebproxy.h"

class NetworkDlg
{
public:
	NetworkDlg();
	virtual ~NetworkDlg();


	NetworkConnectionScheduler m_NetworkConnectionScheduler;
	NetworkDHCPServer m_NetworkDHCPServer;
	NetworkDNSForwarding m_NetworkDNSForwarding;
	NetworkDNSServer m_NetworkDNSServer;
	NetworkEditHosts m_NetworkEditHosts;
	NetworkRouting m_NetworkRouting;
	NetworkURLFilter m_NetworkURLFilter;
	NetworkWebProxy m_NetworkWebProxy;
};

#endif // NETWORKDLG_H
