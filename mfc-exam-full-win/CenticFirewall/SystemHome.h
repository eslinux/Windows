#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "quicklist.h"


// SystemHome dialog

class SystemHome : public CDialogEx
{
	DECLARE_DYNAMIC(SystemHome)

public:
	SystemHome(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemHome();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM_HOME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	

public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();

	//vector<CSampleData> m_data;
	CQuickList m_netInterfaceList;
	CQuickList m_lanInterfaceList;
	afx_msg LRESULT OnGetNetListItem(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetLanListItem(WPARAM wParam, LPARAM lParam);

	void UpdateList(void);
	afx_msg void OnPaint();
	NetInterface_t m_ifList;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
