// SystemShutdown.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemShutdown.h"
#include "afxdialogex.h"


// SystemShutdown dialog

IMPLEMENT_DYNAMIC(SystemShutdown, CDialogEx)

SystemShutdown::SystemShutdown(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemShutdown::IDD, pParent)
{

}

SystemShutdown::~SystemShutdown()
{
}

void SystemShutdown::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SystemShutdown, CDialogEx)
	ON_WM_SIZE()	
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &SystemShutdown::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_REBOOT, &SystemShutdown::OnBnClickedButtonReboot)
	ON_BN_CLICKED(IDC_BUTTON_SHUTDOWN, &SystemShutdown::OnBnClickedButtonShutdown)
END_MESSAGE_MAP()


// SystemShutdown message handlers


void SystemShutdown::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL SystemShutdown::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void SystemShutdown::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}



//EVENT_SHUTDOWN = 0, EVENT_REBOOT = 1, EVENT_LOGOUT = 2
void SystemShutdown::OnBnClickedButtonLogout()
{
	// TODO: Add your control notification handler code here
	if(ctSoapEngine.SysShutdownHandle(EVENT_LOGOUT)){

	}else{

	}
}


void SystemShutdown::OnBnClickedButtonReboot()
{
	// TODO: Add your control notification handler code here
	if(ctSoapEngine.SysShutdownHandle(EVENT_REBOOT)){

	}else{

	}
}


void SystemShutdown::OnBnClickedButtonShutdown()
{
	// TODO: Add your control notification handler code here
	if(ctSoapEngine.SysShutdownHandle(EVENT_SHUTDOWN)){

	}else{

	}
}
