#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "quicklist.h"
#include <vector>
#include <sstream>
#include <string>

// StatusServices dialog

class StatusServices : public CDialogEx
{
	DECLARE_DYNAMIC(StatusServices)

public:
	StatusServices(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusServices();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_SERVICES };

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

	CQuickList m_servicesTable;
	afx_msg LRESULT OnGetServicesListItem(WPARAM wParam, LPARAM lParam);
	void UpdateList(void);
	StatusServicesList_t m_servicesTableData;

	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
