#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// ServicesSslVpn dialog

class ServicesSslVpn : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesSslVpn)

public:
	ServicesSslVpn(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesSslVpn();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES_SSLVPN };

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
