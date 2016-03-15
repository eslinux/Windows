// StatusNetworkOther.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusNetworkOther.h"
#include "afxdialogex.h"


static const char **xStr;
static const char *yStr[] = {{"0"}, {"20"}, {"40"}, {"60"}, {"80"}, {"100"}};
static const char *hourStr[] = {{"0"}, {"10"}, {"20"}, {"30"}, {"40"}, {"50"}, {"60"}};
static const char *dayStr[] = {{"0"}, {"2"}, {"4"}, {"6"}, {"8"}, {"10"},
{"12"}, {"14"}, {"16"}, {"18"},  {"20"}, {"22"}, {"24"}};
static const char *weekStr[] = {{"Mon"}, {"Tue"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
static const char *monthStr[] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"}};
static const char *yearStr[] = {{"2015"}, {"2016"}, {"2017"}, {"2018"}, {"2019"}, {"2020"}};
	
// StatusNetworkOther dialog

IMPLEMENT_DYNAMIC(StatusNetworkOther, CDialogEx)

StatusNetworkOther::StatusNetworkOther(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusNetworkOther::IDD, pParent)
	, m_inputMax(_T(""))
	, m_inputAvg(_T(""))
	, m_inputMin(_T(""))
	, m_inputCurrent(_T(""))
	, m_forwardMax(_T(""))
	, m_forwardAvg(_T(""))
	, m_forwardMin(_T(""))
	, m_forwardCurrent(_T(""))
	, m_outputMax(_T(""))
	, m_outputAvg(_T(""))
	, m_outputMin(_T(""))
	, m_outputCurrent(_T(""))
{

}

StatusNetworkOther::~StatusNetworkOther()
{
}

void StatusNetworkOther::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GRAPH_MODE, m_graphTime);
	DDX_Control(pDX, IDC_STATIC_OTHER_GRAPH, m_graphTool);
	DDX_Text(pDX, IDC_EDIT_INPUT_MAX, m_inputMax);
	DDX_Text(pDX, IDC_EDIT_INPUT_AVG, m_inputAvg);
	DDX_Text(pDX, IDC_EDIT_INPUT_MIN, m_inputMin);
	DDX_Text(pDX, IDC_EDIT_INPUT_CURRENT, m_inputCurrent);
	DDX_Text(pDX, IDC_EDIT_FORWARD_MAX, m_forwardMax);
	DDX_Text(pDX, IDC_EDIT_FORWARD_AVG, m_forwardAvg);
	DDX_Text(pDX, IDC_EDIT_FORWARD_MIN, m_forwardMin);
	DDX_Text(pDX, IDC_EDIT_FORWARD_CURRENT, m_forwardCurrent);
	DDX_Text(pDX, IDC_EDIT_OUTPUT_MAX, m_outputMax);
	DDX_Text(pDX, IDC_EDIT_OUTPUT_AVG, m_outputAvg);
	DDX_Text(pDX, IDC_EDIT_OUTPUT_MIN, m_outputMin);
	DDX_Text(pDX, IDC_EDIT_OUTPUT_CURRENT, m_outputCurrent);
	DDX_Control(pDX, IDC_STATIC_GREEN_COLOR, m_greenColor);
	//  DDX_Control(pDX, IDC_STATIC_RED_COLOR, m_blueColor);
	DDX_Control(pDX, IDC_STATIC_RED_COLOR, m_redColor);
	DDX_Control(pDX, IDC_STATIC_BLUE_COLOR, m_blueColor);
}


BEGIN_MESSAGE_MAP(StatusNetworkOther, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO_GRAPH_MODE, &StatusNetworkOther::OnCbnSelchangeComboGraphMode)
END_MESSAGE_MAP()


// StatusNetworkOther message handlers


