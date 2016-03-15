#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsFwLoggraphIP dialog

class LogsFwLoggraphIP : public CDialogEx
{
	DECLARE_DYNAMIC(LogsFwLoggraphIP)

public:
	LogsFwLoggraphIP(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsFwLoggraphIP();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_FWLOGGRAPHIP };

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
