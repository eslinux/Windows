// NetworkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkDlg.h"
#include "afxdialogex.h"


// NetworkDlg dialog

IMPLEMENT_DYNAMIC(NetworkDlg, CDialogEx)

NetworkDlg::NetworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

NetworkDlg::~NetworkDlg()
{
}

void NetworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_NETWORK, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(NetworkDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_NETWORK, &NetworkDlg::OnTcnSelchangeTabNetwork)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// NetworkDlg message handlers


void NetworkDlg::OnSize(UINT nType, int cx, int cy)
{
	if(m_tabCtrl.GetSafeHwnd())
	{

		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL NetworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	//Insert tab ctrl
	CString m_strMessage;
	m_tabNetworkWebProxy.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_WEB_PROXY);
	m_tabNetworkWebProxy.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabNetworkWebProxy);

	m_tabNetworkURLFilter.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_URL_FILTER);
	m_tabNetworkURLFilter.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabNetworkURLFilter);

	m_tabNetworkDHCPServer.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_DHCP_SERVER);
	m_tabNetworkDHCPServer.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabNetworkDHCPServer);

	m_tabNetworkConnectionScheduler.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_CONNECTION_SCHEDULER);
	m_tabNetworkConnectionScheduler.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabNetworkConnectionScheduler);

	m_tabNetworkEditHosts.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_EDIT_HOSTS);
	m_tabNetworkEditHosts.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(4,&m_tabNetworkEditHosts);

	m_tabNetworkDNSServer.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_DNS_SERVER);
	m_tabNetworkDNSServer.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(5, &m_tabNetworkDNSServer);

	m_tabNetworkDNSForwarding.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_DNS_FORWARDING);
	m_tabNetworkDNSForwarding.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (6,&m_tabNetworkDNSForwarding);

	m_tabNetworkRouting.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_NETWORK_ROUTING);
	m_tabNetworkRouting.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (7,&m_tabNetworkRouting);

	//create dlg
	m_NetworkConnectionScheduler.Create(IDD_DIALOG_NETWORK_CONNECTION_SCHEDULER, this);
	m_NetworkDHCPServer.Create(IDD_DIALOG_NETWORK_DHCPSERVER, this);
	m_NetworkDNSForwarding.Create(IDD_DIALOG_NETWORK_DNSFORWARDING, this);
	m_NetworkDNSServer.Create(IDD_DIALOG_NETWORK_DNSSERVER, this);
	m_NetworkEditHosts.Create(IDD_DIALOG_NETWORK_EDITHOSTS, this);
	m_NetworkRouting.Create(IDD_DIALOG_NETWORK_ROUTING, this);
	m_NetworkURLFilter.Create(IDD_DIALOG_NETWORK_URLFILTER, this);
	m_NetworkWebProxy.Create(IDD_DIALOG_NETWORK_WEBPROXY, this);


	m_dPointer[0] = &m_NetworkWebProxy;
	m_dPointer[1] = &m_NetworkURLFilter ;
	m_dPointer[2] = &m_NetworkDHCPServer ;
	m_dPointer[3] = &m_NetworkConnectionScheduler;
	m_dPointer[4] = &m_NetworkEditHosts ;
	m_dPointer[5] = &m_NetworkDNSServer ;
	m_dPointer[6] = &m_NetworkDNSForwarding ;
	m_dPointer[7] = &m_NetworkRouting ;
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



void NetworkDlg::ShowTabNumber(int number)
{
	CRect mainRect;
	m_tabCtrl.GetWindowRect(mainRect);
	ScreenToClient(&mainRect);


	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);

	TRACE(L"%s subTab %d \n", __FUNCTION__, number);
	m_dPointer[number]->SetWindowPos(&wndTop, 
				mainRect.left + SUB_TAB_OFFSET_LEFT,	
				mainRect.top + SUB_TAB_OFFSET_TOP, 
				mainRect.Width() + SUB_TAB_OFFSET_RIGHT, 
				mainRect.Height() + SUB_TAB_OFFSET_BOTTOM, 
				SWP_SHOWWINDOW);

	m_tabCtrl.SetCurFocus(number);
	m_cur_subtab = number;
}


void NetworkDlg::OnTcnSelchangeTabNetwork(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());
	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);
	*pResult = 0;
}


void NetworkDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void NetworkDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void NetworkDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
