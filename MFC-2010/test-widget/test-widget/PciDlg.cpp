// PciDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test-widget.h"
#include "PciDlg.h"
#include "afxdialogex.h"


// PciDlg dialog

IMPLEMENT_DYNAMIC(PciDlg, CDialogEx)

PciDlg::PciDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PciDlg::IDD, pParent)
{

}

PciDlg::~PciDlg()
{
}

void PciDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PCIE_TXGRAPH, m_cPCIeTransmitGraph);
}


BEGIN_MESSAGE_MAP(PciDlg, CDialogEx)	
	ON_WM_PAINT()
END_MESSAGE_MAP()


// PciDlg message handlers


void PciDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	
	

	TRACE(traceAppMsg, 0, "==============PciDlg::OnBnClickedButton1 =======================\n");
	//
	


}


void PciDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//// TODO: Add your message handler code here
	//// Do not call CDialogEx::OnPaint() for painting messages

	//TRACE(traceAppMsg, 0, "==============PciDlg::OnPaint =======================\n");
	//
	//static const DWORD nXMargin = 10;
	//int fromPoint=0,toPoint=0,nSave=0;
	//RECT rectGraphDim;
	//CBrush hbrBkGnd;
	//hbrBkGnd.CreateSolidBrush(GetSysColor(COLOR_BTNFACE));

	//nSave  = dc.SaveDC();
	//GetClientRect(&rectGraphDim);
	//RECT rectTemp;
	//rectTemp.bottom = rectGraphDim.bottom ;
	//rectTemp.left = rectGraphDim.left + nXMargin;
	//rectTemp.right = rectGraphDim.right ;
	//rectTemp .top = rectGraphDim .top ;
	//dc.FillRect(&rectTemp,&hbrBkGnd);

	//dc.MoveTo(nXMargin,rectGraphDim.bottom );
	//dc.LineTo(rectGraphDim.right ,rectGraphDim.bottom);
	//dc.MoveTo(nXMargin,rectGraphDim.bottom);
	//dc.LineTo(nXMargin,(rectGraphDim.top));




}
