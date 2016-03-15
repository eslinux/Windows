#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "GraphClass.h"
#include <list>



// StatusSystem dialog

class StatusSystem : public CDialogEx
{
	DECLARE_DYNAMIC(StatusSystem)

public:
	StatusSystem(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusSystem();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_SYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCbnSelchangeComboGraphMode();

	SystemData_t m_graphData;

	GraphClass m_cpuGraph;
	GraphClass m_memoryGraph;

	CComboBox m_graphTime;
	
};
