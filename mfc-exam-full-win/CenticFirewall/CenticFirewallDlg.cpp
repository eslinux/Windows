
// CenticFirewallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "CenticFirewallDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCenticFirewallDlg dialog




CCenticFirewallDlg::CCenticFirewallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCenticFirewallDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cur_tabmenu = TAB_MENU_LOGIN;
	m_cur_subtab = 0;
}

void CCenticFirewallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_MENU_TITLE, m_menuTitle);
}

BEGIN_MESSAGE_MAP(CCenticFirewallDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_LOGIN_MESSAGE, &CCenticFirewallDlg::DoUpdateFromLoginDlg)
	ON_MESSAGE(WM_UPDATE_TABNUMBER_MESSAGE, &CCenticFirewallDlg::DoUpdateTabNumberFromChildDlg)
	ON_WM_SIZE()

	ON_COMMAND(ID_SYSTEM_HOME, &CCenticFirewallDlg::OnSystemHome)
	ON_COMMAND(ID_SYSTEM_BACKUP, &CCenticFirewallDlg::OnSystemBackup)
	ON_COMMAND(ID_SYSTEM_SYSTEMINFORMATION, &CCenticFirewallDlg::OnSystemSysteminformation)
	ON_COMMAND(ID_SYSTEM_SHUTDOWN, &CCenticFirewallDlg::OnSystemShutdown)
	ON_COMMAND(ID_STATUS_SYSTEM, &CCenticFirewallDlg::OnStatusSystem)
	ON_COMMAND(ID_STATUS_SERVICES, &CCenticFirewallDlg::OnStatusServices)
	ON_COMMAND(ID_STATUS_NETWORKEXTERNAL, &CCenticFirewallDlg::OnStatusNetworkexternal)
	ON_COMMAND(ID_STATUS_NETWORKINTERNAL, &CCenticFirewallDlg::OnStatusNetworkinternal)
	ON_COMMAND(ID_STATUS_NETWORKOTHER, &CCenticFirewallDlg::OnStatusNetworkother)
	ON_COMMAND(ID_STATUS_IPSEC_VPN, &CCenticFirewallDlg::OnStatusIpsecVpn)
	ON_COMMAND(ID_STATUS_SSL_VPN, &CCenticFirewallDlg::OnStatusSslVpn)
	ON_COMMAND(ID_STATUS_CONNECTION, &CCenticFirewallDlg::OnStatusConnection)
	ON_COMMAND(ID_STATUS_NETTRAFFIC, &CCenticFirewallDlg::OnStatusNettraffic)
	ON_COMMAND(ID_NETWORK_WEBPROXY, &CCenticFirewallDlg::OnNetworkWebproxy)
	ON_COMMAND(ID_NETWORK_URLFILTER, &CCenticFirewallDlg::OnNetworkUrlfilter)
	ON_COMMAND(ID_NETWORK_DHCPSERVER, &CCenticFirewallDlg::OnNetworkDhcpserver)
	ON_COMMAND(ID_NETWORK_CONNECTIONSCHEDULER, &CCenticFirewallDlg::OnNetworkConnectionscheduler)
	ON_COMMAND(ID_NETWORK_EDITHOSTS, &CCenticFirewallDlg::OnNetworkEdithosts)
	ON_COMMAND(ID_NETWORK_ASSIGNDNSSERVER, &CCenticFirewallDlg::OnNetworkAssigndnsserver)
	ON_COMMAND(ID_NETWORK_DNSFORWARDING, &CCenticFirewallDlg::OnNetworkDnsforwarding)
	ON_COMMAND(ID_NETWORK_ROUTING, &CCenticFirewallDlg::OnNetworkRouting)
	ON_COMMAND(ID_SERVICES_IPSEC_VPN, &CCenticFirewallDlg::OnServicesIpsecVpn)
	ON_COMMAND(ID_SERVICES_SSL_VPN, &CCenticFirewallDlg::OnServicesSslVpn)
	ON_COMMAND(ID_SERVICES_DYNAMIC_DNS, &CCenticFirewallDlg::OnServicesDynamicDns)
	ON_COMMAND(ID_SERVICES_TIMESERVER, &CCenticFirewallDlg::OnServicesTimeserver)
	ON_COMMAND(ID_SERVICES_QOS, &CCenticFirewallDlg::OnServicesQos)
	ON_COMMAND(ID_SERVICES_IDS, &CCenticFirewallDlg::OnServicesIds)
	ON_COMMAND(ID_FIREWALL_RULES, &CCenticFirewallDlg::OnFirewallRules)
	ON_COMMAND(ID_FIREWALL_GROUPS, &CCenticFirewallDlg::OnFirewallGroups)
	ON_COMMAND(ID_FIREWALL_OPTIONS, &CCenticFirewallDlg::OnFirewallOptions)
	ON_COMMAND(ID_FIREWALL_P2PNETWORKS, &CCenticFirewallDlg::OnFirewallP2pnetworks)
	ON_COMMAND(ID_FIREWALL_GEOIPBLOCK, &CCenticFirewallDlg::OnFirewallGeoipblock)
	ON_COMMAND(ID_LOGS_SUMMARY, &CCenticFirewallDlg::OnLogsSummary)
	ON_COMMAND(ID_LOGS_SETTINGS, &CCenticFirewallDlg::OnLogsSettings)
	ON_COMMAND(ID_LOGS_PROXYLOGS, &CCenticFirewallDlg::OnLogsProxylogs)
	ON_COMMAND(ID_LOGS_PROXYREPORTS, &CCenticFirewallDlg::OnLogsProxyreports)
	ON_COMMAND(ID_LOGS_FIREWALLLOGS, &CCenticFirewallDlg::OnLogsFirewalllogs)
	ON_COMMAND(ID_LOGS_FW_LOGGRAPH_IP, &CCenticFirewallDlg::OnLogsFwLoggraphIp)
	ON_COMMAND(ID_LOGS_FW_LOGGRAPH_PORT, &CCenticFirewallDlg::OnLogsFwLoggraphPort)
	ON_COMMAND(ID_LOGS_FW_LOGGRAPH_COUNTRY, &CCenticFirewallDlg::OnLogsFwLoggraphCountry)
	ON_COMMAND(ID_LOGS_IDSLOGS, &CCenticFirewallDlg::OnLogsIdslogs)
	ON_COMMAND(ID_LOGS_URLFILTER, &CCenticFirewallDlg::OnLogsUrlfilter)
	ON_COMMAND(ID_LOGS_SYSTEM, &CCenticFirewallDlg::OnLogsSystem)
