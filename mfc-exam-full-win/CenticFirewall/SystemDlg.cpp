// SystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemDlg.h"
#include "afxdialogex.h"


// SystemDlg dialog

IMPLEMENT_DYNAMIC(SystemDlg, CDialogEx)

SystemDlg::SystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

SystemDlg::~SystemDlg()
{
}

void SystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SYSTEM, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(SystemDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SYSTEM, &SystemDlg::OnTcnSelchangeTabSystem)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// SystemDlg message handlers


void SystemDlg::OnSize(UINT nType, int cx, int cy)
{

	if(m_tabCtrl.GetSafeHwnd())
	{

		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}


	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL SystemDlg::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	//Insert tab ctrl
	CString m_strMessage;
	m_tabSystemHome.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SYSTEM_HOME);
	m_tabSystemHome.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabSystemHome);

	m_tabSystemBackup.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SYSTEM_BACKUP);
	m_tabSystemBackup.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabSystemBackup);

	m_tabSystemSysInformation.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SYSTEM_SYSTEM_INFORMATION);
	m_tabSystemSysInformation.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabSystemSysInformation);

	m_tabSystemShutdown.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SYSTEM_SHUTDOWN);
	m_tabSystemShutdown.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabSystemShutdown);

	
	//create dlg
	m_SystemBackup.Create(IDD_DIALOG_SYSTEM_BACKUP, this);
	m_SystemHome.Create(IDD_DIALOG_SYSTEM_HOME, this);
	m_SystemShutdown.Create(IDD_DIALOG_SYSTEM_SHUTDOWN, this);
	m_SystemSysInformation.Create(IDD_DIALOG_SYSTEM_SYSINFOMATION, this);

	m_dPointer[0] = &m_SystemHome;
	m_dPointer[1] = &m_SystemBackup ;
	m_dPointer[2] = &m_SystemSysInformation ;
	m_dPointer[3] = &m_SystemShutdown;


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}




void SystemDlg::ShowTabNumber(int number)
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


void SystemDlg::OnTcnSelchangeTabSystem(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());

	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);
	*pResult = 0;
}


void SystemDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void SystemDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void SystemDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
