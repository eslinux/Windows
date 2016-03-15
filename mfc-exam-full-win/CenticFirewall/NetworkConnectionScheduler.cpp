// NetworkConnectionScheduler.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkConnectionScheduler.h"
#include "afxdialogex.h"


// NetworkConnectionScheduler dialog

IMPLEMENT_DYNAMIC(NetworkConnectionScheduler, CDialogEx)

NetworkConnectionScheduler::NetworkConnectionScheduler(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkConnectionScheduler::IDD, pParent)
{

}

NetworkConnectionScheduler::~NetworkConnectionScheduler()
{
}

void NetworkConnectionScheduler::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkConnectionScheduler, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkConnectionScheduler message handlers


void NetworkConnectionScheduler::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL NetworkConnectionScheduler::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkConnectionScheduler::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
