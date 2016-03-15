// CenticFirewallRuntime.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "CenticFirewallRuntime.h"
#include "afxdialogex.h"


// CenticFirewallRuntime dialog

IMPLEMENT_DYNAMIC(CenticFirewallRuntime, CDialogEx)

CenticFirewallRuntime::CenticFirewallRuntime(CWnd* pParent /*=NULL*/)
	: CDialogEx(CenticFirewallRuntime::IDD, pParent)
	, m_connection(_T(""))
	, m_traffic(_T(""))
{

}

CenticFirewallRuntime::~CenticFirewallRuntime()
{
	//KillTimer(TIMER_IDEVENT_DEFAULT);
}

void CenticFirewallRuntime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONNECTION_RUNTIME, m_connection);
	DDX_Text(pDX, IDC_EDIT_TRAFFIC_RUNTIME, m_traffic);
}


BEGIN_MESSAGE_MAP(CenticFirewallRuntime, CDialogEx)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CenticFirewallRuntime message handlers


void CenticFirewallRuntime::OnSize(UINT nType, int cx, int cy)
{
	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void CenticFirewallRuntime::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(FALSE);
	//CDialogEx::OnOK();
}


BOOL CenticFirewallRuntime::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CenticFirewallRuntime::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		//TRACE(L"CenticFirewallRuntime::OnTimer\n");
		//check connection is connected, get in/out speed
		UpdateRuntime();

	}
	CDialogEx::OnTimer(nIDEvent);
}


void CenticFirewallRuntime::StartTimerInfo(bool isStart)
{
	if(isStart)
		SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
	else
		KillTimer(TIMER_IDEVENT_DEFAULT);
}


void CenticFirewallRuntime::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}


void CenticFirewallRuntime::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}



void CenticFirewallRuntime::UpdateRuntime(void)
{

	if(ctSoapEngine.getRuntimeInfo(&m_runtimeInfo)){
		m_connection.Format(_T("connected"));
		m_traffic.Format(_T("In: %0.1f kbps, Out: %0.1f kbps"), m_runtimeInfo.inSpeed, m_runtimeInfo.outSpeed);
		
	}else{
		m_connection.Format(_T("disconnect"));
		m_traffic.Format(_T("---"));
	}

	UpdateData(FALSE);
}
