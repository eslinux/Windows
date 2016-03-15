#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// StatusIPSecVPN dialog

class StatusIPSecVPN : public CDialogEx
{
	DECLARE_DYNAMIC(StatusIPSecVPN)

public:
	StatusIPSecVPN(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusIPSecVPN();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_IPSEC_VPN };

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
