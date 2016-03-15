#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsURLFilter dialog

class LogsURLFilter : public CDialogEx
{
	DECLARE_DYNAMIC(LogsURLFilter)

public:
	LogsURLFilter(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsURLFilter();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_URLFILTER };

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
