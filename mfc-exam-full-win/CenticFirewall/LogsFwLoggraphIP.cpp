// LogsFwLoggraphIP.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsFwLoggraphIP.h"
#include "afxdialogex.h"


// LogsFwLoggraphIP dialog

IMPLEMENT_DYNAMIC(LogsFwLoggraphIP, CDialogEx)

LogsFwLoggraphIP::LogsFwLoggraphIP(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsFwLoggraphIP::IDD, pParent)
{

}

LogsFwLoggraphIP::~LogsFwLoggraphIP()
{
}

void LogsFwLoggraphIP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsFwLoggraphIP, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsFwLoggraphIP message handlers


BOOL LogsFwLoggraphIP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsFwLoggraphIP::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsFwLoggraphIP::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
