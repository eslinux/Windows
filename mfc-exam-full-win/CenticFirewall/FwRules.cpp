// FwRules.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FwRules.h"
#include "afxdialogex.h"


// FwRules dialog

IMPLEMENT_DYNAMIC(FwRules, CDialogEx)

FwRules::FwRules(CWnd* pParent /*=NULL*/)
	: CDialogEx(FwRules::IDD, pParent)
{

}

FwRules::~FwRules()
{
}

void FwRules::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FwRules, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FwRules message handlers


BOOL FwRules::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void FwRules::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void FwRules::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
