// LogsSystem.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsSystem.h"
#include "afxdialogex.h"


// LogsSystem dialog

IMPLEMENT_DYNAMIC(LogsSystem, CDialogEx)

LogsSystem::LogsSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsSystem::IDD, pParent)
{

}

LogsSystem::~LogsSystem()
{
}

void LogsSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsSystem, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsSystem message handlers


void LogsSystem::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsSystem::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsSystem::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
