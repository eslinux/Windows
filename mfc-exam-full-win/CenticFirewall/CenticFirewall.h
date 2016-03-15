
// CenticFirewall.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "afxmt.h"

#include "centic_wm.h"
#include "dlg_para.h"
#include "gSoapEngine.h"
#include "event_handle.h"
#include "memory_handle.h"

// CCenticFirewallApp:
// See CenticFirewall.cpp for the implementation of this class
//

class CCenticFirewallApp : public CWinApp
{
public:
	CCenticFirewallApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	
	CCriticalSection m_graphSection;
};

extern CCenticFirewallApp theApp;