#ifndef SYSTEMDLG_H
#define SYSTEMDLG_H
#include "common.h"

#include "systembackup.h"
#include "systemhome.h"
#include "systemshutdown.h"
#include "systemsysinformation.h"

class SystemDlg
{
public:
	SystemDlg();
	virtual ~SystemDlg();


	SystemBackup m_SystemBackup;
	SystemHome m_SystemHome;
	SystemShutdown m_SystemShutdown;
	SystemSysInformation m_SystemSysInformation;
};

#endif // SYSTEMDLG_H
