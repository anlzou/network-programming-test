; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "网络通信Server.h"

ClassCount=3
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SERVER_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=网络通信Server.h
ImplementationFile=网络通信Server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=网络通信ServerDlg.h
ImplementationFile=网络通信ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=网络通信ServerDlg.h
ImplementationFile=网络通信ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_STARTRUN,button,1342242816
Control3=IDC_STATUS,static,1342308352
Control4=IDC_RECV,edit,1352728580
Control5=IDC_SEND,edit,1350631552
Control6=IDC_SENDBTN,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

