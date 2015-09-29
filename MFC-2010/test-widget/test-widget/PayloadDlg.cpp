// PayloadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test-widget.h"
#include "PayloadDlg.h"
#include "afxdialogex.h"


// PayloadDlg dialog

IMPLEMENT_DYNAMIC(PayloadDlg, CDialogEx)

PayloadDlg::PayloadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PayloadDlg::IDD, pParent)
{

}

PayloadDlg::~PayloadDlg()
{
}

void PayloadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PayloadDlg, CDialogEx)
END_MESSAGE_MAP()


// PayloadDlg message handlers
