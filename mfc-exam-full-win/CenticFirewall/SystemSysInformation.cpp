// SystemSysInformation.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemSysInformation.h"
#include "afxdialogex.h"


// SystemSysInformation dialog

IMPLEMENT_DYNAMIC(SystemSysInformation, CDialogEx)

SystemSysInformation::SystemSysInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemSysInformation::IDD, pParent)
	, m_centicVersion(_T(""))
	, m_cpu(_T(""))
	, m_memory(_T(""))
{

}

SystemSysInformation::~SystemSysInformation()
{
}

void SystemSysInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CENTIC_FIREWALL_VERSION, m_centicVersion);
	DDX_Text(pDX, IDC_EDIT_CPU_ARCH, m_cpu);
	DDX_Text(pDX, IDC_EDIT_MEMORY, m_memory);
}


BEGIN_MESSAGE_MAP(SystemSysInformation, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// SystemSysInformation message handlers


BOOL SystemSysInformation::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void SystemSysInformation::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void SystemSysInformation::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void SystemSysInformation::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	SysInfo_t ret;
	if(ctSoapEngine.getSysSysInfo(&ret)){
		m_centicVersion = CString(ret.ctfw_version.c_str());
		m_cpu = CString(ret.cpu.c_str());
		m_memory = CString(ret.memory.c_str());

	}else{
		m_centicVersion = _T("---");
		m_cpu  = _T("---");
		m_memory = _T("---");

	}

	UpdateData(FALSE);
}
