#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

#include "StatusConnection.h"
#include "StatusIPSecVPN.h"
#include "StatusNetTraffic.h"
#include "StatusNetworkExternal.h"
#include "StatusNetworkInternal.h"
#include "StatusNetworkOther.h"
#include "StatusServices.h"
#include "StatusSslVpn.h"
#include "StatusSystem.h"

#include "dlg_para.h"
#include "centic_wm.h"


// StatusDlg dialog

class StatusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StatusDlg)

public:
	StatusDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();

	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabStatusConnection;
	TCITEM m_tabStatusIPSecVPN;
	TCITEM m_tabStatusNetTraffic;
	TCITEM m_tabStatusNetworkExternal;
	TCITEM m_tabStatusNetworkInternal;
	TCITEM m_tabStatusNetworkOther;
	TCITEM m_tabStatusServices;
	TCITEM m_tabStatusSslVpn;
	TCITEM m_tabStatusSystem;

	StatusConnection m_StatusConnection;
	StatusIPSecVPN m_StatusIPSecVPN;
	StatusNetTraffic m_StatusNetTraffic;
	StatusNetworkExternal m_StatusNetworkExternal;
	StatusNetworkInternal m_StatusNetworkInternal;
	StatusNetworkOther m_StatusNetworkOther;
	StatusServices m_StatusServices;
	StatusSslVpn m_StatusSslVpn;
	StatusSystem m_StatusSystem;

	CDialog *m_dPointer[NUMBER_OF_STATUS_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabStatus(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
