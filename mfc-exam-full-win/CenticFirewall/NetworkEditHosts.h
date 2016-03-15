#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkEditHosts dialog

class NetworkEditHosts : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkEditHosts)

public:
	NetworkEditHosts(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkEditHosts();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_EDITHOSTS };

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
