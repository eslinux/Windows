#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// StatusNetTraffic dialog

class StatusNetTraffic : public CDialogEx
{
	DECLARE_DYNAMIC(StatusNetTraffic)

public:
	StatusNetTraffic(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusNetTraffic();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_NETTRAFFIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	afx_msg void OnPaint();
};
