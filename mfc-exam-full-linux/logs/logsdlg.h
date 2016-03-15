#ifndef LOGSDLG_H
#define LOGSDLG_H

#include "logsfwloggraphcountry.h"
#include "logsfwloggraphip.h"
#include "logsfwloggraphport.h"
#include "logsfwlogs.h"
#include "logsids.h"
#include "logsproxylogs.h"
#include "logsproxyreports.h"
#include "logssettings.h"
#include "logssummary.h"
#include "logssystem.h"
#include "logsurlfilter.h"
#include "common.h"

class LogsDlg
{
public:
	LogsDlg();
	virtual ~LogsDlg();

public:
	LogsFwLoggraphCountry m_LogsFwLoggraphCountry;
	LogsFwLoggraphIP m_LogsFwLoggraphIP;
	LogsFwLoggraphPort m_LogsFwLoggraphPort;
	LogsFwLogs m_LogsFwLogs;
	LogsIDS m_LogsIDS;
	LogsProxyLogs m_LogsProxyLogs;
	LogsProxyReports m_LogsProxyReports;
	LogsSettings m_LogsSettings;
	LogsSummary m_LogsSummary;
	LogsSystem m_LogsSystem;
	LogsURLFilter m_LogsURLFilter;

};

#endif // LOGSDLG_H
