; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTransfer_serverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Transfer_server.h"

ClassCount=3
Class1=CTransfer_serverApp
Class2=CTransfer_serverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TRANSFER_SERVER_DIALOG

[CLS:CTransfer_serverApp]
Type=0
HeaderFile=Transfer_server.h
ImplementationFile=Transfer_server.cpp
Filter=N

[CLS:CTransfer_serverDlg]
Type=0
HeaderFile=Transfer_serverDlg.h
ImplementationFile=Transfer_serverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTransfer_serverDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Transfer_serverDlg.h
ImplementationFile=Transfer_serverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TRANSFER_SERVER_DIALOG]
Type=1
Class=CTransfer_serverDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_STARTRUN,button,1342242816
Control3=IDC_RECVFILE,button,1342242816
Control4=IDC_SENDFILE,button,1342242816

