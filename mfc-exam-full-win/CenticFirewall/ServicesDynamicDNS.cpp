// ServicesDynamicDNS.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesDynamicDNS.h"
#include "afxdialogex.h"


// ServicesDynamicDNS dialog

IMPLEMENT_DYNAMIC(ServicesDynamicDNS, CDialogEx)

ServicesDynamicDNS::ServicesDynamicDNS(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesDynamicDNS::IDD, pParent)
{

}

ServicesDynamicDNS::~ServicesDynamicDNS()
{
}

void ServicesDynamicDNS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesDynamicDNS, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesDynamicDNS message handlers


BOOL ServicesDynamicDNS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesDynamicDNS::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void ServicesDynamicDNS::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
