; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "网络通信Client.h"

ClassCount=3
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CLIENT_DIALOG

[CLS:CClientApp]
Type=0
HeaderFile=网络通信Client.h
ImplementationFile=网络通信Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=网络通信ClientDlg.h
ImplementationFile=网络通信ClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CClientDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=网络通信ClientDlg.h
ImplementationFile=网络通信ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_RECV,edit,1352728580
Control3=IDC_SEND,edit,1350631552
Control4=IDC_SENDBTN,button,1342242816
Control5=IDC_CONNECT,button,1342242816
Control6=IDC_IP,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

