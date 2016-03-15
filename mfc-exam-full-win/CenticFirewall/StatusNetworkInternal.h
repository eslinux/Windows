#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "GraphClass.h"
#include "afxwin.h"
#include "colorstatic.h"


// StatusNetworkInternal dialog

class StatusNetworkInternal : public CDialogEx
{
	DECLARE_DYNAMIC(StatusNetworkInternal)

public:
	StatusNetworkInternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusNetworkInternal();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_NETWORK_INTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
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
