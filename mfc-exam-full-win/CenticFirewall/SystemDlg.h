#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

#include "SystemBackup.h"
#include "SystemHome.h"
#include "SystemShutdown.h"
#include "SystemSysInformation.h"

#include "dlg_para.h"
#include "centic_wm.h"

// SystemDlg dialog

class SystemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SystemDlg)

public:
	SystemDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();

	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabSystemBackup;
	TCITEM m_tabSystemHome;
	TCITEM m_tabSystemShutdown;
	TCITEM m_tabSystemSysInformation;

	SystemBackup m_SystemBackup;
	SystemHome m_SystemHome;
	SystemShutdown m_SystemShutdown;
	SystemSysInformation m_SystemSysInformation;

	CDialog *m_dPointer[NUMBER_OF_SYSTEM_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabSystem(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