END_MESSAGE_MAP()


LRESULT CCenticFirewallDlg::DoUpdateFromLoginDlg(WPARAM wParam, LPARAM lParam)
{
	//hiden login dlg
	m_loginDlg.ShowWindow(SW_HIDE);
	TRACE(L"m_loginDlg.ShowWindow(SW_HIDE) \n ");

	//show system::home dlg
	m_firewallRuntime.ShowWindow(SW_SHOW);
	ShowTabNumber(TAB_MENU_DEFAULT, 0);

	//show main menu
	SetMenu(&m_mainMenu);

	CString title;
	title.LoadString(IDS_CENTIC_FIREWALL_ADMINISTRATOR);
	SetWindowText(title);

	return true;
}



LRESULT CCenticFirewallDlg::DoUpdateTabNumberFromChildDlg(WPARAM wParam, LPARAM lParam)
{
	m_cur_subtab = (int)wParam;
	//TRACE(L"%s m_cur_subtab=%d \n ", __FUNCTION__, m_cur_subtab);
	return true;
}

// CCenticFirewallDlg message handlers

BOOL CCenticFirewallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// TODO: Add extra initialization here
//========================================================================
// load background
//========================================================================
	//HBITMAP bmp = LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP_WHITE));
	//SetBackgroundImage(bmp, BACKGR_TOPLEFT);


