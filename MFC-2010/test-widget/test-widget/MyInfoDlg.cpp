// MyInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInfoDlg.h"
#include "afxdialogex.h"


// MyInfoDlg dialog

IMPLEMENT_DYNAMIC(MyInfoDlg, CDialogEx)

MyInfoDlg::MyInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyInfoDlg::IDD, pParent)
	, m_sName(_T(""))
	, m_iAge(0)
{

	m_iAge = 0;
}

MyInfoDlg::~MyInfoDlg()
{
}

void MyInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	//  DDX_Text(pDX, IDC_EDIT2, m_iAge);
	DDX_Text(pDX, IDC_EDIT2, m_iAge);
}


BEGIN_MESSAGE_MAP(MyInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// MyInfoDlg message handlers
