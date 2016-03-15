#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsFwLoggraphCountry dialog

class LogsFwLoggraphCountry : public CDialogEx
{
	DECLARE_DYNAMIC(LogsFwLoggraphCountry)

public:
	LogsFwLoggraphCountry(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsFwLoggraphCountry();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_FWLOGGRAPHCOUNTRY };

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
