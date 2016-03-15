// LogsURLFilter.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsURLFilter.h"
#include "afxdialogex.h"


// LogsURLFilter dialog

IMPLEMENT_DYNAMIC(LogsURLFilter, CDialogEx)

LogsURLFilter::LogsURLFilter(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsURLFilter::IDD, pParent)
{

}

LogsURLFilter::~LogsURLFilter()
{
}

void LogsURLFilter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsURLFilter, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsURLFilter message handlers


BOOL LogsURLFilter::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsURLFilter::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsURLFilter::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
