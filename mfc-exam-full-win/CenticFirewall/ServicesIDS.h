#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// ServicesIDS dialog

class ServicesIDS : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesIDS)

public:
	ServicesIDS(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesIDS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES_IDS };

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
