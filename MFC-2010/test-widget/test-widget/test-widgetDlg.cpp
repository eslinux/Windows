
// test-widgetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test-widget.h"
#include "test-widgetDlg.h"
#include "afxdialogex.h"

#include "MyInfoDlg.h"

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


// CtestwidgetDlg dialog




CtestwidgetDlg::CtestwidgetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestwidgetDlg::IDD, pParent)
	, m_sohanga(0)
	, m_sohangb(0)
	, m_ketqua(0)
	, m_calculator_function(0)
	, m_enable_calculate(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_calculator_function = 0;
}

void CtestwidgetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cbMyCombo);
	DDX_Control(pDX, IDC_LIST1, m_lbMyListBox);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sbMyScrollBar);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sbMyHSScrollBar);
	DDX_Control(pDX, IDC_TAB1, m_TabCtrl);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IPAdress);
	DDX_Control(pDX, IDC_NETADDRESS1, m_NetAddCtrl);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressBar);
	DDX_Text(pDX, IDC_SOHANGA, m_sohanga);
	DDX_Text(pDX, IDC_SOHANGB, m_sohangb);
	DDX_Text(pDX, IDC_KETQUA, m_ketqua);
	DDX_Radio(pDX, IDC_CALCULATOR_FUNCTION, m_calculator_function);
	DDX_Check(pDX, IDC_ENABLE_CALCULATE, m_enable_calculate);
}

BEGIN_MESSAGE_MAP(CtestwidgetDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CtestwidgetDlg::OnCbnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CtestwidgetDlg::OnLbnSelchangeList1)
//	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CtestwidgetDlg::OnNMThemeChangedScrollbar1)
//ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CtestwidgetDlg::OnNMThemeChangedScrollbar1)
ON_WM_HSCROLL()
ON_WM_VSCROLL()
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CtestwidgetDlg::OnTcnSelchangeTab1)
ON_WM_SHOWWINDOW()
ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &CtestwidgetDlg::OnIpnFieldchangedIpaddress1)
ON_EN_CHANGE(IDC_NETADDRESS1, &CtestwidgetDlg::OnEnChangeNetaddress1)
ON_COMMAND(ID_TAB1_SUB1, &CtestwidgetDlg::OnTab1Sub1)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CtestwidgetDlg::OnNMCustomdrawProgress1)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON1, &CtestwidgetDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CtestwidgetDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CtestwidgetDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BTN_CALCULATE, &CtestwidgetDlg::OnBnClickedBtnCalculate)
ON_BN_CLICKED(IDC_BTN_INPUT_INFO, &CtestwidgetDlg::OnBnClickedBtnInputInfo)
END_MESSAGE_MAP()




///////////////////////////////////////////
UINT WorkerThreadFunction_1(LPVOID pParam)
///////////////////////////////////////////
{
	
	
	int *i = (int*)pParam;
	TRACE(traceAppMsg, 0, "============== WorkerThreadFunction_1 %d =======\n", i);
	return 0;
}


// CtestwidgetDlg message handlers

