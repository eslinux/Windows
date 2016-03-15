#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsProxyLogs dialog

class LogsProxyLogs : public CDialogEx
{
	DECLARE_DYNAMIC(LogsProxyLogs)

public:
	LogsProxyLogs(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsProxyLogs();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_PROXY_LOGS };

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