void StatusNetworkOther::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL StatusNetworkOther::OnInitDialog()
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

	//graph tool setup
	m_graphTool.m_graphMode = GRAPH_MODE_HOUR;
	m_graphTool.m_axisPara.xOriginCoord = 0;
	m_graphTool.m_axisPara.yOriginCoord = 150;

	m_graphTool.m_axisPara.xWidth = 500;
	m_graphTool.m_axisPara.yWidth = 150;

	m_graphTool.m_axisPara.xMaxValue = 0;//not use
	m_graphTool.m_axisPara.yMaxValue = 100; //100%

	m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_graphTool.m_axisPara.yAxisNumPoint =  6; //0 20 40 60 80 100% (6 point)

	m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;//default for GRAPH_MODE_HOUR
	m_graphTool.m_axisPara.yPenNumPoint =  6; //0 20 40 60 80 100% (6 point)

	m_graphTool.m_axisPara.xTextXoffset = 0;
	m_graphTool.m_axisPara.xTextYoffset = 10;

	m_graphTool.m_axisPara.yTextXoffset = -40;
	m_graphTool.m_axisPara.yTextYoffset = -10;

	m_graphTool.m_axisPara.xText.clear();
	m_graphTool.m_axisPara.yText.clear();
	for(int i = 0; i < m_graphTool.m_axisPara.yAxisNumPoint; i++){
		m_graphTool.m_axisPara.yText.push_back(yStr[i]);
	}
	for(int i = 0; i < m_graphTool.m_axisPara.xAxisNumPoint; i++){
		m_graphTool.m_axisPara.xText.push_back(hourStr[i]);//default for GRAPH_MODE_HOUR
	}

	m_graphTool.m_axisPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	m_graphTool.m_listPen[0].CreatePen(PS_SOLID, 1, RGB(0, 255, 0)); //incoming traffic pen
	m_graphTool.m_listPen[1].CreatePen(PS_SOLID, 1, RGB(0, 0, 255)); //forward  traffic pen
	m_graphTool.m_listPen[2].CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //outcoming traffic pen
	m_graphTool.m_numPen = 3;

	m_graphTool.m_listData = &(m_networkData.graphListData);

	//color note
	m_greenColor.SetBkColor(LIGHTGREEN);
	m_redColor.SetBkColor(LIGHTRED);
	m_blueColor.SetBkColor(LIGHTBLUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusNetworkOther::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void StatusNetworkOther::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}


void StatusNetworkOther::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}


void StatusNetworkOther::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		

		//update
		if(ctSoapEngine.getStatusNetworkOther(m_graphTool.m_graphMode, &m_networkData)){
			//update current list if
			TRACE(L"StatusNetworkOther::OnTimer update\n");

		}else{
			//clear all current list if
			TRACE(L"StatusNetworkOther::OnTimer clear\n");
			m_networkData.graphListData.clear();
			m_networkData.netListTraffic.clear();
		}

		if(m_networkData.netListTraffic.size() > 0){
			m_inputMax.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).max);
			m_inputAvg.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).avg);
			m_inputMin.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).min);
			m_inputCurrent.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).current);

			m_forwardMax.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).max);
			m_forwardAvg.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).avg);
			m_forwardMin.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).min);
			m_forwardCurrent.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).current);
		
			m_outputMax.Format(_T("%0.1f"), m_networkData.netListTraffic.at(2).max);
			m_outputAvg.Format(_T("%0.1f"), m_networkData.netListTraffic.at(2).avg);
			m_outputMin.Format(_T("%0.1f"), m_networkData.netListTraffic.at(2).min);
			m_outputCurrent.Format(_T("%0.1f"), m_networkData.netListTraffic.at(2).current);
		}else{
			m_inputMax.Format(_T("---"));
			m_inputAvg.Format(_T("---"));
			m_inputMin.Format(_T("---"));
			m_inputCurrent.Format(_T("---"));

			m_forwardMax.Format(_T("---"));
			m_forwardAvg.Format(_T("---"));
			m_forwardMin.Format(_T("---"));
			m_forwardCurrent.Format(_T("---"));

			m_outputMax.Format(_T("---"));
			m_outputAvg.Format(_T("---"));
			m_outputMin.Format(_T("---"));
			m_outputCurrent.Format(_T("---"));
		}

		UpdateData(FALSE);
	
		//re draw window (next state: ::OnPaint)
		InvalidateRect(NULL,false); 


	}


	CDialogEx::OnTimer(nIDEvent);
}


void StatusNetworkOther::OnCbnSelchangeComboGraphMode()
{
	// TODO: Add your control notification handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
	int getcur = m_graphTime.GetCurSel();

	m_graphTool.m_graphMode = (enum SysGraphMode_t)getcur;

		
	switch (m_graphTool.m_graphMode) {
	case GRAPH_MODE_HOUR:
		m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_HOUR;
		m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_HOUR;
		xStr = hourStr;
		break;
	case GRAPH_MODE_DAY:
		m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_DAY;
		m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_DAY;
		xStr = dayStr;
		break;
	case GRAPH_MODE_WEEK:
		m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_WEEK;
		m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_WEEK;
		xStr = weekStr;
		break;
	case GRAPH_MODE_MONTH:
		m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_MONTH;
		m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_MONTH;
		xStr = monthStr;
		break;
	case GRAPH_MODE_YEAR:
		m_graphTool.m_axisPara.xAxisNumPoint = NUMS_POINT_YEAR;
		m_graphTool.m_axisPara.xPenNumPoint = NUMS_POINT_YEAR;
		xStr = yearStr;
		break;
	default:
		break;
	}

	m_graphTool.m_axisPara.xText.clear();
	for(int i = 0; i < m_graphTool.m_axisPara.xAxisNumPoint; i++){
		m_graphTool.m_axisPara.xText.push_back(xStr[i]);
	}


	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}
