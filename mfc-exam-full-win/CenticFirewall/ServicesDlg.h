#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"

#include "ServicesDynamicDNS.h"
#include "ServicesIDS.h"
#include "ServicesIPSecVPN.h"
#include "ServicesQoS.h"
#include "ServicesSslVpn.h"
#include "ServicesTimeServer.h"

#include "dlg_para.h"
#include "centic_wm.h"


// ServicesDlg dialog

class ServicesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ServicesDlg)

public:
	ServicesDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServicesDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SERVICES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();


	CTabCtrl m_tabCtrl;//TCITEM tab
	TCITEM m_tabServicesDynamicDNS;
	TCITEM m_tabServicesIDS;
	TCITEM m_tabServicesIPSecVPN;
	TCITEM m_tabServicesQoS;
	TCITEM m_tabServicesSslVpn;
	TCITEM m_tabServicesTimeServer;

	ServicesDynamicDNS m_ServicesDynamicDNS;
	ServicesIDS m_ServicesIDS;
	ServicesIPSecVPN m_ServicesIPSecVPN;
	ServicesQoS m_ServicesQoS;
	ServicesSslVpn m_ServicesSslVpn;
	ServicesTimeServer m_ServicesTimeServer;

	CDialog *m_dPointer[NUMBER_OF_SERVICES_TAB];
	void ShowTabNumber(int number);
	int m_cur_subtab;
	afx_msg void OnTcnSelchangeTabServices(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
