// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include <iostream>

// LoginDlg dialog

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(LoginDlg::IDD, pParent)
	, m_strUsername(_T(""))
	, m_strPassword(_T(""))
	, m_serverIP(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUsername);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Control(pDX, IDC_STATIC_LOGIN_WAITING, m_loginWaiting);
	DDX_Text(pDX, IDC_EDIT_SERVER_IP, m_serverIP);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &LoginDlg::OnBnClickedBtnLogin)
	ON_WM_SIZE()
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// LoginDlg message handlers


void LoginDlg::OnBnClickedBtnLogin()
{
	//for test

	GetParent()->SendMessage(WM_LOGIN_MESSAGE, 0, /*(LPARAM)pStruct*/1);
	return;



	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if(m_strUsername.StringLength(m_strUsername) == 0 || m_strPassword.StringLength(m_strPassword) == 0) return;

	CT2CA pszConvertedAnsiStringUsername (m_strUsername);
	std::string strStdUsername (pszConvertedAnsiStringUsername);
	
	CT2CA pszConvertedAnsiStringPassword (m_strPassword);
	std::string strStdPassword (pszConvertedAnsiStringPassword);
	
	TRACE("username %s, passwd %s \n", strStdUsername.c_str(), strStdPassword.c_str());

	if(ctSoapEngine.login((char*)strStdUsername.c_str(), (char*)strStdPassword.c_str())){
		//goin mainboard

		/*MY_STRUCT *pStruct = new MY_STRUCT;

		pStruct->a = 5;
		pStruct->b = 4;
		pStruct->c = 1;*/

		GetParent()->SendMessage(WM_LOGIN_MESSAGE, 0, /*(LPARAM)pStruct*/1);


	}else{
		MessageBox(L"Login Fail !");
	}

}


void LoginDlg::OnSize(UINT nType, int cx, int cy)
{
	//TRACE(L"LoginDlg::OnSize cx %d, cy %d \n", cx, cy);

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
}


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	/*HBITMAP bmpLogo = (HBITMAP)LoadImage(NULL, L"res/waiting.gif", IMAGE_BITMAP, 145, 140, LR_LOADFROMFILE);
	m_loginWaiting.SetBitmap(bmpLogo);*/


	/*CImage viewImage;
	CBitmap viewBitmap;

	viewImage.Load(L"res/waiting.gif");
	viewBitmap.Attach(viewImage.Detach());
	m_loginWaiting.SetBitmap((HBITMAP)viewBitmap);*/

	m_loginWaiting.Load(_T(WAITING_PICTURE));
	//m_loginWaiting.Draw();
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void LoginDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}