//========================================================================
// load top menu
//========================================================================
	m_mainMenu.LoadMenu(IDR_MAINMENU_TOP);
	//SetMenu(&m_mainMenu);

//========================================================================
// initialize resize helper
//========================================================================
	m_resizeHelper.Init(m_hWnd);


//========================================================================
// create dialog
//========================================================================		
	m_loginDlg.Create(IDD_DIALOG_LOGIN,this);
	m_firewallRuntime.Create(IDD_DIALOG_RUNTIME,this);

	m_systemDlg.Create(IDD_DIALOG_SYSTEM,this);
	m_statusDlg.Create(IDD_DIALOG_STATUS,this);
	m_networkDlg.Create(IDD_DIALOG_NETWORK,this);
	m_servicesDlg.Create(IDD_DIALOG_SERVICES,this);
	m_firewallDlg.Create(IDD_DIALOG_FIREWALL,this);
	m_logsDlg.Create(IDD_DIALOG_LOGS,this);

	
	m_dPointer[0] = &m_systemDlg;
	m_dPointer[1] = &m_statusDlg ;
	m_dPointer[2] = &m_networkDlg ;
	m_dPointer[3] = &m_servicesDlg;
	m_dPointer[4] = &m_firewallDlg ;
	m_dPointer[5] = &m_logsDlg ;



