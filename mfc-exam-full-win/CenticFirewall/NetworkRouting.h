#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// NetworkRouting dialog

class NetworkRouting : public CDialogEx
{
	DECLARE_DYNAMIC(NetworkRouting)

public:
	NetworkRouting(CWnd* pParent = NULL);   // standard constructor
	virtual ~NetworkRouting();

// Dialog Data
	enum { IDD = IDD_DIALOG_NETWORK_ROUTING };

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
