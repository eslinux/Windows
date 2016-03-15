// StatusServices.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusServices.h"
#include "afxdialogex.h"


// StatusServices dialog

IMPLEMENT_DYNAMIC(StatusServices, CDialogEx)

StatusServices::StatusServices(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusServices::IDD, pParent)
{

}

StatusServices::~StatusServices()
{
}

void StatusServices::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SERVICES, m_servicesTable);
}


BEGIN_MESSAGE_MAP(StatusServices, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_MESSAGE((WM_QUICKLIST_GETLISTITEMDATA + WM_QUICKLIST_SERVICES), OnGetServicesListItem) 
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// StatusServices message handlers


BOOL StatusServices::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);

	CString m_strTmp;
	m_strTmp.LoadString(IDS_SERVICES);
	m_servicesTable.InsertColumn(0, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT*2);

	m_strTmp.LoadString(IDS_STATUS);
	m_servicesTable.InsertColumn(1, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT-50);

	m_strTmp.LoadString(IDS_PID);
	m_servicesTable.InsertColumn(2, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT-50);

	m_strTmp.LoadString(IDS_MEMORY);
	m_servicesTable.InsertColumn(3, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT-50);

	m_servicesTable.SetSendMgsId(WM_QUICKLIST_SERVICES);
	m_servicesTable.SetItemCount(0);

	ListView_SetExtendedListViewStyleEx(m_servicesTable.m_hWnd, LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusServices::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void StatusServices::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}





//Get item data
LRESULT StatusServices::OnGetServicesListItem(WPARAM wParam, LPARAM lParam)
{
	//wParam is a handler to the list
	//Make sure message comes from list box
	ASSERT( (HWND)wParam == m_servicesTable.GetSafeHwnd() );

	//lParam is a pointer to the data that is needed for the element
	CQuickList::CListItemData* data = (CQuickList::CListItemData*) lParam;

	//Get which item and subitem that is asked for.
	int item = data->GetItem();
	int subItem = data->GetSubItem();
	std::stringstream tmp;

	//TRACE(_T("Get item %d, subitem %d \n"), item, subItem);
	//data->m_text.Format(_T("lan item %d-%d "), item, subItem);
	switch(subItem){
	case 0://services
		data->m_text = CString(m_servicesTableData.at(item).name.c_str());
		break;
	case 1://status
		//data->m_text = CString(m_ifList.netIfList.at(item).ip.c_str());
		//data->m_text.Format(_T("%s"), m_servicesTableData.at(item).isRunning?"RUNNING":"STOP");
		if(m_servicesTableData.at(item).isRunning){
			tmp << "RUNNING";
		}else{
			tmp << "STOPPED";
		}
		
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();

		if(m_servicesTableData.at(item).isRunning){
			data->m_colors.m_textColor =			RGB( 255, 255, 255);
			data->m_colors.m_backColor =			RGB( 0, 150, 0);
		}else{
			data->m_colors.m_textColor =			RGB( 255, 255, 255);
			data->m_colors.m_backColor =			RGB( 150, 0, 0);
		}
		break;
	case 2://PID
		tmp <<m_servicesTableData.at(item).pid;
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	case 3://Memory
		tmp <<m_servicesTableData.at(item).memory << " kB";
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	default:
		break;
	}

	
			

	return 0;
}



void StatusServices::UpdateList(void)
{
	TRACE(L"StatusServices::UpdateList \n");
	m_servicesTable.LockWindowUpdate();
	m_servicesTable.SetItemCount((int)m_servicesTableData.size());
	m_servicesTable.UnlockWindowUpdate();
	m_servicesTable.RedrawItems(m_servicesTable.GetTopIndex(),
			m_servicesTable.GetTopIndex()+m_servicesTable.GetCountPerPage());

	m_servicesTable.LockWindowUpdate();
	m_servicesTable.SetItemCount((int)m_servicesTableData.size());
	m_servicesTable.UnlockWindowUpdate();
	m_servicesTable.RedrawItems(m_servicesTable.GetTopIndex(),
			m_servicesTable.GetTopIndex()+m_servicesTable.GetCountPerPage());
}


void StatusServices::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	// get and update services status
	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
	


}
void StatusServices::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}


void StatusServices::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		
		//update interface status
		if(ctSoapEngine.getStatusServices(&m_servicesTableData)){
			//update current list if
			TRACE(L"StatusServices::OnTimer new\n");

		}else{
			//clear all current list if
			TRACE(L"StatusServices::OnTimer clear\n");
			
			m_servicesTableData.clear();			
		}

		UpdateList();
		
	}
	CDialogEx::OnTimer(nIDEvent);
}
