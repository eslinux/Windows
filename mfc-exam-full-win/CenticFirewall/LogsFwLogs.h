#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsFwLogs dialog

class LogsFwLogs : public CDialogEx
{
	DECLARE_DYNAMIC(LogsFwLogs)

public:
	LogsFwLogs(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsFwLogs();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_FW_LOGS };

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
