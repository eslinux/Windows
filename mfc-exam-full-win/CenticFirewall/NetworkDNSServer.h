#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkDNSServer dialog

class NetworkDNSServer : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkDNSServer)

public:
	NetworkDNSServer(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkDNSServer();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_DNSSERVER };

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
