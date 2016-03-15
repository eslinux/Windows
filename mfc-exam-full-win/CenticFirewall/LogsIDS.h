#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// LogsIDS dialog

class LogsIDS : public CDialogEx
{
	DECLARE_DYNAMIC(LogsIDS)

public:
	LogsIDS(CWnd* pParent = NULL);   // standard constructor
	virtual ~LogsIDS();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGS_IDS };

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