BOOL CtestwidgetDlg::OnInitDialog()
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

	//combo box
	m_cbMyCombo.AddString(_T("2010"));
	m_cbMyCombo.AddString(_T("2011"));
	m_cbMyCombo.AddString(_T("2012"));
	m_cbMyCombo.AddString(_T("2013"));


	//list box
	m_lbMyListBox.AddString(_T("2010"));
	m_lbMyListBox.AddString(_T("2011"));
	m_lbMyListBox.AddString(_T("2012"));
	m_lbMyListBox.AddString(_T("2013"));

	//scroll bar
	m_sbMyScrollBar.SetScrollRange(0, 255);
	m_sbMyHSScrollBar.SetScrollRange(0, 255);

	//tab control
	CString m_strMessage,strTemp;
	PayLoadItem.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_PAYLOAD_TITLE);
	PayLoadItem.pszText = m_strMessage.GetBuffer();
	m_TabCtrl.InsertItem(0,&PayLoadItem);

	PCIItem.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_PCIE_TITLE);
	PCIItem.pszText = m_strMessage.GetBuffer();
	m_TabCtrl.InsertItem (2,&PCIItem);

	StatsItem.mask = TCIF_TEXT;
	m_strMessage.LoadString(IDS_SYSTEM_TITLE);
	StatsItem.pszText = m_strMessage.GetBuffer();
	m_TabCtrl.InsertItem(1, &StatsItem);
	

	m_Payloaddlg.Create(IDD_DIALOG_PAYLOAD,this);
	m_PCIedlg.Create(IDD_DIALOG_PCI,this);
	m_Systemdlg.Create(IDD_DIALOG_SYSTEM, this);
	
	

	//Network address control 
	m_NetAddCtrl.SetAllowType(NET_STRING_IPV4_ADDRESS);
	//m_NetAddCtrl.SetAllowType(NET_STRING_IPV6_ADDRESS);
	//m_NetAddCtrl.SetAllowType(NET_STRING_NAMED_ADDRESS);
	CString csIPAddress(_T("255.125.25.1"));
	m_NetAddCtrl.SetWindowText(csIPAddress);
	m_IPAdress.SetWindowText(csIPAddress);


	
	//Menu
	m_MyMenu.LoadMenu(IDR_MENU1);
	SetMenu(&m_MyMenu);
	
	//progress bar
	m_ProgressBar.SetRange(0, 100);
	m_ProgressBar.SetPos(10);

	int i=1;
	m_pThreads = AfxBeginThread(WorkerThreadFunction_1,(LPVOID)i);
	

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CtestwidgetDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

//void CtestwidgetDlg::OnPaint()
//{
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // device context for painting
//
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// Center icon in client rectangle
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// Draw the icon
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
//		CDialogEx::OnPaint();
//	}
//}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
//HCURSOR CtestwidgetDlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}



void CtestwidgetDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int getcur = m_cbMyCombo.GetCurSel();
	
	CString sel;
	m_cbMyCombo.GetLBText(getcur, sel);

	TRACE(traceAppMsg, 0, "============== getcur = %d =======================\n", getcur);
	MessageBox(sel);
}


void CtestwidgetDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here

	int getcur = m_lbMyListBox.GetCurSel();

	CString sel;
	m_lbMyListBox.GetText(getcur, sel);

	TRACE(traceAppMsg, 0, "============== getcur = %d =======================\n", getcur);
	MessageBox(sel);
}

