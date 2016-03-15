// ServicesIPSecVPN.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesIPSecVPN.h"
#include "afxdialogex.h"


// ServicesIPSecVPN dialog

IMPLEMENT_DYNAMIC(ServicesIPSecVPN, CDialogEx)

ServicesIPSecVPN::ServicesIPSecVPN(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesIPSecVPN::IDD, pParent)
{

}

ServicesIPSecVPN::~ServicesIPSecVPN()
{
}

void ServicesIPSecVPN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesIPSecVPN, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesIPSecVPN message handlers


BOOL ServicesIPSecVPN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesIPSecVPN::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void ServicesIPSecVPN::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
