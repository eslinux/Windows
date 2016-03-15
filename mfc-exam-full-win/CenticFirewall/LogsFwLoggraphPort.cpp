// LogsFwLoggraphPort.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsFwLoggraphPort.h"
#include "afxdialogex.h"


// LogsFwLoggraphPort dialog

IMPLEMENT_DYNAMIC(LogsFwLoggraphPort, CDialogEx)

LogsFwLoggraphPort::LogsFwLoggraphPort(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsFwLoggraphPort::IDD, pParent)
{

}

LogsFwLoggraphPort::~LogsFwLoggraphPort()
{
}

void LogsFwLoggraphPort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsFwLoggraphPort, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsFwLoggraphPort message handlers


BOOL LogsFwLoggraphPort::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsFwLoggraphPort::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsFwLoggraphPort::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
