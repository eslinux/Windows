#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// ServicesQoS dialog

class ServicesQoS : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesQoS)

public:
	ServicesQoS(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesQoS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES_QOS };

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
