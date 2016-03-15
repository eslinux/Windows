#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkDHCPServer dialog

class NetworkDHCPServer : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkDHCPServer)

public:
	NetworkDHCPServer(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkDHCPServer();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_DHCPSERVER };

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
