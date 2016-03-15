// StatusSslVpn.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusSslVpn.h"
#include "afxdialogex.h"


// StatusSslVpn dialog

IMPLEMENT_DYNAMIC(StatusSslVpn, CDialogEx)

StatusSslVpn::StatusSslVpn(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusSslVpn::IDD, pParent)
{

}

StatusSslVpn::~StatusSslVpn()
{
}

void StatusSslVpn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StatusSslVpn, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// StatusSslVpn message handlers


void StatusSslVpn::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL StatusSslVpn::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusSslVpn::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
