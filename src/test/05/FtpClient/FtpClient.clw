; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFtpClientView
LastTemplate=CTreeView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FtpClient.h"
LastPage=0

ClassCount=7
Class1=CFtpClientApp
Class2=CFtpClientDoc
Class3=CFtpClientView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CMsgShow
Class7=CFileTree
Resource2=IDD_FLOAT_DLG
Resource3=IDR_MAINFRAME

[CLS:CFtpClientApp]
Type=0
HeaderFile=FtpClient.h
ImplementationFile=FtpClient.cpp
Filter=N

[CLS:CFtpClientDoc]
Type=0
HeaderFile=FtpClientDoc.h
ImplementationFile=FtpClientDoc.cpp
Filter=N

[CLS:CFtpClientView]
Type=0
HeaderFile=FtpClientView.h
ImplementationFile=FtpClientView.cpp
Filter=C
LastObject=CFtpClientView
BaseClass=CListView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=FtpClient.cpp
ImplementationFile=FtpClient.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CMsgShow]
Type=0
HeaderFile=MsgShow.h
ImplementationFile=MsgShow.cpp
BaseClass=CEditView
Filter=C
LastObject=CMsgShow
VirtualFilter=VWC

[CLS:CFileTree]
Type=0
HeaderFile=FileTree.h
ImplementationFile=FileTree.cpp
BaseClass=CTreeView
Filter=C
LastObject=CFileTree
VirtualFilter=VWC

[DLG:IDD_FLOAT_DLG]
Type=1
Class=?
ControlCount=13
Control1=IDC_DISC,edit,1350631552
Control2=IDC_CHOOSEDISC,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CONNECT,button,1342242816
Control10=IDC_IP,edit,1350631552
Control11=IDC_PORT,edit,1350631552
Control12=IDC_NAME,edit,1350631552
Control13=IDC_PASSWORD,edit,1350631552

[MNU:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

