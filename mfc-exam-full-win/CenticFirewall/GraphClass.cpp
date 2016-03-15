// GraphClass.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "GraphClass.h"


IMPLEMENT_DYNAMIC(GraphClass, CStatic)

GraphClass::GraphClass()
{
	m_graphMode = GRAPH_MODE_HOUR;
	m_listData = NULL;
	m_saveDc = 0;
	m_hbrBkGnd.CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
}

GraphClass::~GraphClass()
{
}


BEGIN_MESSAGE_MAP(GraphClass, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// GraphClass message handlers




void GraphClass::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
	DrawGraph();
}


void GraphClass::DrawGraph(void)
{
	CPaintDC dc(this); // device context for painting
	int i = 0, j = 0;
	int stepX = 0, stepY = 0;
	int numPoint = 0;
	CString szBuffer;

	m_saveDc  = dc.SaveDC();
	GetClientRect(&m_rectGraphDim);
	dc.FillRect(&m_rectGraphDim,&m_hbrBkGnd);


	//draw XY coordinate
	dc.SelectObject(&m_axisPen);
	dc.MoveTo(m_axisPara.xOriginCoord, m_axisPara.yOriginCoord - m_axisPara.yWidth);
	dc.LineTo(m_axisPara.xOriginCoord , m_axisPara.yOriginCoord);
	dc.LineTo(m_axisPara.xOriginCoord + m_axisPara.xWidth , m_axisPara.yOriginCoord);


	//text on Y axis
	dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
	stepX = 0;
	stepY = m_axisPara.yWidth / (m_axisPara.yAxisNumPoint-1);

	for(i = 0; i < m_axisPara.yAxisNumPoint; i++){
		szBuffer = CString(m_axisPara.yText.at(i).c_str());
		
		dc.TextOutW(m_axisPara.xOriginCoord + m_axisPara.yTextXoffset, 
			       m_axisPara.yOriginCoord - stepY *i + m_axisPara.yTextYoffset, szBuffer);
		szBuffer.Empty();
	}


	//text on X axis	
	stepX = m_axisPara.xWidth / (m_axisPara.xAxisNumPoint-1);
	stepY = 0;

	for(i = 0; i < m_axisPara.xAxisNumPoint; i++){
		szBuffer = CString(m_axisPara.xText.at(i).c_str());
		
		dc.TextOutW(m_axisPara.xOriginCoord + stepX *i + m_axisPara.xTextXoffset, 
			       m_axisPara.yOriginCoord + m_axisPara.xTextYoffset, szBuffer);
		szBuffer.Empty();
	}


	//draw graph
	GraphData_t *tmpData = NULL;
	stepX = m_axisPara.xWidth / (m_axisPara.xPenNumPoint-1);
	for(i = 0; (i < m_numPen) && (m_numPen == (int)m_listData->size()); i++){
		dc.SelectObject(&(m_listPen[i]));
		tmpData = &(m_listData->at(i));
		if(tmpData->grapData.size() == 0) continue;
		
		dc.MoveTo(m_axisPara.xOriginCoord, m_axisPara.yOriginCoord - (tmpData->grapData.at(0))*m_axisPara.yWidth/m_axisPara.yMaxValue);
		numPoint = min(m_axisPara.xPenNumPoint, (int)tmpData->grapData.size());
		for(j = 0; j < numPoint; j++){		
			dc.LineTo(m_axisPara.xOriginCoord + stepX * j, m_axisPara.yOriginCoord - (tmpData->grapData.at(j))*m_axisPara.yWidth/m_axisPara.yMaxValue);
			//TRACE(traceAppMsg, 0, "<%d>tmpData->at(%d) = %d \n", i, j, tmpData->grapData.at(j));			
		}
	}

	TRACE(traceAppMsg, 0, "GraphClass::DrawGraph Done\n");
	dc.RestoreDC(m_saveDc);
}


