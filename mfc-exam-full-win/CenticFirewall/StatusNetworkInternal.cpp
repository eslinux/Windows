// StatusNetworkInternal.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusNetworkInternal.h"
#include "afxdialogex.h"


static const char **xStr;
static const char *yStr[] = {{"0"}, {"20"}, {"40"}, {"60"}, {"80"}, {"100"}};
static const char *hourStr[] = {{"0"}, {"10"}, {"20"}, {"30"}, {"40"}, {"50"}, {"60"}};
static const char *dayStr[] = {{"0"}, {"2"}, {"4"}, {"6"}, {"8"}, {"10"},
{"12"}, {"14"}, {"16"}, {"18"},  {"20"}, {"22"}, {"24"}};
static const char *weekStr[] = {{"Mon"}, {"Tue"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
static const char *monthStr[] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"}};
static const char *yearStr[] = {{"2015"}, {"2016"}, {"2017"}, {"2018"}, {"2019"}, {"2020"}};
	
// StatusNetworkInternal dialog

IMPLEMENT_DYNAMIC(StatusNetworkInternal, CDialogEx)

StatusNetworkInternal::StatusNetworkInternal(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusNetworkInternal::IDD, pParent)
	, m_incomeMax(_T(""))
	, m_incomeAvg(_T(""))
	, m_incomeMin(_T(""))
	, m_incomeCurrent(_T(""))
	, m_outcomeMax(_T(""))
	, m_outcomeAvg(_T(""))
	, m_outcomeMin(_T(""))
	, m_outcomeCurrent(_T(""))
{

}

StatusNetworkInternal::~StatusNetworkInternal()
{
}

void StatusNetworkInternal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GRAPH_MODE, m_graphTime);
	DDX_Control(pDX, IDC_STATIC_INTERNAL_GRAPH, m_graphTool);
	DDX_Text(pDX, IDC_EDIT_INCOME_MAX, m_incomeMax);
	DDX_Text(pDX, IDC_EDIT_INCOME_AVG, m_incomeAvg);
	DDX_Text(pDX, IDC_EDIT_INCOME_MIN, m_incomeMin);
	DDX_Text(pDX, IDC_EDIT_INCOME_CURRENT, m_incomeCurrent);
	DDX_Text(pDX, IDC_EDIT_OUTCOME_MAX, m_outcomeMax);
	DDX_Text(pDX, IDC_EDIT_OUTCOME_AVG, m_outcomeAvg);
	DDX_Text(pDX, IDC_EDIT_OUTCOME_MIN, m_outcomeMin);
	DDX_Text(pDX, IDC_EDIT_OUTCOME_CURRENT, m_outcomeCurrent);
	DDX_Control(pDX, IDC_STATIC_GREEN_COLOR, m_greenColor);
	DDX_Control(pDX, IDC_STATIC_RED_COLOR, m_redColor);
}


BEGIN_MESSAGE_MAP(StatusNetworkInternal, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO_GRAPH_MODE, &StatusNetworkInternal::OnCbnSelchangeComboGraphMode)
END_MESSAGE_MAP()


// StatusNetworkInternal message handlers


BOOL StatusNetworkInternal::OnInitDialog()
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
	m_graphTool.m_listPen[1].CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //outcoming traffic pen
	m_graphTool.m_numPen = 2;

	m_graphTool.m_listData = &(m_networkData.graphListData);


	
	//color note
	m_greenColor.SetBkColor(LIGHTGREEN);
	m_redColor.SetBkColor(LIGHTRED);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusNetworkInternal::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void StatusNetworkInternal::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void StatusNetworkInternal::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}


void StatusNetworkInternal::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}


void StatusNetworkInternal::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		//update
		if(ctSoapEngine.getStatusNetworkInternal(m_graphTool.m_graphMode, &m_networkData)){
			//update current list if
			TRACE(L"StatusNetworkInternal::OnTimer update\n");

		}else{
			//clear all current list if
			TRACE(L"StatusNetworkInternal::OnTimer clear\n");
			m_networkData.graphListData.clear();
			m_networkData.netListTraffic.clear();
		}

		if(m_networkData.netListTraffic.size() > 0){
			m_incomeMax.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).max);
			m_incomeAvg.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).avg);
			m_incomeMin.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).min);
			m_incomeCurrent.Format(_T("%0.1f"), m_networkData.netListTraffic.at(0).current);

			m_outcomeMax.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).max);
			m_outcomeAvg.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).avg);
			m_outcomeMin.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).min);
			m_outcomeCurrent.Format(_T("%0.1f"), m_networkData.netListTraffic.at(1).current);
		}else{
			m_incomeMax.Format(_T("---"));
			m_incomeAvg.Format(_T("---"));
			m_incomeMin.Format(_T("---"));
			m_incomeCurrent.Format(_T("---"));

			m_outcomeMax.Format(_T("---"));
			m_outcomeAvg.Format(_T("---"));
			m_outcomeMin.Format(_T("---"));
			m_outcomeCurrent.Format(_T("---"));
		}

		UpdateData(FALSE);
	
		//re draw window (next state: ::OnPaint)
		InvalidateRect(NULL,false); 


	}
	CDialogEx::OnTimer(nIDEvent);
}


void StatusNetworkInternal::OnCbnSelchangeComboGraphMode()
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
