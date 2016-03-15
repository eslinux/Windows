// SystemBackup.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemBackup.h"
#include "afxdialogex.h"


// SystemBackup dialog

IMPLEMENT_DYNAMIC(SystemBackup, CDialogEx)

SystemBackup::SystemBackup(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemBackup::IDD, pParent)
	, m_pathOpenConfig(_T(""))
	, m_pathSaveConfig(_T(""))
	, m_pathOpenFirmware(_T(""))
	, m_pathSaveFirmware(_T(""))
{

}

SystemBackup::~SystemBackup()
{
}

void SystemBackup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_WAITING_CONFIGURE, m_startConfigureWaiting);
	DDX_Control(pDX, IDC_PIC_WAITING_SAVE_CONFIGURE, m_startSaveWaiting);
	DDX_Control(pDX, IDC_PIC_WAITING_UPDATE_FIRMWARE, m_statUpdateFwWaiting);
	DDX_Control(pDX, IDC_PIC_WAITING_BACKUP_FIRMWARE, m_startBackupFwWaiting);
	DDX_Text(pDX, IDC_EDIT_OPEN_FILE_CONFIGURE_PATH, m_pathOpenConfig);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_CONFIGURE_PATH, m_pathSaveConfig);
	DDX_Text(pDX, IDC_EDIT_OPEN_FILE_FIRMWARE_PATH, m_pathOpenFirmware);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_FIRMWARE_PATH, m_pathSaveFirmware);
}


BEGIN_MESSAGE_MAP(SystemBackup, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_START_DO_UPDATE_FIRMWARE, &SystemBackup::OnBnClickedButtonStartDoUpdateFirmware)
	ON_BN_CLICKED(IDC_BUTTON_START_DO_CONFIGURE, &SystemBackup::OnBnClickedButtonStartDoConfigure)
	ON_BN_CLICKED(IDC_BUTTON_START_DO_SAVE_CONFIGURE, &SystemBackup::OnBnClickedButtonStartDoSaveConfigure)
	ON_BN_CLICKED(IDC_BUTTON_START_DO_BACKUP_FIRMWARE, &SystemBackup::OnBnClickedButtonStartDoBackupFirmware)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_CONFIGURE, &SystemBackup::OnBnClickedButtonOpenConfigure)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CONFIGURE, &SystemBackup::OnBnClickedButtonSaveConfigure)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_FIRMWARE_LOCATION, &SystemBackup::OnBnClickedButtonOpenFirmwareLocation)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_FIRMWARE_LOCATION, &SystemBackup::OnBnClickedButtonSaveFirmwareLocation)
END_MESSAGE_MAP()


// SystemBackup message handlers


void SystemBackup::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL SystemBackup::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	//HBITMAP bmp = LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP_WHITE));
	//SetBackgroundImage(bmp, BACKGR_TOPLEFT);
	m_startConfigureWaiting.Load(_T(WAITING_PICTURE));
	m_startSaveWaiting.Load(_T(WAITING_PICTURE));
	m_statUpdateFwWaiting.Load(_T(WAITING_PICTURE));
	m_startBackupFwWaiting.Load(_T(WAITING_PICTURE));

	//m_startConfigureWaiting.Draw();
	//m_startSaveWaiting.Draw();
	//m_statUpdateFwWaiting.Draw();
	//m_startBackupFwWaiting.Draw();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void SystemBackup::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void SystemBackup::OnBnClickedButtonStartDoUpdateFirmware()
{
	// TODO: Add your control notification handler code here
	if(m_pathOpenFirmware.IsEmpty()){
		MessageBox(_T("Please chose firmware file"));
		return;
	}


	CT2CA tmpConvt (m_pathOpenFirmware);
	std::string tmpStr (tmpConvt);
	//TRACE("cs %s ", tmpStr.c_str());


	
	//std::string keyf ("/");
	//std::size_t found = tmpStr.rfind(keyf);
	//TRACE("found %s \n", tmpStr.c_str() + found);

	if(ctSoapEngine.SysBackupHandle(EVENT_UPDATE_FIRMWARE, (char*)tmpStr.c_str())){


	}else{

	}
}


void SystemBackup::OnBnClickedButtonStartDoConfigure()
{
	// TODO: Add your control notification handler code here
	if(m_pathOpenConfig.IsEmpty()){
		MessageBox(_T("Please chose configuration file"));
		return;
	}
	CT2CA tmpConvt (m_pathOpenConfig);
	std::string tmpStr (tmpConvt);
	//TRACE("cs %s ", tmpStr.c_str());

	if(ctSoapEngine.SysBackupHandle(EVENT_UPDATE_CONFIGURATION, (char*)tmpStr.c_str())){


	}else{

	}

}


void SystemBackup::OnBnClickedButtonStartDoSaveConfigure()
{
	// TODO: Add your control notification handler code here
	if(m_pathSaveConfig.IsEmpty()){
		MessageBox(_T("Please chose where to save"));
		return;
	}
	CT2CA tmpConvt (m_pathSaveConfig);
	std::string tmpStr (tmpConvt);
	//TRACE("cs %s ", tmpStr.c_str());

	if(ctSoapEngine.SysBackupHandle(EVENT_BACKUP_CONFIGURATION, (char*)tmpStr.c_str())){


	}else{

	}
}


void SystemBackup::OnBnClickedButtonStartDoBackupFirmware()
{
	// TODO: Add your control notification handler code here
	if(m_pathSaveFirmware.IsEmpty()){
		MessageBox(_T("Please chose where to save"));
		return;
	}
	CT2CA tmpConvt (m_pathSaveFirmware);
	std::string tmpStr (tmpConvt);
	//TRACE("cs %s ", tmpStr.c_str());

	if(ctSoapEngine.SysBackupHandle(EVENT_BACKUP_FIRMWARE, (char*)tmpStr.c_str())){


	}else{

	}
}


void SystemBackup::OnBnClickedButtonOpenConfigure()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg (TRUE,  //Open
						L"conf", 
						L"*.conf", 
						OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, 
						L"Configuration Files (*.conf)|*.conf|All Files (*.*)|*.*||", 
						this);
	if( fileDlg.DoModal ()==IDOK )
	{
		m_pathOpenConfig = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void SystemBackup::OnBnClickedButtonSaveConfigure()
{
	// TODO: Add your control notification handler code here
	char strFilter[] = { "Configuration Files (*.conf)|*.conf|" };
	CFileDialog FileDlg(FALSE,  CString("conf"),  CString("savefile.conf"), 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, CString(strFilter));

	//BIF_BROWSEINCLUDEFILES

	if (FileDlg.DoModal() == IDOK)  
	{  
		m_pathSaveConfig = FileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void SystemBackup::OnBnClickedButtonOpenFirmwareLocation()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg (TRUE,  //Open
						L"ctfw", 
						L"*.ctfw", 
						OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, 
						L"Firmware Files (*.ctfw)|*.ctfw|All Files (*.*)|*.*||", 
						this);
	if( fileDlg.DoModal ()==IDOK )
	{
		m_pathOpenFirmware = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void SystemBackup::OnBnClickedButtonSaveFirmwareLocation()
{
	// TODO: Add your control notification handler code here
	char strFilter[] = { "Firmware Files (*.ctfw)|*.ctfw|" };
	CFileDialog FileDlg(FALSE,  CString("ctfw"),  CString("savefile.ctfw"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, CString(strFilter));

	if (FileDlg.DoModal() == IDOK)  
	{  
		m_pathSaveFirmware = FileDlg.GetPathName();
		UpdateData(FALSE);
	}
}
