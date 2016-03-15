#pragma once
#include "centic_wm.h"
#include "gSoapEngine.h"
#include "dlgresizehelper.h"

#include "atlimage.h"
#include "pictureex.h"
// LoginDlg dialog


class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~LoginDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUsername;
	CString m_strPassword;
	afx_msg void OnBnClickedBtnLogin();

	DlgResizeHelper m_resizeHelper;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	CPictureEx m_loginWaiting;
	CString m_serverIP;
};
