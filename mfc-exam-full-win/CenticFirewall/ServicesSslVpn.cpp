// ServicesSslVpn.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesSslVpn.h"
#include "afxdialogex.h"


// ServicesSslVpn dialog

IMPLEMENT_DYNAMIC(ServicesSslVpn, CDialogEx)

ServicesSslVpn::ServicesSslVpn(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesSslVpn::IDD, pParent)
{

}

ServicesSslVpn::~ServicesSslVpn()
{
}

void ServicesSslVpn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesSslVpn, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesSslVpn message handlers


BOOL ServicesSslVpn::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesSslVpn::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void ServicesSslVpn::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
