#pragma once


// PayloadDlg dialog

class PayloadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PayloadDlg)

public:
	PayloadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~PayloadDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_PAYLOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
