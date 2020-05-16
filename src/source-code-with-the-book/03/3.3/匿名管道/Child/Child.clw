; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChildDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Child.h"

ClassCount=4
Class1=CChildApp
Class2=CChildDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHILD_DIALOG

[CLS:CChildApp]
Type=0
HeaderFile=Child.h
ImplementationFile=Child.cpp
Filter=N

[CLS:CChildDlg]
Type=0
HeaderFile=ChildDlg.h
ImplementationFile=ChildDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ChildDlg.h
ImplementationFile=ChildDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHILD_DIALOG]
Type=1
Class=CChildDlg
ControlCount=2
Control1=IDC_Read,button,1342242816
Control2=IDC_Write,button,1342242816

