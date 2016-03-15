#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "GraphClass.h"
#include "afxwin.h"
#include "ColorStatic.h"


// StatusNetworkExternal dialog

class StatusNetworkExternal : public CDialogEx
{
	DECLARE_DYNAMIC(StatusNetworkExternal)

public:
	StatusNetworkExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusNetworkExternal();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_NETWORK_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeComboGraphMode();

	NetworkData_t m_networkData;	
	CComboBox m_graphTime;
	GraphClass m_graphTool;

	CString m_incomeMax;
	CString m_incomeAvg;
	CString m_incomeMin;
	CString m_incomeCurrent;
	CString m_outcomeMax;
	CString m_outcomeAvg;
	CString m_outcomeMin;
	CString m_outcomeCurrent;

	CColorStatic m_greenColor;
	CColorStatic m_redColor;
};
