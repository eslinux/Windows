// ServicesIDS.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesIDS.h"
#include "afxdialogex.h"


// ServicesIDS dialog

IMPLEMENT_DYNAMIC(ServicesIDS, CDialogEx)

ServicesIDS::ServicesIDS(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesIDS::IDD, pParent)
{

}

ServicesIDS::~ServicesIDS()
{
}

void ServicesIDS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesIDS, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesIDS message handlers


void ServicesIDS::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL ServicesIDS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesIDS::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
