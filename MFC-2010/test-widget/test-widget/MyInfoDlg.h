#pragma once
#include "resource.h"

// MyInfoDlg dialog

class MyInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyInfoDlg)

public:
	MyInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyInfoDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_sName;
//	CString m_iAge;
	int m_iAge;
};
