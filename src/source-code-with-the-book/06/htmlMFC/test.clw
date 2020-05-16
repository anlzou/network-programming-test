; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test.h"
LastPage=0

ClassCount=6
Class1=CTestApp
Class2=CTestDoc
Class3=CTestView
Class4=CMainFrame

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CMyTool
Resource2=IDR_MAINFRAME

[CLS:CTestApp]
Type=0
HeaderFile=test.h
ImplementationFile=test.cpp
Filter=N

[CLS:CTestDoc]
Type=0
HeaderFile=testDoc.h
ImplementationFile=testDoc.cpp
Filter=N

[CLS:CTestView]
Type=0
HeaderFile=testView.h
ImplementationFile=testView.cpp
Filter=C
LastObject=ID_REFRESH
BaseClass=CHtmlView
VirtualFilter=7VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_ADDTOMENU
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=test.cpp
ImplementationFile=test.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

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

[DLG:IDR_MAINFRAME]
Type=1
Class=CMyTool
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ADDRESS,combobox,1344340226
Control3=IDC_GOTO,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_LAST
Command2=ID_NEXT
Command3=ID_REFRESH
CommandCount=3

[CLS:CMyTool]
Type=0
HeaderFile=MyTool.h
ImplementationFile=MyTool.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyTool
VirtualFilter=dWC

