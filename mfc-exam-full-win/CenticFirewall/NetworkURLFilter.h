#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkURLFilter dialog

class NetworkURLFilter : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkURLFilter)

public:
	NetworkURLFilter(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkURLFilter();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_URLFILTER };

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
