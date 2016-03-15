#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsProxyReports dialog

class LogsProxyReports : public CDialogEx
{
	DECLARE_DYNAMIC(LogsProxyReports)

public:
	LogsProxyReports(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsProxyReports();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_PROXY_REPORTS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
};
