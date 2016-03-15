// FwGeoIP.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FwGeoIP.h"
#include "afxdialogex.h"


// FwGeoIP dialog

IMPLEMENT_DYNAMIC(FwGeoIP, CDialogEx)

FwGeoIP::FwGeoIP(CWnd* pParent /*=NULL*/)
	: CDialogEx(FwGeoIP::IDD, pParent)
{

}

FwGeoIP::~FwGeoIP()
{
}

void FwGeoIP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FwGeoIP, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FwGeoIP message handlers


void FwGeoIP::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL FwGeoIP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void FwGeoIP::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
