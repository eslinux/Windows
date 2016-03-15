// NetworkRouting.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkRouting.h"
#include "afxdialogex.h"


// NetworkRouting dialog

IMPLEMENT_DYNAMIC(NetworkRouting, CDialogEx)

NetworkRouting::NetworkRouting(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkRouting::IDD, pParent)
{

}

NetworkRouting::~NetworkRouting()
{
}

void NetworkRouting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkRouting, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkRouting message handlers


void NetworkRouting::OnSize(UINT nType, int cx, int cy)
{
		
	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL NetworkRouting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkRouting::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
