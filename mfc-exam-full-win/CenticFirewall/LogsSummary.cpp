// LogsSummary.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsSummary.h"
#include "afxdialogex.h"


// LogsSummary dialog

IMPLEMENT_DYNAMIC(LogsSummary, CDialogEx)

LogsSummary::LogsSummary(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsSummary::IDD, pParent)
{

}

LogsSummary::~LogsSummary()
{
}

void LogsSummary::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsSummary, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsSummary message handlers


BOOL LogsSummary::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsSummary::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsSummary::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
