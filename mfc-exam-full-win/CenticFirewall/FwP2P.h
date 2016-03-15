#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// FwP2P dialog

class FwP2P : public CDialogEx
{
	DECLARE_DYNAMIC(FwP2P)

public:
	FwP2P(CWnd* pParent = NULL);   // standard constructor
	virtual ~FwP2P();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL_P2P };

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
