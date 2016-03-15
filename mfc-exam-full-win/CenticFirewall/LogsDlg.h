#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

#include "LogsFwLoggraphCountry.h"
#include "LogsFwLoggraphIP.h"
#include "LogsFwLoggraphPort.h"
#include "LogsFwLogs.h"
#include "LogsIDS.h"
#include "LogsProxyLogs.h"
#include "LogsProxyReports.h"
#include "LogsSettings.h"
#include "LogsSummary.h"
#include "LogsSystem.h"
#include "LogsURLFilter.h"

#include "dlg_para.h"
#include "centic_wm.h"

// LogsDlg dialog

class LogsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogsDlg)

public:
	LogsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();


	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabLogsFwLoggraphCountry;
	TCITEM m_tabLogsFwLoggraphIP;
	TCITEM m_tabLogsFwLoggraphPort;
	TCITEM m_tabLogsFwLogs;
	TCITEM m_tabLogsIDS;
	TCITEM m_tabLogsProxyLogs;
	TCITEM m_tabLogsProxyReports;
	TCITEM m_tabLogsSettings;
	TCITEM m_tabLogsSummary;
	TCITEM m_tabLogsSystem;
	TCITEM m_tabLogsURLFilter;

	LogsFwLoggraphCountry m_LogsFwLoggraphCountry;
	LogsFwLoggraphIP m_LogsFwLoggraphIP;
	LogsFwLoggraphPort m_LogsFwLoggraphPort;
	LogsFwLogs m_LogsFwLogs;
	LogsIDS m_LogsIDS;
	LogsProxyLogs m_LogsProxyLogs;
	LogsProxyReports m_LogsProxyReports;
	LogsSettings m_LogsSettings;
	LogsSummary m_LogsSummary;
	LogsSystem m_LogsSystem;
	LogsURLFilter m_LogsURLFilter;

	CDialog *m_dPointer[NUMBER_OF_LOGS_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabLogs(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
