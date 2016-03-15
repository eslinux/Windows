#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "GraphClass.h"
#include "afxwin.h"
#include "colorstatic.h"


// StatusNetworkOther dialog

class StatusNetworkOther : public CDialogEx
{
	DECLARE_DYNAMIC(StatusNetworkOther)

public:
	StatusNetworkOther(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusNetworkOther();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_NETWORK_OTHER };

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

	CString m_inputMax;
	CString m_inputAvg;
	CString m_inputMin;
	CString m_inputCurrent;
	CString m_forwardMax;
	CString m_forwardAvg;
	CString m_forwardMin;
	CString m_forwardCurrent;
	CString m_outputMax;
	CString m_outputAvg;
	CString m_outputMin;
	CString m_outputCurrent;
	
	CColorStatic m_greenColor;
	CColorStatic m_redColor;
	CColorStatic m_blueColor;
};
