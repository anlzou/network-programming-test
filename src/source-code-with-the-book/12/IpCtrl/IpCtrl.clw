; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIpCtrlDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "IpCtrl.h"

ClassCount=2
Class1=CIpCtrlApp
Class2=CIpCtrlDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_IPCTRL_DIALOG

[CLS:CIpCtrlApp]
Type=0
HeaderFile=IpCtrl.h
ImplementationFile=IpCtrl.cpp
Filter=N

[CLS:CIpCtrlDlg]
Type=0
HeaderFile=IpCtrlDlg.h
ImplementationFile=IpCtrlDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_IPADDRESS1



[DLG:IDD_IPCTRL_DIALOG]
Type=1
Class=CIpCtrlDlg
ControlCount=3
Control1=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control2=IDC_GETIP,button,1342242816
Control3=IDC_CLEARIP,button,1342242816