//========================================================================
// show login dlg
//========================================================================
	int nScreenX,nScreenY;
	nScreenX = GetSystemMetrics(SM_CXSCREEN);
	nScreenY  = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(&wndTop, 
				(nScreenX-MAIN_DLG_WIDTH)/2, (nScreenY - MAIN_DLG_HEIGHT)/2, 
				MAIN_DLG_WIDTH, MAIN_DLG_HEIGHT, 
				SWP_SHOWWINDOW);
	
	CRect mainRect;
	GetWindowRect(mainRect);
	ScreenToClient(mainRect);

	m_loginDlg.SetWindowPos(&wndTop, 
							mainRect.left + (mainRect.Width() - mainRect.Width()/2)/2,	
							mainRect.top + (mainRect.Height() - mainRect.Height()/2)/2, 
							mainRect.Width()/2, mainRect.Height()/2, 
							SWP_SHOWWINDOW);





	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCenticFirewallDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCenticFirewallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCenticFirewallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CCenticFirewallDlg::OnSize(UINT nType, int cx, int cy)
{
	
	//if(nType==2)
	//{
	//	//Maximize
	//	
	//	

	//}
	//else
	//{
	//	//Restore down
	//	
	//}

	if(m_cur_tabmenu >= TAB_MENU_SYSTEM){
		ShowTabNumber(TAB_MENU_ONSIZE, 0);
	}else if(m_cur_tabmenu == TAB_MENU_LOGIN){
		if(m_loginDlg.GetSafeHwnd())
		{
			CRect mainRect;
			GetWindowRect(mainRect);
			ScreenToClient(mainRect);
			m_loginDlg.SetWindowPos(&wndTop, 
									mainRect.left + (mainRect.Width() - mainRect.Width()/2)/2,	
									mainRect.top + (mainRect.Height() - mainRect.Height()/2)/2, 
									mainRect.Width()/2, mainRect.Height()/2, 
									SWP_SHOWWINDOW);
			//TRACE(L"m_cur_tabmenu == TAB_MENU_LOGIN \n ");
		}
		//TRACE(L"===>>> m_cur_tabmenu == TAB_MENU_LOGIN \n ");
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}




void CCenticFirewallDlg::ShowTabNumber(int tabMenu, int subTab)
{
	CRect mainRect;
	GetWindowRect(mainRect);
	ScreenToClient(mainRect);

	if(tabMenu == TAB_MENU_DEFAULT){
		//Default System::Home dlg
		m_systemDlg.SetWindowPos(&wndTop, 
					mainRect.left + TAB_MENU_OFFSET_LEFT,	
					mainRect.top + TAB_MENU_OFFSET_TOP, 
					mainRect.Width() + TAB_MENU_OFFSET_RIGHT, 
					mainRect.Height() + TAB_MENU_OFFSET_BOTTOM, 
					SWP_SHOWWINDOW);
		m_systemDlg.ShowTabNumber(TAB_SYSTEM_HOME);

		m_cur_tabmenu = TAB_MENU_SYSTEM;
		m_cur_subtab = TAB_SYSTEM_HOME;

		return;
	}

	if(tabMenu == TAB_MENU_ONSIZE){
		tabMenu = m_cur_tabmenu;
		subTab = m_cur_subtab;

		m_dPointer[tabMenu]->SetWindowPos(&wndTop, 
					mainRect.left + TAB_MENU_OFFSET_LEFT,	
					mainRect.top + TAB_MENU_OFFSET_TOP, 
					mainRect.Width() + TAB_MENU_OFFSET_RIGHT, 
					mainRect.Height() + TAB_MENU_OFFSET_BOTTOM, 
					SWP_SHOWWINDOW);

		goto __ShowSubTab;
	}


	if(tabMenu == m_cur_tabmenu && m_cur_subtab == subTab) return;
	if(tabMenu == m_cur_tabmenu){
		goto __ShowSubTab;
	}else{
		m_dPointer[m_cur_tabmenu]->ShowWindow(SW_HIDE);

		
		m_dPointer[tabMenu]->SetWindowPos(&wndTop, 
					mainRect.left + TAB_MENU_OFFSET_LEFT,	
					mainRect.top + TAB_MENU_OFFSET_TOP, 
					mainRect.Width() + TAB_MENU_OFFSET_RIGHT, 
					mainRect.Height() + TAB_MENU_OFFSET_BOTTOM, 
					SWP_SHOWWINDOW);
		goto __ShowSubTab;			
	}

__ShowSubTab:	
	//TRACE(L"%s tabMenu %d, subTab %d \n ", __FUNCTION__, tabMenu, subTab);
	switch (tabMenu){
	case TAB_MENU_SYSTEM:
		m_systemDlg.ShowTabNumber(subTab);
		break;
	case TAB_MENU_STATUS:
		m_statusDlg.ShowTabNumber(subTab);
		break;
	case TAB_MENU_NETWORK:
		m_networkDlg.ShowTabNumber(subTab);
		break;
	case TAB_MENU_SERVICES:
		m_servicesDlg.ShowTabNumber(subTab);
		break;
	case TAB_MENU_FIREWALL:
		m_firewallDlg.ShowTabNumber(subTab);
		break;
	case TAB_MENU_LOGS:
		m_logsDlg.ShowTabNumber(subTab);
		break;
	default:
		break;
	}

	m_cur_tabmenu = tabMenu;
	m_cur_subtab = subTab;

}





void CCenticFirewallDlg::OnSystemHome()
{
	// TODO: Add your command handler code here
	///MessageBox(L"CCenticFirewallDlg::OnSystemHome");
	ShowTabNumber(TAB_MENU_SYSTEM, TAB_SYSTEM_HOME);
}



void CCenticFirewallDlg::OnSystemBackup()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SYSTEM, TAB_SYSTEM_BACKUP);
}


void CCenticFirewallDlg::OnSystemSysteminformation()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SYSTEM, TAB_SYSTEM_SYSINFORMATION);
}


void CCenticFirewallDlg::OnSystemShutdown()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SYSTEM, TAB_SYSTEM_SHUTDOWN);
}


void CCenticFirewallDlg::OnStatusSystem()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_SYSTEM);
}


void CCenticFirewallDlg::OnStatusServices()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_SERVICES);
}


void CCenticFirewallDlg::OnStatusNetworkexternal()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_NETWORK_EXTERNAL);
}


void CCenticFirewallDlg::OnStatusNetworkinternal()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_NETWORK_INTERNAL);
}


