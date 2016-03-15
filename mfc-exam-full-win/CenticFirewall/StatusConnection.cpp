// StatusConnection.cpp : implementation file
//

#include "stdafx.h"
#include "CenticFirewall.h"
#include "StatusConnection.h"
#include "afxdialogex.h"
#include "colorstatic.h"

static protocol_t  listProtocol[] = {
	{PROTOCOL_ICMP, (char*)"ICMP"},
	{PROTOCOL_TCP, (char*)"TCP"},
	{PROTOCOL_UDP, (char*)"UDP"},
	{PROTOCOL_GRE, (char*)"GRE"},
	{PROTOCOL_AH, (char*)"AH"},
	{PROTOCOL_ESP, (char*)"ESP"},
	{PROTOCOL_GGP, (char*)"GGP"},
	{PROTOCOL_HMP, (char*)"HMP"},
	{PROTOCOL_IGMP, (char*)"IGMP"},
	{PROTOCOL_RVD, (char*)"RVD"},
	{PROTOCOL_OSPF, (char*)"OSPF"},
	{PROTOCOL_PUP, (char*)"PUP"},
	{PROTOCOL_RDP, (char*)"RDP"},
	{PROTOCOL_RSVP, (char*)"RSVP"},
};


static conn_status_t  listStatus[] = {
	{CONN_LISTEN, (char*)"LISTEN"},
	{CONN_SYN_SENT, (char*)"SYN-SENT"},
	{CONN_SYN_RECEIVED, (char*)"SYN-RECEIVED"},
	{CONN_ESTABLISHED, (char*)"ESTABLISHED"},
	{CONN_FIN_WAIT_1, (char*)"FIN-WAIT-1"},
	{CONN_FIN_WAIT_2, (char*)"FIN-WAIT-2"},
	{CONN_CLOSE_WAIT, (char*)"CLOSE-WAIT"},
	{CONN_CLOSING, (char*)"CLOSING"},
	{CONN_LAST_ACK, (char*)"LAST-ACK"},
	{CONN_TIME_WAIT, (char*)"TIME-WAIT"},
	{CONN_CLOSED, (char*)"CLOSED"},
};











// StatusConnection dialog

IMPLEMENT_DYNAMIC(StatusConnection, CDialogEx)

StatusConnection::StatusConnection(CWnd* pParent /*=NULL*/)
	: CDialogEx(StatusConnection::IDD, pParent)
{

}

StatusConnection::~StatusConnection()
{
}

void StatusConnection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_LAN, m_lanColor);
	DDX_Control(pDX, IDC_STATIC_INTERNET, m_netColor);
	DDX_Control(pDX, IDC_STATIC_DMZ, m_dmzColor);
	DDX_Control(pDX, IDC_STATIC_FIREWALL, m_firewallColor);
	DDX_Control(pDX, IDC_STATIC_IPSEC, m_ipsecColor);
	DDX_Control(pDX, IDC_STATIC_SSLVPN, m_sslvpnColor);
	DDX_Control(pDX, IDC_STATIC_MULTICAST, m_multicastColor);
	DDX_Control(pDX, IDC_LIST_CONNECTION_TRACK, m_connectionTable);
}


