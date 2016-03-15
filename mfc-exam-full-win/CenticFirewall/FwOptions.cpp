// FwOptions.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FwOptions.h"
#include "afxdialogex.h"


// FwOptions dialog

IMPLEMENT_DYNAMIC(FwOptions, CDialogEx)

FwOptions::FwOptions(CWnd* pParent /*=NULL*/)
	: CDialogEx(FwOptions::IDD, pParent)
{

}

FwOptions::~FwOptions()
{
}

void FwOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FwOptions, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FwOptions message handlers


void FwOptions::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL FwOptions::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void FwOptions::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
