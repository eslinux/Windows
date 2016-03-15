#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// SystemSysInformation dialog

class SystemSysInformation : public CDialogEx
{
	DECLARE_DYNAMIC(SystemSysInformation)

public:
	SystemSysInformation(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemSysInformation();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM_SYSINFOMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	CString m_centicVersion;
	CString m_cpu;
	CString m_memory;
	afx_msg void OnPaint();
};
