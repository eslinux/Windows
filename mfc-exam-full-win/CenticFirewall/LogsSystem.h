#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsSystem dialog

class LogsSystem : public CDialogEx
{
	DECLARE_DYNAMIC(LogsSystem)

public:
	LogsSystem(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsSystem();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_SYSTEM };

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
