
// CenticFirewallDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "gsoapengine.h"
#include "logindlg.h"
#include "dlgresizehelper.h"
#include "centic_wm.h"
#include "atltypes.h"

#include "FirewallDlg.h"
#include "LogsDlg.h"
#include "SystemDlg.h"
#include "StatusDlg.h"
#include "NetworkDlg.h"
#include "ServicesDlg.h"

#include "dlg_para.h"
#include "centicfirewallruntime.h"






// CCenticFirewallDlg dialog
class CCenticFirewallDlg : public CDialogEx
{
// Construction
public:
	CCenticFirewallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DLG_CENTICFIREWALL };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_mainMenu;

	
	LRESULT DoUpdateFromLoginDlg(WPARAM wParam, LPARAM lParam);
	LRESULT DoUpdateTabNumberFromChildDlg(WPARAM wParam, LPARAM lParam);

	//gSoapEngine ctSoapEngine;
	LoginDlg m_loginDlg;
	CenticFirewallRuntime m_firewallRuntime;
	FirewallDlg m_firewallDlg;
	LogsDlg m_logsDlg;
	NetworkDlg m_networkDlg;
	ServicesDlg m_servicesDlg;
	StatusDlg m_statusDlg;
	SystemDlg m_systemDlg;

	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);

	

	CDialog *m_dPointer[NUMBER_OF_MENU_TAB];

	afx_msg void OnSystemHome();
	afx_msg void OnSystemBackup();
	afx_msg void OnSystemSysteminformation();
	afx_msg void OnSystemShutdown();
	afx_msg void OnStatusSystem();
	afx_msg void OnStatusServices();
	afx_msg void OnStatusNetworkexternal();
	afx_msg void OnStatusNetworkinternal();
	afx_msg void OnStatusNetworkother();
	afx_msg void OnStatusIpsecVpn();
	afx_msg void OnStatusSslVpn();
	afx_msg void OnStatusConnection();
	afx_msg void OnStatusNettraffic();
	afx_msg void OnNetworkWebproxy();
	afx_msg void OnNetworkUrlfilter();
	afx_msg void OnNetworkDhcpserver();
	afx_msg void OnNetworkConnectionscheduler();
	afx_msg void OnNetworkEdithosts();
	afx_msg void OnNetworkAssigndnsserver();
	afx_msg void OnNetworkDnsforwarding();
	afx_msg void OnNetworkRouting();
	afx_msg void OnServicesIpsecVpn();
	afx_msg void OnServicesSslVpn();
	afx_msg void OnServicesDynamicDns();
	afx_msg void OnServicesTimeserver();
	afx_msg void OnServicesQos();
	afx_msg void OnServicesIds();
	afx_msg void OnFirewallRules();
	afx_msg void OnFirewallGroups();
	afx_msg void OnFirewallOptions();
	afx_msg void OnFirewallP2pnetworks();
	afx_msg void OnFirewallGeoipblock();
	afx_msg void OnLogsSummary();
	afx_msg void OnLogsSettings();
	afx_msg void OnLogsProxylogs();
	afx_msg void OnLogsProxyreports();
	afx_msg void OnLogsFirewalllogs();
	afx_msg void OnLogsFwLoggraphIp();
	afx_msg void OnLogsFwLoggraphPort();
	afx_msg void OnLogsFwLoggraphCountry();
	afx_msg void OnLogsIdslogs();
	afx_msg void OnLogsUrlfilter();
	afx_msg void OnLogsSystem();
	void ShowTabNumber(int tabMenu, int subTab);
	int m_cur_tabmenu;
	int m_cur_subtab;

	virtual void OnOK();
	
};
