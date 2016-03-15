// FwP2P.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "FwP2P.h"
#include "afxdialogex.h"


// FwP2P dialog

IMPLEMENT_DYNAMIC(FwP2P, CDialogEx)

FwP2P::FwP2P(CWnd* pParent /*=NULL*/)
	: CDialogEx(FwP2P::IDD, pParent)
{

}

FwP2P::~FwP2P()
{
}

void FwP2P::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FwP2P, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FwP2P message handlers


BOOL FwP2P::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void FwP2P::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void FwP2P::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
