// SystemHome.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "SystemHome.h"
#include "afxdialogex.h"

#include <sstream>
#include <string>

// SystemHome dialog

IMPLEMENT_DYNAMIC(SystemHome, CDialogEx)

SystemHome::SystemHome(CWnd* pParent /*=NULL*/)
	: CDialogEx(SystemHome::IDD, pParent)
{

}

SystemHome::~SystemHome()
{
}

void SystemHome::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_NET_INTERFACE, m_netInterfaceList);	
	DDX_Control(pDX, IDC_LIST_LAN_INTERFACE, m_lanInterfaceList);
}


BEGIN_MESSAGE_MAP(SystemHome, CDialogEx)
	ON_WM_SIZE()
	ON_MESSAGE((WM_QUICKLIST_GETLISTITEMDATA + WM_QUICKLIST_NET_INTERFACE), OnGetNetListItem) 
	ON_MESSAGE((WM_QUICKLIST_GETLISTITEMDATA + WM_QUICKLIST_LAN_INTERFACE), OnGetLanListItem) 	
//	ON_WM_SHOWWINDOW()
//	ON_WM_PAINT()
ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// SystemHome message handlers


BOOL SystemHome::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_resizeHelper.Init(m_hWnd);


	//Net and Lan Interface
	CString m_strTmp;
	m_strTmp.LoadString(IDS_NETWORK);
	m_netInterfaceList.InsertColumn(0, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);
	m_strTmp.LoadString(IDS_IP_ADDRESS);
	m_netInterfaceList.InsertColumn(1, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);
	m_strTmp.LoadString(IDS_MORE_INFO);
	m_netInterfaceList.InsertColumn(2, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT+150);
	m_netInterfaceList.SetSendMgsId(WM_QUICKLIST_NET_INTERFACE);
	
	m_strTmp.LoadString(IDS_NETWORK);
	m_lanInterfaceList.InsertColumn(0, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);
	m_strTmp.LoadString(IDS_IP_ADDRESS);
	m_lanInterfaceList.InsertColumn(1, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);
	m_strTmp.LoadString(IDS_MORE_INFO);
	m_lanInterfaceList.InsertColumn(2, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT+150);
	m_lanInterfaceList.SetSendMgsId(WM_QUICKLIST_LAN_INTERFACE);

	m_lanInterfaceList.SetItemCount(0);
	m_netInterfaceList.SetItemCount(0);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void SystemHome::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void SystemHome::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(TRUE);

}



//Get item data
LRESULT SystemHome::OnGetNetListItem(WPARAM wParam, LPARAM lParam)
{
	//wParam is a handler to the list
	//Make sure message comes from list box
	ASSERT( (HWND)wParam == m_netInterfaceList.GetSafeHwnd() );

	//lParam is a pointer to the data that is needed for the element
	CQuickList::CListItemData* data = (CQuickList::CListItemData*) lParam;

	//Get which item and subitem that is asked for.
	int item = data->GetItem();
	int subItem = data->GetSubItem();
	std::stringstream tmp;

	//TRACE(_T("Get item %d, subitem %d \n"), item, subItem);
	//data->m_text.Format(_T("lan item %d-%d "), item, subItem);
	switch(subItem){
	case 0://ifname
		data->m_text = CString(m_ifList.netIfList.at(item).ifname.c_str());
		break;
	case 1://IP
		data->m_text = CString(m_ifList.netIfList.at(item).ip.c_str());
		break;
	case 2://more info
		tmp <<"netmask: " << m_ifList.netIfList.at(item).netmask
			<< ", mac: " <<  m_ifList.netIfList.at(item).mac
			<< ", mtu: " << m_ifList.netIfList.at(item).mtu;

		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	default:
		break;

	}

	return 0;

}


LRESULT SystemHome::OnGetLanListItem(WPARAM wParam, LPARAM lParam)
{

	//wParam is a handler to the list
	//Make sure message comes from list box
	ASSERT( (HWND)wParam == m_lanInterfaceList.GetSafeHwnd() );

	//lParam is a pointer to the data that is needed for the element
	CQuickList::CListItemData* data = (CQuickList::CListItemData*) lParam;

	//Get which item and subitem that is asked for.
	int item = data->GetItem();
	int subItem = data->GetSubItem();
	std::stringstream tmp;

	//TRACE(_T("Get item %d, subitem %d \n"), item, subItem);
	
	//data->m_text.Format(_T("lan item %d-%d "), item, subItem);
	switch(subItem){
	case 0://ifname
		data->m_text = CString(m_ifList.lanIfList.at(item).ifname.c_str());
		break;
	case 1://IP
		data->m_text = CString(m_ifList.lanIfList.at(item).ip.c_str());
		break;
	case 2://more info
		tmp <<"netmask: " << m_ifList.lanIfList.at(item).netmask
			<< ", mac: " <<  m_ifList.lanIfList.at(item).mac
			<< ", mtu: " << m_ifList.lanIfList.at(item).mtu;

		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	default:
		break;
	}

	return 0;
}



void SystemHome::UpdateList(void)
{
	TRACE(L"SystemHome::UpdateList \n");
	m_netInterfaceList.LockWindowUpdate();
	m_netInterfaceList.SetItemCount((int) m_ifList.netIfList.size());
	m_netInterfaceList.UnlockWindowUpdate();
	m_netInterfaceList.RedrawItems(m_netInterfaceList.GetTopIndex(),
			m_netInterfaceList.GetTopIndex()+m_netInterfaceList.GetCountPerPage());

	m_lanInterfaceList.LockWindowUpdate();
	m_lanInterfaceList.SetItemCount((int) m_ifList.lanIfList.size());
	m_lanInterfaceList.UnlockWindowUpdate();
	m_lanInterfaceList.RedrawItems(
			m_lanInterfaceList.GetTopIndex(),
			m_lanInterfaceList.GetTopIndex()+m_lanInterfaceList.GetCountPerPage());
}


void SystemHome::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	//TRACE(L"SystemHome::OnPaint SHOW WINDOWS \n");

	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);

}


void SystemHome::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}

void SystemHome::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		
		//update interface status
		if(ctSoapEngine.getSysHomeInterface(&m_ifList)){
			//update current list if
			TRACE(L"SystemHome::OnTimer new\n");

		}else{
			//clear all current list if
			TRACE(L"SystemHome::OnTimer clear\n");
			m_ifList.lanIfList.clear();
			m_ifList.netIfList.clear();			
		}

		UpdateList();
		
	}

	CDialogEx::OnTimer(nIDEvent);
}


