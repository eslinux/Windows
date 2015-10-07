
Content:
1 Tab Control
2 IP Control
3 Net Address Control
4 H.Scroll Control
5 V.Scroll Control
6 Progress Bar Control
7 ListBox Control
8 Combo-box Control
9 Radio-button Control
10 Check-box Control
11 Menu bar

12 Open & Save File Dialog
13 Timer
14 Draw witch CDC
15 Multi Dialog with Tab Control
16 MultiThread

17 DoModal (active online window) 
   DoModaless (active multi window with .ShowWindow and .SetWindowPos function)
18 USing Class Wizard (Ctrl+Shift+X) to declaration/remove variable for Widget Control and class, ...
   Using Solution Explorer, Class View to browser source code and class function/variable
   Using Resource View to create new dialog, menu, string table, icon, ...
19 Using UpdateData(TRUE) : update data from Widget Control to variable (CString, int, float, ...)
         UpdateData(FALSE) : update data from variable up to Widget Control (CEDit, Radio, CheckBox, ...)
20 Run in Debug mode to enable trace message
          Release mode to disable trace message
    TRACE(traceAppMsg, 0, "address %x \n", address);
	CString strNetAdd;
	MessageBox(strNetAdd);
	MessageBox(_T("hello world"));
	MessageBox(L"hello world");


