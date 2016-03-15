#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

#include "FwGeoIP.h"
#include "FwGroups.h"
#include "FwOptions.h"
#include "FwP2P.h"
#include "FwRules.h"

#include "dlg_para.h"
#include "centic_wm.h"


// FirewallDlg dialog

class FirewallDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FirewallDlg)

public:
	FirewallDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FirewallDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_FIREWALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();

	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabFwGeoIP;
	TCITEM m_tabFwGroups;
	TCITEM m_tabFwOptions;
	TCITEM m_tabFwP2P;
	TCITEM m_tabFwRules;

	FwGeoIP m_FwGeoIP;
	FwGroups m_FwGroups;
	FwOptions m_FwOptions;
	FwP2P m_FwP2P;
	FwRules m_FwRules;

	CDialog *m_dPointer[NUMBER_OF_FIREWALL_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabFirewall(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
