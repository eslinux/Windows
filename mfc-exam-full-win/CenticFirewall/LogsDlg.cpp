// LogsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LogsDlg.h"
#include "afxdialogex.h"


// LogsDlg dialog

IMPLEMENT_DYNAMIC(LogsDlg, CDialogEx)

LogsDlg::LogsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(LogsDlg::IDD, pParent)
{

	m_cur_subtab = 0;
}

LogsDlg::~LogsDlg()
{
}

void LogsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_LOGS, m_tabCtrl);
}


BEGIN_MESSAGE_MAP(LogsDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_LOGS, &LogsDlg::OnTcnSelchangeTabLogs)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// LogsDlg message handlers


void LogsDlg::OnSize(UINT nType, int cx, int cy)
{
	if(m_tabCtrl.GetSafeHwnd())
	{
		ShowTabNumber(m_tabCtrl.GetCurFocus());
	}

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL LogsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	//Insert tab ctrl
	CString m_strMessage;
	m_tabLogsSummary.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_SUMMARY);
	m_tabLogsSummary.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(0,&m_tabLogsSummary);

	m_tabLogsSettings.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_SETTINGS);
	m_tabLogsSettings.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(1, &m_tabLogsSettings);

	m_tabLogsProxyLogs.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_PROXY_LOGS);
	m_tabLogsProxyLogs.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (2,&m_tabLogsProxyLogs);

	m_tabLogsProxyReports.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_PROXY_REPORTS);
	m_tabLogsProxyReports.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem (3,&m_tabLogsProxyReports);

	m_tabLogsFwLogs.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_FW_LOGS);
	m_tabLogsFwLogs.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(4, &m_tabLogsFwLogs);

	m_tabLogsFwLoggraphIP.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_FW_LOGGRAPH_IP);
	m_tabLogsFwLoggraphIP.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(5, &m_tabLogsFwLoggraphIP);

	m_tabLogsFwLoggraphPort.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_FW_LOGGRAPH_PORT);
	m_tabLogsFwLoggraphPort.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(6, &m_tabLogsFwLoggraphPort);


	m_tabLogsFwLoggraphCountry.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_FW_LOGGRAPH_COUNTRY);
	m_tabLogsFwLoggraphCountry.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(7, &m_tabLogsFwLoggraphCountry);

	m_tabLogsIDS.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_IDS);
	m_tabLogsIDS.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(8, &m_tabLogsIDS);

	m_tabLogsURLFilter.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_URL_FILTER);
	m_tabLogsURLFilter.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(9, &m_tabLogsURLFilter);

	m_tabLogsSystem.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_LOGS_SYSTEM);
	m_tabLogsSystem.pszText = m_strMessage.GetBuffer();
	m_tabCtrl.InsertItem(10, &m_tabLogsSystem);


	//create dlg
	m_LogsFwLoggraphCountry.Create(IDD_DIALOG_LOGS_FWLOGGRAPHCOUNTRY, this);
	m_LogsFwLoggraphIP.Create(IDD_DIALOG_LOGS_FWLOGGRAPHIP, this);
	m_LogsFwLoggraphPort.Create(IDD_DIALOG_LOGS_FWLOGGRAPHPORT, this);
	m_LogsFwLogs.Create(IDD_DIALOG_LOGS_FW_LOGS, this);
	m_LogsIDS.Create(IDD_DIALOG_LOGS_IDS, this);
	m_LogsProxyLogs.Create(IDD_DIALOG_LOGS_PROXY_LOGS, this);
	m_LogsProxyReports.Create(IDD_DIALOG_LOGS_PROXY_REPORTS, this);
	m_LogsSettings.Create(IDD_DIALOG_LOGS_SETTINGS, this);
	m_LogsSummary.Create(IDD_DIALOG_LOGS_SUMMARY, this);
	m_LogsSystem.Create(IDD_DIALOG_LOGS_SYSTEM, this);
	m_LogsURLFilter.Create(IDD_DIALOG_LOGS_URLFILTER, this);


	m_dPointer[0] = &m_LogsSummary;
	m_dPointer[1] = &m_LogsSettings ;
	m_dPointer[2] = &m_LogsProxyLogs ;
	m_dPointer[3] = &m_LogsProxyReports;
	m_dPointer[4] = &m_LogsFwLogs ;
	m_dPointer[5] = &m_LogsFwLoggraphIP ;
	m_dPointer[6] = &m_LogsFwLoggraphPort ;
	m_dPointer[7] = &m_LogsFwLoggraphCountry ;
	m_dPointer[8] = &m_LogsIDS ;
	m_dPointer[9] = &m_LogsURLFilter ;
	m_dPointer[10] = &m_LogsSystem ;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}




void LogsDlg::ShowTabNumber(int number)
{
	CRect mainRect;
	m_tabCtrl.GetWindowRect(mainRect);
	ScreenToClient(&mainRect);


	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);

	TRACE(L"%s subTab %d \n", __FUNCTION__, number);
	m_dPointer[number]->SetWindowPos(&wndTop, 
				mainRect.left + SUB_TAB_OFFSET_LEFT,	
				mainRect.top + SUB_TAB_OFFSET_TOP, 
				mainRect.Width() + SUB_TAB_OFFSET_RIGHT, 
				mainRect.Height() + SUB_TAB_OFFSET_BOTTOM, 
				SWP_SHOWWINDOW);

	m_tabCtrl.SetCurFocus(number);
	m_cur_subtab = number;
}


void LogsDlg::OnTcnSelchangeTabLogs(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	ShowTabNumber(m_tabCtrl.GetCurFocus());
	GetParent()->SendMessage(WM_UPDATE_TABNUMBER_MESSAGE, m_tabCtrl.GetCurFocus(), /*(LPARAM)pStruct*/0);
	*pResult = 0;
}


void LogsDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void LogsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
}


void LogsDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	m_dPointer[m_cur_subtab]->ShowWindow(SW_HIDE);
}
