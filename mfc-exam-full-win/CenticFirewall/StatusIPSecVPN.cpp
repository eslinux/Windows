// StatusIPSecVPN.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusIPSecVPN.h"
#include "afxdialogex.h"


// StatusIPSecVPN dialog

IMPLEMENT_DYNAMIC(StatusIPSecVPN, CDialogEx)

StatusIPSecVPN::StatusIPSecVPN(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusIPSecVPN::IDD, pParent)
{

}

StatusIPSecVPN::~StatusIPSecVPN()
{
}

void StatusIPSecVPN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StatusIPSecVPN, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// StatusIPSecVPN message handlers


void StatusIPSecVPN::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL StatusIPSecVPN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusIPSecVPN::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
