
// test-widgetDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "systemdlg.h"
#include "pcidlg.h"
#include "payloaddlg.h"
#include "afxdlgs.h"


// CtestwidgetDlg dialog
class CtestwidgetDlg : public CDialogEx
{
// Construction
public:
	CtestwidgetDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTWIDGET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cbMyCombo;
	afx_msg void OnCbnSelchangeCombo1();

	CListBox m_lbMyListBox;
	afx_msg void OnLbnSelchangeList1();

	CScrollBar m_sbMyScrollBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_sbMyHSScrollBar;

	CTabCtrl m_TabCtrl;
	TCITEM PayLoadItem;
	TCITEM PCIItem;
	TCITEM StatsItem;

	void ShowWindowNumber(int number);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);


	PciDlg m_PCIedlg;
	SystemDlg m_Systemdlg;
	PayloadDlg m_Payloaddlg;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	CIPAddressCtrl m_IPAdress;
	CNetAddressCtrl m_NetAddCtrl;
	afx_msg void OnEnChangeNetaddress1();
	CMenu m_MyMenu;
	afx_msg void OnTab1Sub1();
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_ProgressBar;
	CWinThread *m_pThreads;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	CFileDialog m_CfileDialog;
	afx_msg void OnBnClickedButton3();
};
