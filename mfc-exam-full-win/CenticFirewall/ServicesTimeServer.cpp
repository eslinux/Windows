// ServicesTimeServer.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "ServicesTimeServer.h"
#include "afxdialogex.h"


// ServicesTimeServer dialog

IMPLEMENT_DYNAMIC(ServicesTimeServer, CDialogEx)

ServicesTimeServer::ServicesTimeServer(CWnd* pParent /*=NULL*/)
	: CDialogEx(ServicesTimeServer::IDD, pParent)
{

}

ServicesTimeServer::~ServicesTimeServer()
{
}

void ServicesTimeServer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServicesTimeServer, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ServicesTimeServer message handlers


void ServicesTimeServer::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL ServicesTimeServer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ServicesTimeServer::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}
