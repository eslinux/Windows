// FwGroups.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FwGroups.h"
#include "afxdialogex.h"


// FwGroups dialog

IMPLEMENT_DYNAMIC(FwGroups, CDialogEx)

FwGroups::FwGroups(CWnd* pParent /*=NULL*/)
	: CDialogEx(FwGroups::IDD, pParent)
{

}

FwGroups::~FwGroups()
{
}

void FwGroups::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FwGroups, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FwGroups message handlers


BOOL FwGroups::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void FwGroups::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void FwGroups::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
