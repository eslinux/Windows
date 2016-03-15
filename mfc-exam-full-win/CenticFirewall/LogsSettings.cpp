// LogsSettings.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsSettings.h"
#include "afxdialogex.h"


// LogsSettings dialog

IMPLEMENT_DYNAMIC(LogsSettings, CDialogEx)

LogsSettings::LogsSettings(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsSettings::IDD, pParent)
{

}

LogsSettings::~LogsSettings()
{
}

void LogsSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsSettings, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsSettings message handlers


void LogsSettings::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsSettings::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsSettings::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
