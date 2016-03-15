#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// FwGroups dialog

class FwGroups : public CDialogEx
{
	DECLARE_DYNAMIC(FwGroups)

public:
	FwGroups(CWnd* pParent = NULL);   // standard constructor
	virtual ~FwGroups();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL_GROUPS };

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
