// GraphClass.cpp : implementation file
//

#include "stdafx.h"
#include "test-widget.h"
#include "GraphClass.h"


// CGraphClass

IMPLEMENT_DYNAMIC(CGraphClass, CStatic)

CGraphClass::CGraphClass()
{

}

CGraphClass::~CGraphClass()
{
}


BEGIN_MESSAGE_MAP(CGraphClass, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CGraphClass message handlers




void CGraphClass::CraeteGraph(void)
{

	CPaintDC dc(this); // device context for painting
	
	COLORREF qCircleColor = RGB(255, 0, 0);
	CPen qCirclePen(PS_SOLID, 5, qCircleColor);
	dc.SelectObject(&qCirclePen);

	dc.Ellipse(0, 0, 200, 100);


	COLORREF qLineColor = RGB(0, 0, 255);
	CPen qLinePen(PS_SOLID, 7, qLineColor);
	dc.SelectObject(&qLinePen);
	dc.MoveTo(0,100 );
	dc.LineTo(0 ,0);
	dc.MoveTo(0,100 );
	dc.LineTo(100 ,100);

	CString szBuffer(_T("hello"));
	//dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
	dc.TextOutW(10,10, szBuffer);
}


void CGraphClass::OnPaint()
{
	TRACE(traceAppMsg, 0, "============== CGraphClass::OnPaint =======================\n");
	CraeteGraph();
}


BOOL CGraphClass::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CStatic::OnEraseBkgnd(pDC);
}
