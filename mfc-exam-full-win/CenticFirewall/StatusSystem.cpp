// StatusSystem.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusSystem.h"
#include "afxdialogex.h"
#include <stdlib.h>



static const char **xStr;
static const char *yStr[] = {{"0%"}, {"20%"}, {"40%"}, {"60%"}, {"80%"}, {"100%"}};
static const char *hourStr[] = {{"0"}, {"10"}, {"20"}, {"30"}, {"40"}, {"50"}, {"60"}};
static const char *dayStr[] = {{"0"}, {"2"}, {"4"}, {"6"}, {"8"}, {"10"},
{"12"}, {"14"}, {"16"}, {"18"},  {"20"}, {"22"}, {"24"}};
static const char *weekStr[] = {{"Mon"}, {"Tue"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
static const char *monthStr[] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"}};
static const char *yearStr[] = {{"2015"}, {"2016"}, {"2017"}, {"2018"}, {"2019"}, {"2020"}};
	
// StatusSystem dialog

IMPLEMENT_DYNAMIC(StatusSystem, CDialogEx)

StatusSystem::StatusSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusSystem::IDD, pParent)
{
	

}

StatusSystem::~StatusSystem()
{
}

void StatusSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CPU_GRAPH, m_cpuGraph);
	DDX_Control(pDX, IDC_MEMORY_GRAPH, m_memoryGraph);
	DDX_Control(pDX, IDC_COMBO_GRAPH_MODE, m_graphTime);
}


BEGIN_MESSAGE_MAP(StatusSystem, CDialogEx)
	ON_WM_SIZE()
	
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_COMBO_GRAPH_MODE, &StatusSystem::OnCbnSelchangeComboGraphMode)
END_MESSAGE_MAP()


// StatusSystem message handlers


BOOL StatusSystem::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	//graph mode
	CString tmp;
	tmp.LoadString(IDS_HOUR);
	m_graphTime.AddString(tmp);
	tmp.LoadString(IDS_DAY);
	m_graphTime.AddString(tmp);
	tmp.LoadString(IDS_WEEK);
	m_graphTime.AddString(tmp);
	tmp.LoadString(IDS_MONTH);
	m_graphTime.AddString(tmp);
	tmp.LoadString(IDS_YEAR);
	m_graphTime.AddString(tmp);
	m_graphTime.SetCurSel(0);


	//cpu graph tool setup
	m_cpuGraph.m_graphMode = GRAPH_MODE_HOUR;
	m_cpuGraph.m_axisPara.xOriginCoord = 0;
	m_cpuGraph.m_axisPara.yOriginCoord = 150;

	m_cpuGraph.m_axisPara.xWidth = 500;
	m_cpuGraph.m_axisPara.yWidth = 150;

	m_cpuGraph.m_axisPara.xMaxValue = 0;//not use
	m_cpuGraph.m_axisPara.yMaxValue = 100; //100%

	m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_cpuGraph.m_axisPara.yAxisNumPoint =  6; //0 20 40 60 80 100% (6 point)

	m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_cpuGraph.m_axisPara.yPenNumPoint =  6; //0 20 40 60 80 100% (6 point)

	m_cpuGraph.m_axisPara.xTextXoffset = 0;
	m_cpuGraph.m_axisPara.xTextYoffset = 10;

	m_cpuGraph.m_axisPara.yTextXoffset = -40;
	m_cpuGraph.m_axisPara.yTextYoffset = -10;

	m_cpuGraph.m_axisPara.xText.clear();
	m_cpuGraph.m_axisPara.yText.clear();
	for(int i = 0; i < m_cpuGraph.m_axisPara.yAxisNumPoint; i++){
		m_cpuGraph.m_axisPara.yText.push_back(yStr[i]);
	}
	for(int i = 0; i < m_cpuGraph.m_axisPara.xAxisNumPoint; i++){
		m_cpuGraph.m_axisPara.xText.push_back(hourStr[i]);//default for GRAPH_MODE_HOUR
	}

	m_cpuGraph.m_axisPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	m_cpuGraph.m_listPen[0].CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //cpu load pen	
	m_cpuGraph.m_numPen = 1;
	m_cpuGraph.m_listData = &(m_graphData.cpuData);

	//momory graph tool setup
	m_memoryGraph.m_graphMode = GRAPH_MODE_HOUR;
	m_memoryGraph.m_axisPara.xOriginCoord = 0;
	m_memoryGraph.m_axisPara.yOriginCoord = 150;

	m_memoryGraph.m_axisPara.xWidth = 500;
	m_memoryGraph.m_axisPara.yWidth = 150;

	m_memoryGraph.m_axisPara.xMaxValue = 0;//not use
	m_memoryGraph.m_axisPara.yMaxValue = 100; //100%

	m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_memoryGraph.m_axisPara.yAxisNumPoint =  6; //0 20 40 60 80 100% (6 point)
	
	m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_memoryGraph.m_axisPara.yPenNumPoint =  6; //0 20 40 60 80 100% (6 point)


	m_memoryGraph.m_axisPara.xTextXoffset = 0;
	m_memoryGraph.m_axisPara.xTextYoffset = 10;

	m_memoryGraph.m_axisPara.yTextXoffset = -40;
	m_memoryGraph.m_axisPara.yTextYoffset = -10;

	m_memoryGraph.m_axisPara.xText.clear();
	m_memoryGraph.m_axisPara.yText.clear();
	for(int i = 0; i < m_memoryGraph.m_axisPara.yAxisNumPoint; i++){
		m_memoryGraph.m_axisPara.yText.push_back(yStr[i]);
	}
	for(int i = 0; i < m_memoryGraph.m_axisPara.xAxisNumPoint; i++){
		m_memoryGraph.m_axisPara.xText.push_back(hourStr[i]);//default for GRAPH_MODE_HOUR
	}

	m_memoryGraph.m_axisPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	m_memoryGraph.m_listPen[0].CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //cpu load pen	
	m_memoryGraph.m_numPen = 1;
	m_memoryGraph.m_listData = &(m_graphData.memoryData);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusSystem::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();

	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void StatusSystem::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}

