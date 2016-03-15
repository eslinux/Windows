// LogsProxyLogs.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsProxyLogs.h"
#include "afxdialogex.h"


// LogsProxyLogs dialog

IMPLEMENT_DYNAMIC(LogsProxyLogs, CDialogEx)

LogsProxyLogs::LogsProxyLogs(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsProxyLogs::IDD, pParent)
{

}

LogsProxyLogs::~LogsProxyLogs()
{
}

void LogsProxyLogs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsProxyLogs, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsProxyLogs message handlers


void LogsProxyLogs::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsProxyLogs::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsProxyLogs::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
