#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// ServicesIPSecVPN dialog

class ServicesIPSecVPN : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesIPSecVPN)

public:
	ServicesIPSecVPN(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesIPSecVPN();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES_IPSECVPN };

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
