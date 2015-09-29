#pragma once


// SystemDlg dialog

class SystemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SystemDlg)

public:
	SystemDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SystemDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
