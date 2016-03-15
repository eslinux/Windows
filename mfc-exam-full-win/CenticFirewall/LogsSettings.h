#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsSettings dialog

class LogsSettings : public CDialogEx
{
	DECLARE_DYNAMIC(LogsSettings)

public:
	LogsSettings(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsSettings();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
