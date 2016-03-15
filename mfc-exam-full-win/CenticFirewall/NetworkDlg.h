#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"


#include "NetworkConnectionScheduler.h"
#include "NetworkDHCPServer.h"
#include "NetworkDNSForwarding.h"
#include "NetworkDNSServer.h"
#include "NetworkEditHosts.h"
#include "NetworkRouting.h"
#include "NetworkURLFilter.h"
#include "NetworkWebProxy.h"

#include "dlg_para.h"
#include "centic_wm.h"

// NetworkDlg dialog

class NetworkDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkDlg)

public:
	NetworkDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();

	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabNetworkConnectionScheduler;
	TCITEM m_tabNetworkDHCPServer;
	TCITEM m_tabNetworkDNSForwarding;
	TCITEM m_tabNetworkDNSServer;
	TCITEM m_tabNetworkEditHosts;
	TCITEM m_tabNetworkRouting;
	TCITEM m_tabNetworkURLFilter;
	TCITEM m_tabNetworkWebProxy;

	NetworkConnectionScheduler m_NetworkConnectionScheduler;
	NetworkDHCPServer m_NetworkDHCPServer;
	NetworkDNSForwarding m_NetworkDNSForwarding;
	NetworkDNSServer m_NetworkDNSServer;
	NetworkEditHosts m_NetworkEditHosts;
	NetworkRouting m_NetworkRouting;
	NetworkURLFilter m_NetworkURLFilter;
	NetworkWebProxy m_NetworkWebProxy;

	CDialog *m_dPointer[NUMBER_OF_NETWORK_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabNetwork(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
