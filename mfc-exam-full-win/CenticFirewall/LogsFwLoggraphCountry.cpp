// LogsFwLoggraphCountry.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsFwLoggraphCountry.h"
#include "afxdialogex.h"


// LogsFwLoggraphCountry dialog

IMPLEMENT_DYNAMIC(LogsFwLoggraphCountry, CDialogEx)

LogsFwLoggraphCountry::LogsFwLoggraphCountry(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsFwLoggraphCountry::IDD, pParent)
{

}

LogsFwLoggraphCountry::~LogsFwLoggraphCountry()
{
}

void LogsFwLoggraphCountry::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsFwLoggraphCountry, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsFwLoggraphCountry message handlers


void LogsFwLoggraphCountry::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsFwLoggraphCountry::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsFwLoggraphCountry::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