void CCenticFirewallDlg::OnStatusNetworkother()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_NETWORK_OTHER);
}


void CCenticFirewallDlg::OnStatusIpsecVpn()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_IPSEC_VPN);
}


void CCenticFirewallDlg::OnStatusSslVpn()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_SSL_VPN);
}


void CCenticFirewallDlg::OnStatusConnection()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_CONNECTION);
}


void CCenticFirewallDlg::OnStatusNettraffic()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_STATUS, TAB_STATUS_NETTRAFFIC);
}


void CCenticFirewallDlg::OnNetworkWebproxy()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_WEBPROXY);

}


void CCenticFirewallDlg::OnNetworkUrlfilter()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_URL_FILTER);
}


void CCenticFirewallDlg::OnNetworkDhcpserver()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_DHCP_SERVER);
}


void CCenticFirewallDlg::OnNetworkConnectionscheduler()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_CONNECTION_SCHEDULER);
}


void CCenticFirewallDlg::OnNetworkEdithosts()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_EDIT_HOSTS);
}


void CCenticFirewallDlg::OnNetworkAssigndnsserver()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_DNS_SERVER);
}


void CCenticFirewallDlg::OnNetworkDnsforwarding()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_DNS_FORWARDING);
}


void CCenticFirewallDlg::OnNetworkRouting()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_NETWORK, TAB_NETWORK_ROUTING);
}


void CCenticFirewallDlg::OnServicesIpsecVpn()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_IPSEC_VPN);
}


void CCenticFirewallDlg::OnServicesSslVpn()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_SSL_VPN);
}


void CCenticFirewallDlg::OnServicesDynamicDns()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_DYNAMIC_DNS);
}


void CCenticFirewallDlg::OnServicesTimeserver()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_TIME_SERVER);
}


void CCenticFirewallDlg::OnServicesQos()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_QOS);
}


void CCenticFirewallDlg::OnServicesIds()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_SERVICES, TAB_SERVICES_IDS);
}


void CCenticFirewallDlg::OnFirewallRules()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_FIREWALL, TAB_FIREWALL_RULES);
}


void CCenticFirewallDlg::OnFirewallGroups()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_FIREWALL, TAB_FIREWALL_GROUPS);
}


void CCenticFirewallDlg::OnFirewallOptions()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_FIREWALL, TAB_FIREWALL_OPTIONS);
}


void CCenticFirewallDlg::OnFirewallP2pnetworks()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_FIREWALL, TAB_FIREWALL_P2P);
}


void CCenticFirewallDlg::OnFirewallGeoipblock()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_FIREWALL, TAB_FIREWALL_GEOIP);
}


void CCenticFirewallDlg::OnLogsSummary()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_SUMMARY);
}


void CCenticFirewallDlg::OnLogsSettings()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_SETTINGS);
}


void CCenticFirewallDlg::OnLogsProxylogs()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_PROXY_LOGS);
}


void CCenticFirewallDlg::OnLogsProxyreports()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_PROXY_REPORTS);
}


void CCenticFirewallDlg::OnLogsFirewalllogs()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_FIREWALL_LOGS);
}


void CCenticFirewallDlg::OnLogsFwLoggraphIp()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_FW_LOGGRAPHS_IP);
}


void CCenticFirewallDlg::OnLogsFwLoggraphPort()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_FW_LOGGRAPHS_PORT);
}


void CCenticFirewallDlg::OnLogsFwLoggraphCountry()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_FW_LOGGRAPHS_COUNTRY);
}


void CCenticFirewallDlg::OnLogsIdslogs()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_IDS);
}


void CCenticFirewallDlg::OnLogsUrlfilter()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_URL_FILTER);
}


void CCenticFirewallDlg::OnLogsSystem()
{
	// TODO: Add your command handler code here
	ShowTabNumber(TAB_MENU_LOGS, TAB_LOGS_SYSTEM);
}





void CCenticFirewallDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
