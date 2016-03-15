#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "pictureex.h"


// SystemBackup dialog

class SystemBackup : public CDialogEx
{
	DECLARE_DYNAMIC(SystemBackup)

public:
	SystemBackup(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemBackup();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM_BACKUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedButtonStartDoUpdateFirmware();

	CPictureEx m_startConfigureWaiting;
	CPictureEx m_startSaveWaiting;
	CPictureEx m_statUpdateFwWaiting;
	CPictureEx m_startBackupFwWaiting;

	CString m_pathOpenConfig;
	CString m_pathSaveConfig;
	CString m_pathOpenFirmware;
	CString m_pathSaveFirmware;

	afx_msg void OnBnClickedButtonStartDoConfigure();
	afx_msg void OnBnClickedButtonStartDoSaveConfigure();
	afx_msg void OnBnClickedButtonStartDoBackupFirmware();
	afx_msg void OnBnClickedButtonOpenConfigure();
	afx_msg void OnBnClickedButtonSaveConfigure();
	afx_msg void OnBnClickedButtonOpenFirmwareLocation();
	afx_msg void OnBnClickedButtonSaveFirmwareLocation();
};