void StatusSystem::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		TRACE(L"StatusSystem::OnTimer\n");

		//update CPU and Memory graph

		if(ctSoapEngine.getStatusSystemGraph(m_cpuGraph.m_graphMode, &m_graphData)){
			//update current list if
			TRACE(L"StatusServices::OnTimer new\n");

			TRACE(L"ret->cpuData size %d\n", m_graphData.cpuData.size());
			TRACE(L"ret->memoryData size %d\n", m_graphData.memoryData.size());


		}else{
			//clear all current list if
			TRACE(L"StatusServices::OnTimer clear\n");
			
			m_graphData.cpuData.clear();
			m_graphData.memoryData.clear();
		}


		//re draw window (next state: ::OnPaint)
		InvalidateRect(NULL,false); 
		
	}

	CDialogEx::OnTimer(nIDEvent);
}


void StatusSystem::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
	TRACE(L"StatusSystem::OnPaint\n");
}


void StatusSystem::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	TRACE(L"StatusSystem::OnShowWindow\n");
	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}


void StatusSystem::OnCbnSelchangeComboGraphMode()
{
	// TODO: Add your control notification handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
	int getcur = m_graphTime.GetCurSel();

	//change CPU and Memory graph
	m_cpuGraph.m_graphMode = m_memoryGraph.m_graphMode = (enum SysGraphMode_t)getcur;

	switch (m_cpuGraph.m_graphMode) {
	case GRAPH_MODE_HOUR:
		m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;
		m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;

		m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;
		m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;

		xStr = hourStr;
		break;
	case GRAPH_MODE_DAY:
		m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_DAY;
		m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_DAY;

		m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_DAY;
		m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_DAY;

		xStr = dayStr;
		break;
	case GRAPH_MODE_WEEK:
		m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_WEEK;
		m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_WEEK;

		m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_WEEK;
		m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_WEEK;

		xStr = weekStr;
		break;
	case GRAPH_MODE_MONTH:
		m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_MONTH;
		m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_MONTH;

		m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_MONTH;
		m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_MONTH;

		xStr = monthStr;
		break;
	case GRAPH_MODE_YEAR:
		m_cpuGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_YEAR;
		m_memoryGraph.m_axisPara.xAxisNumPoint = NUMS_POINT_YEAR;

		m_cpuGraph.m_axisPara.xPenNumPoint = NUMS_POINT_YEAR;
		m_memoryGraph.m_axisPara.xPenNumPoint = NUMS_POINT_YEAR;

		xStr = yearStr;
		break;
	default:
		break;
	}

	m_cpuGraph.m_axisPara.xText.clear();
	m_memoryGraph.m_axisPara.xText.clear();
	for(int i = 0; i < m_cpuGraph.m_axisPara.xAxisNumPoint; i++){
		m_cpuGraph.m_axisPara.xText.push_back(xStr[i]);
		m_memoryGraph.m_axisPara.xText.push_back(xStr[i]);
	}
	

	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}