//truc ngang
void CtestwidgetDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	int oldPos = m_sbMyHSScrollBar.GetScrollPos();
	

	if(nSBCode == SB_THUMBPOSITION){
		if(pScrollBar == &m_sbMyHSScrollBar){
			TRACE(traceAppMsg, 0, "============== OnHScroll CurPos = %d, nPos = %d=======================\n", oldPos, nPos);
			m_sbMyHSScrollBar.SetScrollPos(nPos);
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


//truc doc
void CtestwidgetDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	
	int oldPos = m_sbMyScrollBar.GetScrollPos();
	

	if(nSBCode == SB_THUMBPOSITION){
		if(pScrollBar == &m_sbMyScrollBar){
			TRACE(traceAppMsg, 0, "============== OnVScroll CurPos = %d, nPos = %d=======================\n", oldPos, nPos);
			m_sbMyScrollBar.SetScrollPos(nPos);
		}
	}


	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}




void CtestwidgetDlg::ShowWindowNumber(int number)
{
	
	
	CRect m_MaxTabRect,m_MaxSettingsRect;
	CRect tabRect;
	m_TabCtrl.GetWindowRect(tabRect);
	
	// Set the size and location of the child windows based on the tab control
	m_MaxSettingsRect.left = tabRect.left; //13;
	m_MaxSettingsRect.top = tabRect.top+22;
	m_MaxSettingsRect.right = tabRect.Width() - 10;
	m_MaxSettingsRect.bottom = tabRect.Height() - 40;


	int windowCount = 3;
	CDialog *m_dPointer[3];
	m_dPointer[0] = &m_Payloaddlg ;
	m_dPointer[1] = &m_Systemdlg;
	m_dPointer[2] = &m_PCIedlg ;

	for (int count = 0; count < windowCount; count++)
		{
			if (count != number)
			{
				m_dPointer[count]->ShowWindow(SW_HIDE);
			}
			else if (count == number)
			{
				m_dPointer[count]->SetWindowPos(&wndTop, m_MaxSettingsRect.left,
							//m_MaxSettingsRect.top+122, m_MaxSettingsRect.right,
							m_MaxSettingsRect.top , m_MaxSettingsRect.right,
							//m_MaxSettingsRect.bottom+15, SWP_SHOWWINDOW);
							m_MaxSettingsRect.bottom, SWP_SHOWWINDOW);
							m_TabCtrl.SetCurSel(count);
							//TRACE(traceAppMsg, 0, "============== ShowWindowNumber number = %d =======================\n", m_TabCtrl.GetCurFocus());
			}
	}


}


void CtestwidgetDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	//TRACE(traceAppMsg, 0, "============== OnTcnSelchangeTab1 =======================\n");

	// Get the number of the currently selected tab, and show it
 	ShowWindowNumber(m_TabCtrl.GetCurFocus());


	*pResult = 0;
}


void CtestwidgetDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	ShowWindowNumber(0);
	// TODO: Add your message handler code here
}


void CtestwidgetDlg::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: Add your control notification handler code here


	
	TRACE(traceAppMsg, 0, "============== OnIpnFieldchangedIpaddress1 =======================\n");
	
	//CString strIPAdd;
	//m_IPAdress.GetWindowText(strIPAdd);
	//MessageBox(strIPAdd);

	DWORD address; 
    m_IPAdress.GetAddress (address);
    TRACE(traceAppMsg, 0, "address %x \n", address);
   

	BYTE ip1, ip2, ip3, ip4; 
	m_IPAdress.GetAddress (ip1, ip2, ip3, ip4); 
	TRACE(traceAppMsg, 0, "%x.%x.%x.%x \n", ip1, ip2, ip3, ip4);
 


	//DWORD dwIP = 0;
	//IPControl.GetAddress(dwIP);
	//struct in_addr Address;
	//Address.S_un.S_addr = dwIP;
	//CString IPAddress(inet_ntoa(Address));



	*pResult = 0;
}

#include "afxcmn.h"
void CtestwidgetDlg::OnEnChangeNetaddress1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	//TRACE(traceAppMsg, 0, "============== OnEnChangeNetaddress1 =======================\n");

	//CString strNetAdd;
	//m_NetAddCtrl.GetWindowText(strNetAdd);
	//MessageBox(strNetAdd);


	NC_ADDRESS m_na;
	NET_ADDRESS_INFO m_nai;
	m_na.pAddrInfo = &m_nai;
	HRESULT rslt = m_NetAddCtrl.GetAddress(&m_na);
	if (rslt != S_OK)
		m_NetAddCtrl.DisplayErrorTip();
	else
	{
		//MessageBox(_T("Success!"), _T("Validation Results"));
		TRACE(traceAppMsg, 0, "============== OnEnChangeNetaddress1 =======================\n");
		CString IPAddress(inet_ntoa(m_nai.Ipv4Address.sin_addr));
		//MessageBox(IPAddress);
		
	}

	
		
}


void CtestwidgetDlg::OnTab1Sub1()
{
	// TODO: Add your command handler code here
	TRACE(traceAppMsg, 0, "============== OnTab1Sub1 =======================\n");
}


void CtestwidgetDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	TRACE(traceAppMsg, 0, "============== OnNMCustomdrawProgress1 =======================\n");


	m_ProgressBar.SetPos(10);





	*pResult = 0;
}


void CtestwidgetDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if(nIDEvent == 1){

		TRACE(traceAppMsg, 0, "============== nIDEvent == 1 =======================\n");

		KillTimer(nIDEvent);//timer only one
	}


	CDialogEx::OnTimer(nIDEvent);
}


void CtestwidgetDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	SetTimer (1, 1000, NULL);
}


void CtestwidgetDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
#if 0	
	CFileDialog fileDlg(TRUE,NULL,NULL,OFN_OVERWRITEPROMPT,L"Text & CSV Files (*.txt,*.csv)|*.txt;*.csv|All Files(*.*)|*.*||");
	int iRet = fileDlg.DoModal();
	CString csFileName;
	csFileName = fileDlg.GetPathName();

	if(iRet == IDOK)
	{
		AfxMessageBox(csFileName);
	}
	else
	{
		 AfxMessageBox(L"No File Selected!");
	}
#endif


	/*CFileDialog(BOOL bOpenFileDialog,
	   LPCTSTR lpszDefExt = NULL,
	   LPCTSTR lpszFileName = NULL,
	   DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
	   LPCTSTR lpszFilter = NULL,
	   CWnd* pParentWnd = NULL );*/



	CFileDialog fileDlg (TRUE,  //Open
						L"txt", 
						L"*.txt", 
						OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, 
						L"Text Files (*.NC)|*.NC|Text Files (*.txt)|*.txt|All Files (*.*)|*.*||", 
						this);
	if( fileDlg.DoModal ()==IDOK )
	{
		CString m_strPathname = fileDlg.GetPathName();
		AfxMessageBox(m_strPathname);
		
	}

}


void CtestwidgetDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	char strFilter[] = { "Text Files (*.txt)|*.txt|" };
	CFileDialog FileDlg(FALSE,  CString("txt"),  CString("noname.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, CString(strFilter));

	if (FileDlg.DoModal() == IDOK)  
	{  
		AfxMessageBox(FileDlg.GetPathName());
	}
}


void CtestwidgetDlg::OnBnClickedBtnCalculate()
{
	// TODO: Add your control notification handler code here

	

	UpdateData(TRUE);

	if(!m_enable_calculate){
		TRACE(traceAppMsg, 0, "============== disable calculate =======================\n");
		return;
	}



	TRACE(traceAppMsg, 0, "============== a = %f =======================\n", m_sohanga);
	TRACE(traceAppMsg, 0, "============== b = %f =======================\n", m_sohangb);
	TRACE(traceAppMsg, 0, "============== m_calculator_function = %f =======================\n", m_calculator_function);


#if 0
	CEdit * pEdit;
	pEdit = (CEdit *)GetDlgItem(IDC_KETQUA);
	CString strResult;
	strResult.Format(_T("%f", m_sohanga + m_sohangb));
	pEdit->SetWindowTextW(strResult);
#else
	switch(m_calculator_function){
	case 0:
		m_ketqua = m_sohanga + m_sohangb;
		break;
	case 1:
		m_ketqua = m_sohanga - m_sohangb;
		break;
	case 2:
		m_ketqua = m_sohanga * m_sohangb;
		break;
	case 3:
		if(m_sohangb != 0)
		m_ketqua = m_sohanga / m_sohangb;
		else
			MessageBox(_T("b value must be not equal 0"));
		break;
	default:
		break;
	}
	
	UpdateData(FALSE);
#endif



}


void CtestwidgetDlg::OnBnClickedBtnInputInfo()
{
	// TODO: Add your control notification handler code here

	MyInfoDlg* dlg=new MyInfoDlg();
 
	if(dlg->DoModal()==IDOK)
 
	{
 
		SetDlgItemText(IDC_NAME,dlg->m_sName);
 
		CString strAge;
 
		strAge.Format(_T("%d"), dlg->m_iAge);
 
		SetDlgItemText(IDC_AGE, strAge);
 
	}





}
