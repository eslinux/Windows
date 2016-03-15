#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// StatusSslVpn dialog

class StatusSslVpn : public CDialogEx
{
	DECLARE_DYNAMIC(StatusSslVpn)

public:
	StatusSslVpn(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusSslVpn();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_SSL_VPN };

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
