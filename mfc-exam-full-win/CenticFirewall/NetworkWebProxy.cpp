// NetworkWebProxy.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkWebProxy.h"
#include "afxdialogex.h"


// NetworkWebProxy dialog

IMPLEMENT_DYNAMIC(NetworkWebProxy, CDialogEx)

NetworkWebProxy::NetworkWebProxy(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkWebProxy::IDD, pParent)
{

}

NetworkWebProxy::~NetworkWebProxy()
{
}

void NetworkWebProxy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkWebProxy, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkWebProxy message handlers


void NetworkWebProxy::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL NetworkWebProxy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkWebProxy::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
