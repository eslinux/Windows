#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// FwRules dialog

class FwRules : public CDialogEx
{
	DECLARE_DYNAMIC(FwRules)

public:
	FwRules(CWnd* pParent = NULL);   // standard constructor
	virtual ~FwRules();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL_RULES };

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
