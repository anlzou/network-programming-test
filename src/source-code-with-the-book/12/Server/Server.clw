; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=3
Class1=CServerApp
Class2=CServerDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CMySocket
Resource2=IDD_SERVER_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg



[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=3
Control1=IDC_LISTUSER,SysListView32,1350631425
Control2=IDC_CTX,edit,1350631492
Control3=IDC_BTNRUN,button,1342242827

[CLS:CMySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CMySocket
VirtualFilter=uq

