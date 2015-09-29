#pragma once
#include "pcietransmitgraph.h"


// PciDlg dialog

class PciDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PciDlg)

public:
	PciDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~PciDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_PCI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CPCIeTransmitGraph m_cPCIeTransmitGraph;
	CPCIeTransmitGraph m_cPCIeTransmitGraph;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};
