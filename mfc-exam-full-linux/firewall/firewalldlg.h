#ifndef FIREWALLDLG_H
#define FIREWALLDLG_H

#include "common.h"

#include "fwgeoip.h"
#include "fwgroups.h"
#include "fwoptions.h"
#include "fwp2p.h"
#include "fwrules.h"

class FirewallDlg
{
public:
	FirewallDlg();
	virtual ~FirewallDlg();

public:
	FwGeoIP m_FwGeoIP;
	FwGroups m_FwGroups;
	FwOptions m_FwOptions;
	FwP2P m_FwP2P;
	FwRules m_FwRules;
};

#endif // FIREWALLDLG_H
