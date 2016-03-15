// ServicesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesDlg.h"
#include "afxdialogex.h"


// ServicesDlg dialog

IMPLEMENT_DYNAMIC(ServicesDlg, CDialogEx)

ServicesDlg::ServicesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

ServicesDlg::~ServicesDlg()
{
}

void ServicesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SERVICES, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(ServicesDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SERVICES, &ServicesDlg::OnTcnSelchangeTabServices)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// ServicesDlg message handlers


void ServicesDlg::OnSize(UINT nType, int cx, int cy)
{

	if(m_tabCtrl.GetSafeHwnd())
	{

		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL ServicesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	//Insert tab ctrl
	CString m_strMessage;
	m_tabServicesIPSecVPN.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_IPSECVPN);
	m_tabServicesIPSecVPN.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabServicesIPSecVPN);

	m_tabServicesSslVpn.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_SSLVPN);
	m_tabServicesSslVpn.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabServicesSslVpn);

	m_tabServicesDynamicDNS.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_DYNAMIC_DNS);
	m_tabServicesDynamicDNS.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabServicesDynamicDNS);

	m_tabServicesTimeServer.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_TIME_SERVER);
	m_tabServicesTimeServer.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabServicesTimeServer);

	m_tabServicesQoS.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_QOS);
	m_tabServicesQoS.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(4, &m_tabServicesQoS);

	m_tabServicesIDS.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SERVICES_IDS);
	m_tabServicesIDS.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (5,&m_tabServicesIDS);

	//create dlg
	m_ServicesDynamicDNS.Create(IDD_DIALOG_SERVICES_DYNAMICDNS, this);
	m_ServicesIDS.Create(IDD_DIALOG_SERVICES_IDS, this);
	m_ServicesIPSecVPN.Create(IDD_DIALOG_SERVICES_IPSECVPN, this);
	m_ServicesQoS.Create(IDD_DIALOG_SERVICES_QOS, this);
	m_ServicesSslVpn.Create(IDD_DIALOG_SERVICES_SSLVPN, this);
	m_ServicesTimeServer.Create(IDD_DIALOG_SERVICES_TIMESERVER, this);

	m_dPointer[0] = &m_ServicesIPSecVPN;
	m_dPointer[1] = &m_ServicesSslVpn ;
	m_dPointer[2] = &m_ServicesDynamicDNS ;
	m_dPointer[3] = &m_ServicesTimeServer;
	m_dPointer[4] = &m_ServicesQoS ;
	m_dPointer[5] = &m_ServicesIDS ;



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



void ServicesDlg::ShowTabNumber(int number)
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


void ServicesDlg::OnTcnSelchangeTabServices(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());

	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);

	*pResult = 0;
}


void ServicesDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void ServicesDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void ServicesDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
