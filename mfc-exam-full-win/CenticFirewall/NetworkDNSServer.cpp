// NetworkDNSServer.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkDNSServer.h"
#include "afxdialogex.h"


// NetworkDNSServer dialog

IMPLEMENT_DYNAMIC(NetworkDNSServer, CDialogEx)

NetworkDNSServer::NetworkDNSServer(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkDNSServer::IDD, pParent)
{

}

NetworkDNSServer::~NetworkDNSServer()
{
}

void NetworkDNSServer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkDNSServer, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkDNSServer message handlers


void NetworkDNSServer::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL NetworkDNSServer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkDNSServer::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
