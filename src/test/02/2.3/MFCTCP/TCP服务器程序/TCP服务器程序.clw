; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTCPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TCP服务器程序.h"

ClassCount=3
Class1=CTCPApp
Class2=CTCPDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TCP_DIALOG

[CLS:CTCPApp]
Type=0
HeaderFile=TCP服务器程序.h
ImplementationFile=TCP服务器程序.cpp
Filter=N

[CLS:CTCPDlg]
Type=0
HeaderFile=TCP服务器程序Dlg.h
ImplementationFile=TCP服务器程序Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SEND

[CLS:CAboutDlg]
Type=0
HeaderFile=TCP服务器程序Dlg.h
ImplementationFile=TCP服务器程序Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TCP_DIALOG]
Type=1
Class=CTCPDlg
ControlCount=4
Control1=IDC_ADDR,static,1342308352
Control2=IDC_TEXT,edit,1350631556
Control3=IDC_SENDTEXT,edit,1350631552
Control4=IDC_SEND,button,1342242816

