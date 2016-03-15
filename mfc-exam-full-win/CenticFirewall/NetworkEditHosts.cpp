// NetworkEditHosts.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkEditHosts.h"
#include "afxdialogex.h"


// NetworkEditHosts dialog

IMPLEMENT_DYNAMIC(NetworkEditHosts, CDialogEx)

NetworkEditHosts::NetworkEditHosts(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkEditHosts::IDD, pParent)
{

}

NetworkEditHosts::~NetworkEditHosts()
{
}

void NetworkEditHosts::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkEditHosts, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkEditHosts message handlers


BOOL NetworkEditHosts::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkEditHosts::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void NetworkEditHosts::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
