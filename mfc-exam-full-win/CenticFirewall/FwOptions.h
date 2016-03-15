#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// FwOptions dialog

class FwOptions : public CDialogEx
{
	DECLARE_DYNAMIC(FwOptions)

public:
	FwOptions(CWnd* pParent = NULL);   // standard constructor
	virtual ~FwOptions();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL_OPTIONS };

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
