#pragma once
#include "dlgresizehelper.h"
#include "gSoapEngine.h"
#include "afxcmn.h"
#include "colorstatic.h"
#include "quicklist.h"
#include <sstream>
#include <string>

#define	 LAN_COLOR			RGB(51, 153, 51)  
#define	 NET_COLOR			RGB(153, 51, 51)
#define	 DMZ_COLOR			RGB(255, 153, 51)
#define	 FIREWALL_COLOR		RGB(0, 0, 0)
#define	 IPSEC_COLOR		RGB(153, 0, 153)
#define	 SSLVPN_COLOR		RGB(51, 153, 153)
#define	 MULTICAST_COLOR	RGB(160, 160, 160)

enum {
	PROTOCOL_ICMP =1,
	PROTOCOL_TCP =6,
	PROTOCOL_UDP = 17,
	PROTOCOL_GRE = 47,
	PROTOCOL_AH = 51,
	PROTOCOL_ESP = 8,
	PROTOCOL_GGP = 3,
	PROTOCOL_HMP = 20,
	PROTOCOL_IGMP = 88,
	PROTOCOL_RVD = 66,
	PROTOCOL_OSPF = 89,
	PROTOCOL_PUP = 12,
	PROTOCOL_RDP = 27,
	PROTOCOL_RSVP = 46,
};

enum {
	CONN_LISTEN = 0,
	CONN_SYN_SENT,
	CONN_SYN_RECEIVED,
	CONN_ESTABLISHED,
	CONN_FIN_WAIT_1,
	CONN_FIN_WAIT_2,
	CONN_CLOSE_WAIT,
	CONN_CLOSING,
	CONN_LAST_ACK,
	CONN_TIME_WAIT,
	CONN_CLOSED,
};



typedef struct {
	int protocol;
	char name[32];
}protocol_t;

typedef struct {
	int status;
	char name[32];
}conn_status_t;

// StatusConnection dialog

class StatusConnection : public CDialogEx
{
	DECLARE_DYNAMIC(StatusConnection)

public:
	StatusConnection(CWnd* pParent = NULL);   // standard constructor
	virtual ~StatusConnection();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS_CONNECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//For Resize window
	DlgResizeHelper m_resizeHelper;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	CColorStatic m_lanColor;
	CColorStatic m_netColor;
	CColorStatic m_dmzColor;
	CColorStatic m_firewallColor;
	CColorStatic m_ipsecColor;
	CColorStatic m_sslvpnColor;
	CColorStatic m_multicastColor;

	CQuickList m_connectionTable;
	StatusConnList_t m_connTableData;
	afx_msg LRESULT OnGetConnectionTrackListItem(WPARAM wParam, LPARAM lParam);
	void UpdateList(void);
	COLORREF getColorLegend(int legend);
};
