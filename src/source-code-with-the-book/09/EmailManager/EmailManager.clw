; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReceiveDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "emailmanager.h"
LastPage=0

ClassCount=8
Class1=CBitButtonNL
Class2=CEmailManagerApp
Class3=CAboutDlg
Class4=CEmailManagerDlg
Class5=CSetDlg

ResourceCount=6
Resource1=IDD_EMAILMANAGER_DIALOG
Resource2=IDD_ABOUTBOX
Resource3=IDD_SET
Class6=CReceiveDlg
Resource4=IDD_RECVDLG
Class7=CProgressDlg
Resource5=IDD_PROGRESS
Class8=CSendDlg
Resource6=IDD_SEND

[CLS:CBitButtonNL]
Type=0
BaseClass=CButton
HeaderFile=BitButtonNL.h
ImplementationFile=BitButtonNL.cpp
Filter=W
VirtualFilter=BWC
LastObject=CBitButtonNL

[CLS:CEmailManagerApp]
Type=0
BaseClass=CWinApp
HeaderFile=EmailManager.h
ImplementationFile=EmailManager.cpp
LastObject=CEmailManagerApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=EmailManagerDlg.cpp
ImplementationFile=EmailManagerDlg.cpp

[CLS:CEmailManagerDlg]
Type=0
BaseClass=CDialog
HeaderFile=EmailManagerDlg.h
ImplementationFile=EmailManagerDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CEmailManagerDlg

[CLS:CSetDlg]
Type=0
BaseClass=CDialog
HeaderFile=SetDlg.h
ImplementationFile=SetDlg.cpp
LastObject=CSetDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EMAILMANAGER_DIALOG]
Type=1
Class=CEmailManagerDlg
ControlCount=3
Control1=IDC_RECEIVE,button,1342242816
Control2=IDC_SEND,button,1342242816
Control3=IDC_SET,button,1342242816

[DLG:IDD_SET]
Type=1
Class=CSetDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_IP,edit,1350631552
Control4=IDC_USERNAME,edit,1350631552
Control5=IDC_PASSWORD,edit,1350631584
Control6=IDC_SERVER_IP,button,1342275584
Control7=IDC_USER,button,1342275584
Control8=IDC_PASSWD,button,1342275584

[DLG:IDD_RECVDLG]
Type=1
Class=CReceiveDlg
ControlCount=4
Control1=IDC_UPDATE,button,1342242816
Control2=IDC_CLEAR,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_EDIT1,edit,1350631556

[CLS:CReceiveDlg]
Type=0
HeaderFile=ReceiveDlg.h
ImplementationFile=ReceiveDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[DLG:IDD_PROGRESS]
Type=1
Class=CProgressDlg
ControlCount=1
Control1=IDC_MSG,static,1342308352

[CLS:CProgressDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProgressDlg

[DLG:IDD_SEND]
Type=1
Class=CSendDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RECV,edit,1350631552
Control5=IDC_SUBJECT,edit,1350631552
Control6=IDC_FILE,edit,1350631552
Control7=IDC_CONTEXT,edit,1350631556
Control8=IDC_BTNSEND,button,1342242816
Control9=IDC_CLEAR,button,1342242816
Control10=IDC_APPEND,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_SMTP_IP,edit,1350631552

[CLS:CSendDlg]
Type=0
HeaderFile=SendDlg.h
ImplementationFile=SendDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSendDlg
VirtualFilter=dWC

