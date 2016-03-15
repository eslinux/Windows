#import "stllist.h"
#import "stlvector.h"
#import "stldeque.h"

//gsoap ns service name:	ctSoap
//gsoap ns service style:	rpc
//gsoap ns service encoding:	encoded
//gsoap ns service namespace:	https://localhost:8085/ctSoap.wsdl
//gsoap ns service location:	https://localhost:8085

//gsoap ns schema  namespace:	urn:ctSoap

//gsoap ns schema type-documentation: Data contains DIME attachment data


//==============================================================================
// dime stream binary file
// support for get log file, update firmware
//==============================================================================
class ns__Data
{
	unsigned char *__ptr; /* points to data */
	int __size;		/* size of data */
	char *id;		/* ctSoap attachment ID (set to NULL to obtain unique cid) */
	char *type;		/* ctSoap attachment content type */
	char *options;	/* ctSoap attachment options (optional) */
	ns__Data();
	struct soap *soap;	/* soap context that created this instance */
};

class arrayOfData	/* SOAP array of data */
{
	ns__Data *__ptr;
	int __size;
	arrayOfData();
	arrayOfData(struct soap*, int);
	virtual ~arrayOfData();
	int size();
	void resize(int);
	ns__Data& operator[](int) const;
	struct soap *soap;
};

class arrayOfName	/* SOAP array of strings */
{
	char **__ptr;
	int __size;
	arrayOfName();
	arrayOfName(struct soap*, int);
	virtual ~arrayOfName();
	int size();
	void resize(int);
	char*& operator[](int) const;
	struct soap *soap;
};


int ns__putData(std::vector<std::string> *nameList, arrayOfData *data, arrayOfName *names);
int ns__getData(arrayOfName *names, arrayOfData *data);
int ns__getImage(char *name, ns__Data &image);

//==============================================================================
// Common
//==============================================================================
struct ns__noResponse { };




//==============================================================================
// Login
//==============================================================================
int ns__login(char *username, char *passwd, bool *ret);




//==============================================================================
// CenticFirewallRuntime
// Get runtime information: connection status to device, traffic info (in/out speed)
//==============================================================================
class RuntimeInfo_t {
	bool isConnected;
	float inSpeed;
	float outSpeed;
};
int ns__getRuntimeInfo(void *, RuntimeInfo_t *ret);

//==============================================================================
// System
//==============================================================================
// System::Home
// Get list of interface
class IfInfot_t{
	std::string ifname, ip, netmask, mac;
	int mtu;
};
class NetInterface_t {
	//lan if info
	std::vector<IfInfot_t> lanIfList;

	//net if info
	std::vector<IfInfot_t> netIfList;
	std::string gw;
	std::string dns;
} ;
int ns__getSysHomeInterface(void *, NetInterface_t *ret);


// System::Backup
// Backup and restore configuration & firmware
enum ns__SysBackupEvent {
	EVENT_NONE = -5,
	EVENT_GET_FILENAME_CONFIG = -4,
	EVENT_GET_FILENAME_FIRMWARE = -3,
	EVENT_SET_FILENAME_CONFIG = -2,
	EVENT_SET_FILENAME_FIRMWARE = -1,
	EVENT_BACKUP_CONFIGURATION = 0,
	EVENT_UPDATE_CONFIGURATION,
	EVENT_BACKUP_FIRMWARE,
	EVENT_UPDATE_FIRMWARE
};
class SysBackupRet_t {
	std::string filename;
} ;
int ns__SysBackupHandle(enum ns__SysBackupEvent in, char *path, SysBackupRet_t *ret);


// System::SystemInformation
// Get system information
class SysInfo_t {
	std::string ctfw_version;
	std::string cpu;
	std::string memory;
	//more info for addition
} ;
int ns__getSysSysInfo(void *, SysInfo_t *ret);


// System::Shutdown
// Logout, reboot, shutdown
enum ns__SysShutdownEvent {
	EVENT_SHUTDOWN = 0,
	EVENT_REBOOT,
	EVENT_LOGOUT,
};
int ns__SysShutdownHandle(enum ns__SysShutdownEvent in, struct ns__noResponse *out);








//==============================================================================
// Status
//==============================================================================
// Status::system
// get CPU and Memory percent list

enum SysGraphMode_t{
	GRAPH_MODE_HOUR = 0,
	GRAPH_MODE_DAY,
	GRAPH_MODE_WEEK,
	GRAPH_MODE_MONTH,
	GRAPH_MODE_YEAR,
};
enum SysGraphNumPoint_t{
	NUMS_POINT_HOUR = 7,
	NUMS_POINT_DAY = 13,
	NUMS_POINT_WEEK = 7,
	NUMS_POINT_MONTH = 12,
	NUMS_POINT_YEAR = 6,
};

class GraphData_t{
	std::vector<int> grapData;
};
//typedef std::vector<GraphData_t> GraphListData_t;/*for multi pen*/

class SystemData_t{
	std::vector<GraphData_t> cpuData; //one pen
	std::vector<GraphData_t> memoryData;//one pen
} ;
int ns__getStatusSystemGraph(enum SysGraphMode_t mode, SystemData_t *ret);

// Status::Network
// Get external/internal/firewall network traffic
class NetTraffic_t{
	float max;
	float avg;
	float min;
	float current;
};
class NetworkData_t{
	std::vector<GraphData_t> graphListData; /*for multi pen*/
	std::vector<NetTraffic_t> netListTraffic; /*incoming/outcoming/...*/
};


int ns__getStatusNetworkExternal(enum SysGraphMode_t mode, NetworkData_t *ret);/*get multi data for multi pen*/
int ns__getStatusNetworkInternal(enum SysGraphMode_t mode, NetworkData_t *ret);/*get multi data for multi pen*/
int ns__getStatusNetworkOther(enum SysGraphMode_t mode, NetworkData_t *ret);/*get multi data for multi pen*/



// Status::Services
// Get services running status
class StatusServices_t{
	std::string name;
	bool isRunning;
	int pid;
	float memory;
};
typedef std::vector<StatusServices_t> StatusServicesList_t;
int ns__getStatusServices(void *, StatusServicesList_t *ret);


// Status::Connection
// Get IPtables connection track
enum legend_t{
	LEGEND_LAN = 0,
	LEGEND_INTERNET,
	LEGEND_DMZ,
	LEGEND_FIREWALL,
	LEGEND_IPSEC,
	LEGEND_SSLVPN,
	LEGEND_MULTICAST,
};
class ConnTrack_t{
	int protocol;
	std::string sip, dip; /*source/destination IP*/
	int sport, dport;/*source/destination port*/
	float downSpeed, upSpeed;
	int connStatus;
	float expires;
	int slegend;
	int dlegend;
};
typedef std::vector<ConnTrack_t> StatusConnList_t;
int ns__getStatusConnection(void *, StatusConnList_t *ret);





//==============================================================================
// Network
//==============================================================================


//==============================================================================
// Services
//==============================================================================


//==============================================================================
// Firewall
//==============================================================================


//==============================================================================
// Logs
//==============================================================================


//==============================================================================
// Settings
//==============================================================================

