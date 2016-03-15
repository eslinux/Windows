// NetworkURLFilter.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "NetworkURLFilter.h"
#include "afxdialogex.h"


// NetworkURLFilter dialog

IMPLEMENT_DYNAMIC(NetworkURLFilter, CDialogEx)

NetworkURLFilter::NetworkURLFilter(CWnd* pParent /*=NULL*/)
	: CDialogEx(NetworkURLFilter::IDD, pParent)
{

}

NetworkURLFilter::~NetworkURLFilter()
{
}

void NetworkURLFilter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NetworkURLFilter, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// NetworkURLFilter message handlers


BOOL NetworkURLFilter::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NetworkURLFilter::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void NetworkURLFilter::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
