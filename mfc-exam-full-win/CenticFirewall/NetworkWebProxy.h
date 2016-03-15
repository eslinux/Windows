#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkWebProxy dialog

class NetworkWebProxy : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkWebProxy)

public:
	NetworkWebProxy(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkWebProxy();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_WEBPROXY };

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
