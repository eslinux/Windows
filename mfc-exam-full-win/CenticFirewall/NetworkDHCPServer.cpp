// NetworkDHCPServer.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkDHCPServer.h"
#include "afxdialogex.h"


// NetworkDHCPServer dialog

IMPLEMENT_DYNAMIC(NetworkDHCPServer, CDialogEx)

NetworkDHCPServer::NetworkDHCPServer(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkDHCPServer::IDD, pParent)
{

}

NetworkDHCPServer::~NetworkDHCPServer()
{
}

void NetworkDHCPServer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkDHCPServer, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkDHCPServer message handlers


BOOL NetworkDHCPServer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkDHCPServer::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void NetworkDHCPServer::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
