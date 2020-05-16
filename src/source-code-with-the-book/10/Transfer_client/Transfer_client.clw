; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTransfer_clientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Transfer_client.h"

ClassCount=4
Class1=CTransfer_clientApp
Class2=CTransfer_clientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TRANSFER_CLIENT_DIALOG

[CLS:CTransfer_clientApp]
Type=0
HeaderFile=Transfer_client.h
ImplementationFile=Transfer_client.cpp
Filter=N

[CLS:CTransfer_clientDlg]
Type=0
HeaderFile=Transfer_clientDlg.h
ImplementationFile=Transfer_clientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Transfer_clientDlg.h
ImplementationFile=Transfer_clientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TRANSFER_CLIENT_DIALOG]
Type=1
Class=CTransfer_clientDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_CONNECT,button,1342242816
Control3=IDC_SENDFILE,button,1342242816
Control4=IDC_RECVFILE,button,1342242816

