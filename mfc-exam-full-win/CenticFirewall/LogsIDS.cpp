// LogsIDS.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsIDS.h"
#include "afxdialogex.h"


// LogsIDS dialog

IMPLEMENT_DYNAMIC(LogsIDS, CDialogEx)

LogsIDS::LogsIDS(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsIDS::IDD, pParent)
{

}

LogsIDS::~LogsIDS()
{
}

void LogsIDS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LogsIDS, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// LogsIDS message handlers


BOOL LogsIDS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LogsIDS::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void LogsIDS::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
