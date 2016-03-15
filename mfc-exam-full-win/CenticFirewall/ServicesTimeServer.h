#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

// ServicesTimeServer dialog

class ServicesTimeServer : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesTimeServer)

public:
	ServicesTimeServer(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesTimeServer();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES_TIMESERVER };

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
