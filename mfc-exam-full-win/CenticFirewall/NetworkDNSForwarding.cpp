// NetworkDNSForwarding.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkDNSForwarding.h"
#include "afxdialogex.h"


// NetworkDNSForwarding dialog

IMPLEMENT_DYNAMIC(NetworkDNSForwarding, CDialogEx)

NetworkDNSForwarding::NetworkDNSForwarding(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkDNSForwarding::IDD, pParent)
{

}

NetworkDNSForwarding::~NetworkDNSForwarding()
{
}

void NetworkDNSForwarding::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkDNSForwarding, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkDNSForwarding message handlers


BOOL NetworkDNSForwarding::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkDNSForwarding::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void NetworkDNSForwarding::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