BEGIN_MESSAGE_MAP(StatusConnection, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_SHOWWINDOW()
	ON_MESSAGE((WM_QUICKLIST_GETLISTITEMDATA + WM_QUICKLIST_CONNECTION_TRACK), OnGetConnectionTrackListItem) 
END_MESSAGE_MAP()


// StatusConnection message handlers


BOOL StatusConnection::OnInitDialog()
{
	m_resizeHelper.Init(m_hWnd);
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	 m_lanColor.SetBkColor(LAN_COLOR);	 
	 m_netColor.SetBkColor(NET_COLOR);
	 m_dmzColor.SetBkColor(DMZ_COLOR);
	 m_firewallColor.SetBkColor(FIREWALL_COLOR);
	 m_ipsecColor.SetBkColor(IPSEC_COLOR);
	 m_sslvpnColor.SetBkColor(SSLVPN_COLOR);
	 m_multicastColor.SetBkColor(MULTICAST_COLOR);


	 m_lanColor.SetTextColor(WHITE);	 
	 m_netColor.SetTextColor(WHITE);
	 m_dmzColor.SetTextColor(WHITE);
	 m_firewallColor.SetTextColor(WHITE);
	 m_ipsecColor.SetTextColor(WHITE);
	 m_sslvpnColor.SetTextColor(WHITE);
	 m_multicastColor.SetTextColor(WHITE);

	 //connection tables
	CString m_strTmp;
	m_strTmp.LoadString(IDS_PROTOCOL);
	m_connectionTable.InsertColumn(0, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT/3);

	m_strTmp.LoadString(IDS_SOURCE_IP);
	m_connectionTable.InsertColumn(1, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);

	m_strTmp.LoadString(IDS_SOURCE_PORT);
	m_connectionTable.InsertColumn(2, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT/3);

	m_strTmp.LoadString(IDS_DEST_IP);
	m_connectionTable.InsertColumn(3, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT);

	m_strTmp.LoadString(IDS_DEST_PORT);
	m_connectionTable.InsertColumn(4, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT/3);

	m_strTmp.LoadString(IDS_UPDOWN_SPEED);
	m_connectionTable.InsertColumn(5, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT/2);

	m_strTmp.LoadString(IDS_CONNECTION_STATUS);
	m_connectionTable.InsertColumn(6, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT*2/3);

	m_strTmp.LoadString(IDS_EXPIRES);
	m_connectionTable.InsertColumn(7, m_strTmp, LVCFMT_CENTER, CQUICKLIST_WIDTH_DEFAULT/2);

	m_connectionTable.SetSendMgsId(WM_QUICKLIST_CONNECTION_TRACK);
	m_connectionTable.SetItemCount(0);

	ListView_SetExtendedListViewStyleEx(m_connectionTable.m_hWnd, LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void StatusConnection::OnSize(UINT nType, int cx, int cy)
{

	m_resizeHelper.OnSize();
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void StatusConnection::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData(TRUE);
}


void StatusConnection::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	SetTimer (TIMER_IDEVENT_DEFAULT, TIMER_ELAPSE_5S, NULL);
}


void StatusConnection::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == TIMER_IDEVENT_DEFAULT){

		
		//update interface status
		if(ctSoapEngine.getStatusConnection(&m_connTableData)){
			//update current list if
			TRACE(L"StatusConnection::OnTimer new\n");

		}else{
			//clear all current list if
			TRACE(L"StatusConnection::OnTimer clear\n");
			
			m_connTableData.clear();			
		}

		UpdateList();
		
	}
	CDialogEx::OnTimer(nIDEvent);
}


void StatusConnection::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	KillTimer(TIMER_IDEVENT_DEFAULT);
}


