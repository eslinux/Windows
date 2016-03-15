// ServicesQoS.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesQoS.h"
#include "afxdialogex.h"


// ServicesQoS dialog

IMPLEMENT_DYNAMIC(ServicesQoS, CDialogEx)

ServicesQoS::ServicesQoS(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesQoS::IDD, pParent)
{

}

ServicesQoS::~ServicesQoS()
{
}

void ServicesQoS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesQoS, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesQoS message handlers


void ServicesQoS::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL ServicesQoS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesQoS::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
