// LogsFwLogs.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsFwLogs.h"
#include "afxdialogex.h"


// LogsFwLogs dialog

IMPLEMENT_DYNAMIC(LogsFwLogs, CDialogEx)

LogsFwLogs::LogsFwLogs(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsFwLogs::IDD, pParent)
{

}

LogsFwLogs::~LogsFwLogs()
{
}

void LogsFwLogs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsFwLogs, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsFwLogs message handlers


void LogsFwLogs::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsFwLogs::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsFwLogs::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
