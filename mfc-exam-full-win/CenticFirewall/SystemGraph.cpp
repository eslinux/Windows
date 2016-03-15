// SystemGraph.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemGraph.h"


// SystemGraph

IMPLEMENT_DYNAMIC(SystemGraph, CStatic)

SystemGraph::SystemGraph()
: m_graphMode(GRAPH_MODE_HOUR)
{
	m_dataList = NULL;
	m_axisPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	m_graphPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_hbrBkGnd.CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
}

SystemGraph::~SystemGraph()
{
}


BEGIN_MESSAGE_MAP(SystemGraph, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// SystemGraph message handlers
static const char *weekStr[] = {{"Mon"}, {"Tue"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
static const char *monthStr[] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"}};
							
void SystemGraph::CraeteGraph(void)
{
	CPaintDC dc(this); // device context for painting
	int i = 0;
	int stepX =0, stepY = 0;
	int numStep =0;
	//TRACE(L"SystemGraph::CraeteGraph %d\n", m_graphMode);

#if 0	
	COLORREF qCircleColor = RGB(255, 0, 0);
	CPen qCirclePen(PS_SOLID, 1, qCircleColor);
	dc.SelectObject(&qCirclePen);

	dc.Ellipse(0, 0, 200, 100);


	COLORREF qLineColor = RGB(0, 0, 0);
	CPen qLinePen(PS_SOLID, 4, qLineColor);
	dc.SelectObject(&qLinePen);
	dc.MoveTo(0,100 );
	dc.LineTo(0 ,0);
	dc.MoveTo(0,100 );
	dc.LineTo(100 ,100);

	CString szBuffer(_T("hello"));
	dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
	dc.TextOutW(10,10, szBuffer);
	dc.TextOutW(10,110, szBuffer);
#endif

	//clean old screen
	m_nSave  = dc.SaveDC();
	GetClientRect(&m_rectGraphDim);
	dc.FillRect(&m_rectGraphDim,&m_hbrBkGnd);


	//draw XY coordinate
	dc.SelectObject(&m_axisPen);
	dc.MoveTo(GRAPH_X_COORD, GRAPH_Y_COORD - GRAPH_Y_AXIS_LENGTH);
	dc.LineTo(GRAPH_X_COORD , GRAPH_Y_COORD);
	dc.LineTo(GRAPH_X_COORD + GRAPH_X_AXIS_LENGTH , GRAPH_Y_COORD);

	//text on Y axis: 0 20 40 60 80 100% (6 point)
	dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
	CString szBuffer;
	numStep = 6;
	stepX = -40;
	stepY = - GRAPH_Y_AXIS_LENGTH / 5;
	for(i = 0; i < numStep; i++){
		szBuffer.Format(_T("%d%s"), 20 * i, "%");
		dc.TextOutW(GRAPH_X_COORD + stepX, GRAPH_Y_COORD + stepY *i - 10, szBuffer);
		szBuffer.Empty();
	}
	

	//text on X axis
	//m_graphMode = TIME_YEAR;
	
	switch(m_graphMode){
	case GRAPH_MODE_HOUR:
		//0 10 20 ... 60 (7 point)
		numStep = 7;
		stepX = GRAPH_X_AXIS_LENGTH/(numStep-1);
		stepY = 10;
		for(i = 0; i < numStep; i++){
			szBuffer.Format(_T("%d"), 10 * i);
			dc.TextOutW(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD + stepY, szBuffer);
			szBuffer.Empty();
		}

		
		break;
	case GRAPH_MODE_DAY:
		//0 2 4 ... 24 Hour ( 13 point)
		numStep = 13;
		stepX = GRAPH_X_AXIS_LENGTH/(numStep-1);
		stepY = 10;
		for(i = 0; i < numStep; i++){
			szBuffer.Format(_T("%d"), 2 * i);
			dc.TextOutW(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD + stepY, szBuffer);
			szBuffer.Empty();
		}

		break;
	case GRAPH_MODE_WEEK:
		//Mon Tue Wed Thu Fri Sat Sun ( 7 point)
		numStep = 7;
		stepX = GRAPH_X_AXIS_LENGTH/(numStep-1);
		stepY = 10;
		for(i = 0; i < numStep; i++){
			//TRACE(_T("%s \n"), "mom"); 
			//TRACE(traceAppMsg, 0, "%s \n", weekStr[i]);
			//szBuffer.Format(_T("%s"), weekStr[i]);
			szBuffer = CString( weekStr[i] );
			dc.TextOutW(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD + stepY, szBuffer);
			szBuffer.Empty();
		}
		break;
	case GRAPH_MODE_MONTH:
		//Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec (12 point)
		numStep = 12;
		stepX = GRAPH_X_AXIS_LENGTH/(numStep-1);
		stepY = 10;
		for(i = 0; i < numStep; i++){
			//TRACE(_T("%s \n"), "mom"); 
			//TRACE(traceAppMsg, 0, "%s \n", weekStr[i]);
			//szBuffer.Format(_T("%s"), weekStr[i]);
			szBuffer = CString( monthStr[i] );
			dc.TextOutW(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD + stepY, szBuffer);
			szBuffer.Empty();
		}
		break;
	case GRAPH_MODE_YEAR:
		//2015 2016 ... 2020 (6 point)
		numStep = 6;
		stepX = GRAPH_X_AXIS_LENGTH/(numStep-1);
		stepY = 10;
		for(i = 0; i < numStep; i++){
			szBuffer.Format(_T("%d"), 2015 + i);
			dc.TextOutW(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD + stepY, szBuffer);
			szBuffer.Empty();
		}
		break;
	default:
		break;
	}


	//draw graph
	SysGraphDataIt_t it=m_dataList->begin();
	dc.SelectObject(&m_graphPen);
	if(it != m_dataList->end()){
		dc.MoveTo(GRAPH_X_COORD, GRAPH_Y_COORD - (*it)*GRAPH_Y_AXIS_LENGTH/100);
	}
	for(i = 0; i < numStep; i++){
		if(it != m_dataList->end()){
			dc.LineTo(GRAPH_X_COORD + stepX * i, GRAPH_Y_COORD - (*it)*150/100);
			it++;
		}
	}
		

	dc.RestoreDC(m_nSave);
}


void SystemGraph::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
	//TRACE(_T("%s<%d>"),__FUNCTION__,__LINE__);
	//TRACE(L"SystemGraph::OnPaint \n");
	
	CraeteGraph();
	
}


BOOL SystemGraph::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CStatic::OnEraseBkgnd(pDC);
}


void SystemGraph::ChangeMode(enum SysGraphMode_t mode)
{
	m_graphMode = mode;
	TRACE(L"SystemGraph::ChangeMode %d\n", m_graphMode);
}


void SystemGraph::SetGraphData(SysGraphData_t * data)
{
	m_dataList = data;
}
