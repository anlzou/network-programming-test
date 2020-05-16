; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=4
Class1=CClientApp
Class2=CClientDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Class3=CMySocket
Resource2=IDD_CLIENT_DIALOG
Class4=CLogDlg
Resource3=IDD_LOGIN

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
LastObject=CClientDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=5
Control1=IDC_LIST,SysListView32,1350631426
Control2=IDC_ECTX,edit,1350631492
Control3=IDC_ESAY,edit,1350631492
Control4=IDC_BTNSEND,button,1342242827
Control5=IDC_CHECK,button,1342242819

[CLS:CMySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CMySocket
VirtualFilter=uq

[DLG:IDD_LOGIN]
Type=1
Class=CLogDlg
ControlCount=4
Control1=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control2=IDC_NAME,edit,1350631552
Control3=IDC_COMBOBOXEX1,ComboBoxEx32,1344340226
Control4=IDC_LOGIN,button,1342242827

[CLS:CLogDlg]
Type=0
HeaderFile=LogDlg.h
ImplementationFile=LogDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLogDlg

