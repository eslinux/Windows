#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsFwLoggraphPort dialog

class LogsFwLoggraphPort : public CDialogEx
{
	DECLARE_DYNAMIC(LogsFwLoggraphPort)

public:
	LogsFwLoggraphPort(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsFwLoggraphPort();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_FWLOGGRAPHPORT };

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
