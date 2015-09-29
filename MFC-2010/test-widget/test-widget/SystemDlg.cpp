// SystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test-widget.h"
#include "SystemDlg.h"
#include "afxdialogex.h"


// SystemDlg dialog

IMPLEMENT_DYNAMIC(SystemDlg, CDialogEx)

SystemDlg::SystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemDlg::IDD, pParent)
{

}

SystemDlg::~SystemDlg()
{
}

void SystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SystemDlg, CDialogEx)
END_MESSAGE_MAP()


// SystemDlg message handlers
