#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// SystemShutdown dialog

class SystemShutdown : public CDialogEx
{
	DECLARE_DYNAMIC(SystemShutdown)

public:
	SystemShutdown(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemShutdown();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM_SHUTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg void OnBnClickedButtonLogout();
	afx_msg void OnBnClickedButtonReboot();
	afx_msg void OnBnClickedButtonShutdown();
};
