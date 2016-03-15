// StatusNetTraffic.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusNetTraffic.h"
#include "afxdialogex.h"


// StatusNetTraffic dialog

IMPLEMENT_DYNAMIC(StatusNetTraffic, CDialogEx)

StatusNetTraffic::StatusNetTraffic(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusNetTraffic::IDD, pParent)
{

}

StatusNetTraffic::~StatusNetTraffic()
{
}

void StatusNetTraffic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StatusNetTraffic, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// StatusNetTraffic message handlers


BOOL StatusNetTraffic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusNetTraffic::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void StatusNetTraffic::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void StatusNetTraffic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}
