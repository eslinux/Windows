Compile soap header: (import folder copy from gsoap to source code project)
soapcpp2.exe -b -I import ctSoap.h

Note:
- Set all dlg Stype properties to "Child" to handle OnMove event
- Add ::OnOk( ) to avoid Enter keyboard in Edit Control
- List Control (CQuickList) set View properties to "Report", add LVS_OWNERDATA in Debug mode with List Control
- Convert CString <-> std:string, char*
  	CString cs (L"Hello");
	CT2CA pszConvertedAnsiString (cs);
	std::string strStd (pszConvertedAnsiString);
	TRACE("cs %s ", strStd.c_str());

	std::string s("Hello");
	CString cs(s.c_str());

	char strString[] = "this is a char string";
	CString cstring;
	cstring = CString( strString );