//Get item data
LRESULT StatusConnection::OnGetConnectionTrackListItem(WPARAM wParam, LPARAM lParam)
{
	//wParam is a handler to the list
	//Make sure message comes from list box
	ASSERT( (HWND)wParam == m_connectionTable.GetSafeHwnd() );

	//lParam is a pointer to the data that is needed for the element
	CQuickList::CListItemData* data = (CQuickList::CListItemData*) lParam;

	//Get which item and subitem that is asked for.
	int item = data->GetItem();
	int subItem = data->GetSubItem();
	std::stringstream tmp;

	static int numPro = sizeof(listProtocol)/sizeof(protocol_t);
	static int numStatus = sizeof(listStatus)/sizeof(conn_status_t) ;
	int i;

	//TRACE(_T("Get item %d, subitem %d \n"), item, subItem);
	//data->m_text.Format(_T("lan item %d-%d "), item, subItem);
	switch(subItem){
	case 0://protocol
		//data->m_text = CString(m_servicesTableData.at(item).name.c_str());
		for(i = 0; i < numPro; i++){
			if(listProtocol[i].protocol == m_connTableData.at(item).protocol){
				data->m_text = CString(listProtocol[i].name);
				break;
			}else{
				data->m_text.Format(_T("UNKNOWN"));
			}
		}
		break;
	case 1://Src IP
		data->m_text = CString(m_connTableData.at(item).sip.c_str());

		data->m_colors.m_textColor =			WHITE;
		data->m_colors.m_backColor =			getColorLegend(m_connTableData.at(item).slegend);

		break;
	case 2://Src Port
		tmp <<m_connTableData.at(item).sport;
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();

		data->m_colors.m_textColor =			WHITE;
		data->m_colors.m_backColor =			getColorLegend(m_connTableData.at(item).slegend);

		break;
	case 3://Dest IP
		data->m_text = CString(m_connTableData.at(item).dip.c_str());

		data->m_colors.m_textColor =			WHITE;
		data->m_colors.m_backColor =			getColorLegend(m_connTableData.at(item).dlegend);;
		break;
	case 4://Dest port
		tmp <<m_connTableData.at(item).dport;
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();

		data->m_colors.m_textColor =			WHITE;
		data->m_colors.m_backColor =			getColorLegend(m_connTableData.at(item).dlegend);

		break;
	case 5://Download/upload speed
		tmp <<m_connTableData.at(item).downSpeed
			<< " kB/ "
			<<m_connTableData.at(item).upSpeed
			<< " kB";
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	case 6://Connection status
		for(i = 0; i < numStatus; i++){
			if(listStatus[i].status == m_connTableData.at(item).connStatus){
				data->m_text = CString(listStatus[i].name);
				break;
			}else{
				data->m_text.Format(_T("UNKNOWN"));
			}
		}
		break;
	case 7://Expires (Secs)
		tmp <<m_connTableData.at(item).expires;
		data->m_text = CString(tmp.str().c_str());
		tmp.clear();
		break;
	default:
		break;
	}


	return 0;
}


void StatusConnection::UpdateList(void)
{
	TRACE(L"StatusConnection::UpdateList numItem: %d\n", (int)m_connTableData.size());
	m_connectionTable.LockWindowUpdate();
	m_connectionTable.SetItemCount((int)m_connTableData.size());
	m_connectionTable.UnlockWindowUpdate();
	m_connectionTable.RedrawItems(m_connectionTable.GetTopIndex(),
			m_connectionTable.GetTopIndex()+m_connectionTable.GetCountPerPage());

	m_connectionTable.LockWindowUpdate();
	m_connectionTable.SetItemCount((int)m_connTableData.size());
	m_connectionTable.UnlockWindowUpdate();
	m_connectionTable.RedrawItems(m_connectionTable.GetTopIndex(),
			m_connectionTable.GetTopIndex()+m_connectionTable.GetCountPerPage());
}

COLORREF StatusConnection::getColorLegend(int legend)
{
	//LEGEND_LAN = 0,
	//LEGEND_INTERNET,
	//LEGEND_DMZ,
	//LEGEND_FIREWALL,
	//LEGEND_IPSEC,
	//LEGEND_SSLVPN,
	//LEGEND_MULTICAST,
	COLORREF color;

	switch(legend)
	{
	case LEGEND_LAN:
		color = LAN_COLOR;
		break;
	case LEGEND_INTERNET:
		color = NET_COLOR;
		break;
	case LEGEND_DMZ:
		color = DMZ_COLOR;
		break;
	case LEGEND_FIREWALL:
		color = FIREWALL_COLOR;
		break;
	case LEGEND_IPSEC:
		color = IPSEC_COLOR;
		break;
	case LEGEND_SSLVPN:
		color = SSLVPN_COLOR;
		break;
	case LEGEND_MULTICAST:
		color = MULTICAST_COLOR;
		break;
	default:
		break;
	}

	return color;
}
