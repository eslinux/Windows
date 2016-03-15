#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "dlg_para.h"
#include "centic_wm.h"
#include "c:\users\thanh\documents\visual studio 2010\projects\centicfirewall\centicfirewall\src\gsoapengine\gsoapengine.h"


// CenticFirewallRuntime dialog

class CenticFirewallRuntime : public CDialogEx
{
	DECLARE_DYNAMIC(CenticFirewallRuntime)

public:
	CenticFirewallRuntime(CWnd* pParent = NULL);   // standard constructor
	virtual ~CenticFirewallRuntime();

// Dialog Data
	enum { IDD = IDD_DIALOG_RUNTIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void StartTimerInfo(bool isStart);
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void UpdateRuntime(void);

	CString m_connection;
	CString m_traffic;
	RuntimeInfo_t m_runtimeInfo;
};
