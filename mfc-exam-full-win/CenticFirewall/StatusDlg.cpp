// StatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusDlg.h"
#include "afxdialogex.h"


// StatusDlg dialog

IMPLEMENT_DYNAMIC(StatusDlg, CDialogEx)

StatusDlg::StatusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

StatusDlg::~StatusDlg()
{
}

void StatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_STATUS, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(StatusDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_STATUS, &StatusDlg::OnTcnSelchangeTabStatus)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// StatusDlg message handlers


void StatusDlg::OnSize(UINT nType, int cx, int cy)
{
	if(m_tabCtrl.GetSafeHwnd())
	{

		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL StatusDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	//Insert tab ctrl
	CString m_strMessage;
	m_tabStatusSystem.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_SYSTEM);
	m_tabStatusSystem.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabStatusSystem);

	m_tabStatusServices.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_SERVICES);
	m_tabStatusServices.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabStatusServices);

	m_tabStatusNetworkExternal.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_NETWORK_EXTERNAL);
	m_tabStatusNetworkExternal.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabStatusNetworkExternal);

	m_tabStatusNetworkInternal.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_NETWORK_INTERNAL);
	m_tabStatusNetworkInternal.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabStatusNetworkInternal);


	m_tabStatusNetworkOther.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_NETWORK_OTHER);
	m_tabStatusNetworkOther.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(4,&m_tabStatusNetworkOther);

	m_tabStatusIPSecVPN.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_IPSEC_VPN);
	m_tabStatusIPSecVPN.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(5, &m_tabStatusIPSecVPN);

	m_tabStatusSslVpn.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_SSL_VPN);
	m_tabStatusSslVpn.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (6,&m_tabStatusSslVpn);

	m_tabStatusConnection.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_CONNECTIONS);
	m_tabStatusConnection.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (7,&m_tabStatusConnection);


	m_tabStatusNetTraffic.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_STATUS_NET_TRAFFIC);
	m_tabStatusNetTraffic.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (8,&m_tabStatusNetTraffic);

	

	//create dlg
	m_StatusConnection.Create(IDD_DIALOG_STATUS_CONNECTION, this);
	m_StatusIPSecVPN.Create(IDD_DIALOG_STATUS_IPSEC_VPN, this);
	m_StatusNetTraffic.Create(IDD_DIALOG_STATUS_NETTRAFFIC, this);
	m_StatusNetworkExternal.Create(IDD_DIALOG_STATUS_NETWORK_EXTERNAL, this);
	m_StatusNetworkInternal.Create(IDD_DIALOG_STATUS_NETWORK_INTERNAL, this);
	m_StatusNetworkOther.Create(IDD_DIALOG_STATUS_NETWORK_OTHER, this);
	m_StatusServices.Create(IDD_DIALOG_STATUS_SERVICES, this);
	m_StatusSslVpn.Create(IDD_DIALOG_STATUS_SSL_VPN, this);
	m_StatusSystem.Create(IDD_DIALOG_STATUS_SYSTEM, this);

	m_dPointer[0] = &m_StatusSystem;
	m_dPointer[1] = &m_StatusServices ;
	m_dPointer[2] = &m_StatusNetworkExternal ;
	m_dPointer[3] = &m_StatusNetworkInternal;
	m_dPointer[4] = &m_StatusNetworkOther ;
	m_dPointer[5] = &m_StatusIPSecVPN ;
	m_dPointer[6] = &m_StatusSslVpn ;
	m_dPointer[7] = &m_StatusConnection ;
	m_dPointer[8] = &m_StatusNetTraffic ;


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



void StatusDlg::ShowTabNumber(int number)
{
	CRect mainRect;
	m_tabCtrl.GetWindowRect(mainRect);
	ScreenToClient(&mainRect);


	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);

	//TRACE(L"%s subTab %d \n", __FUNCTION__, number);
	m_dPointer[number]->SetWindowPos(&wndTop, 
				mainRect.left + SUB_TAB_OFFSET_LEFT,	
				mainRect.top + SUB_TAB_OFFSET_TOP, 
				mainRect.Width() + SUB_TAB_OFFSET_RIGHT, 
				mainRect.Height() + SUB_TAB_OFFSET_BOTTOM, 
				SWP_SHOWWINDOW);

	m_tabCtrl.SetCurFocus(number);
	m_cur_subtab = number;
}


void StatusDlg::OnTcnSelchangeTabStatus(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());

	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);
	*pResult = 0;
}


void StatusDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void StatusDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void StatusDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
