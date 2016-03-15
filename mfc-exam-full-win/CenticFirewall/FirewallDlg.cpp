// FirewallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FirewallDlg.h"
#include "afxdialogex.h"


// FirewallDlg dialog

IMPLEMENT_DYNAMIC(FirewallDlg, CDialogEx)

FirewallDlg::FirewallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(FirewallDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

FirewallDlg::~FirewallDlg()
{
}

void FirewallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_FIREWALL, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(FirewallDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_FIREWALL, &FirewallDlg::OnTcnSelchangeTabFirewall)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// FirewallDlg message handlers


void FirewallDlg::OnSize(UINT nType, int cx, int cy)
{
	if(m_tabCtrl.GetSafeHwnd())
	{
		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL FirewallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	//Insert tab ctrl
	CString m_strMessage;
	m_tabFwRules.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_FW_RULES);
	m_tabFwRules.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabFwRules);

	m_tabFwGroups.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_FW_GROUPS);
	m_tabFwGroups.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabFwGroups);

	m_tabFwOptions.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_FW_OPTIONS);
	m_tabFwOptions.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabFwOptions);

	m_tabFwP2P.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_FW_P2P);
	m_tabFwP2P.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabFwP2P);

	m_tabFwGeoIP.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_FW_GEOIP);
	m_tabFwGeoIP.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(4, &m_tabFwGeoIP);

	//create dlg
	m_FwGeoIP.Create(IDD_DIALOG_FIREWALL_GEOIP, this);
	m_FwGroups.Create(IDD_DIALOG_FIREWALL_GROUPS, this);
	m_FwOptions.Create(IDD_DIALOG_FIREWALL_OPTIONS, this);
	m_FwP2P.Create(IDD_DIALOG_FIREWALL_P2P, this);
	m_FwRules.Create(IDD_DIALOG_FIREWALL_RULES, this);


	m_dPointer[0] = &m_FwRules;
	m_dPointer[1] = &m_FwGroups ;
	m_dPointer[2] = &m_FwOptions ;
	m_dPointer[3] = &m_FwP2P;
	m_dPointer[4] = &m_FwGeoIP;



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



void FirewallDlg::ShowTabNumber(int number)
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


void FirewallDlg::OnTcnSelchangeTabFirewall(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());
	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);
	*pResult = 0;
}


void FirewallDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void FirewallDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void FirewallDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
