// LogsProxyReports.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsProxyReports.h"
#include "afxdialogex.h"


// LogsProxyReports dialog

IMPLEMENT_DYNAMIC(LogsProxyReports, CDialogEx)

LogsProxyReports::LogsProxyReports(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsProxyReports::IDD, pParent)
{

}

LogsProxyReports::~LogsProxyReports()
{
}

void LogsProxyReports::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsProxyReports, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsProxyReports message handlers


BOOL LogsProxyReports::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsProxyReports::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsProxyReports::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
