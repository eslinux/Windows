
// calcSSLgSOAPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calcSSLgSOAP.h"
#include "calcSSLgSOAPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcSSLgSOAPDlg dialog




CcalcSSLgSOAPDlg::CcalcSSLgSOAPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalcSSLgSOAPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcSSLgSOAPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalcSSLgSOAPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

#include "calc++/soapcalcProxy.h"
#include "calc++/calc.nsmap"
#include "stdio.h"
const char server[] = "https://10.49.46.201:2012";
// CcalcSSLgSOAPDlg message handlers

BOOL CcalcSSLgSOAPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

#if 1
	double a = 0, b = 0, result = 0;
	a = 7.0;
	b = 3.0;


	calcProxy calc;
	calc.soap_endpoint = server;

#ifdef WITH_OPENSSL

	soap_ssl_init();

	if (soap_ssl_client_context(&calc,
								//SOAP_SSL_DEFAULT,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK,	/* use SOAP_SSL_DEFAULT in production code, we don't want the host name checks since these will change from machine to machine */
								NULL, 		/* keyfile: required only when client must authenticate to server (see SSL docs on how to obtain this file) */
								NULL, 		/* password to read the keyfile */
								"cacert.pem",	/* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
								NULL,		/* optional capath to directory with trusted certificates */
								NULL		/* if randfile!=NULL: use a file with random data to seed randomness */
								))
	{
		TRACE(traceAppMsg, 0, "soap_ssl_client_context FAIL \n");
		soap_print_fault(&calc, stderr);		
		return TRUE;
	}

	

	calc.connect_timeout = 60;	/* try to connect for 1 minute */
	calc.send_timeout = calc.recv_timeout = 30;	/* if I/O stalls, then timeout after 30 seconds */

#endif

	TRACE(traceAppMsg, 0, "calc.add(a, b, &result) \n");
	calc.add(a, b, &result);
		
	if (calc.error){		
		TRACE(traceAppMsg, 0, "soap_stream_fault \n");
	}else{		
		TRACE(traceAppMsg, 0, "result = %g\n", result);
		CString ret;
		ret.Format(_T("result 7 + 3 = %g \n"), result);
		MessageBox(ret);
	}

#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalcSSLgSOAPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalcSSLgSOAPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalcSSLgSOAPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

