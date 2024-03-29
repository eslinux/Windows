#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// FwGeoIP dialog

class FwGeoIP : public CDialogEx
{
	DECLARE_DYNAMIC(FwGeoIP)

public:
	FwGeoIP(CWnd* pParent = NULL);   // standard constructor
	virtual ~FwGeoIP();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL_GEOIP };

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
