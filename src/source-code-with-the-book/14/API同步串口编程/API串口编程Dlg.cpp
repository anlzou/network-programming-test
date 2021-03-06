//Download by www.cctry.com
// API串口编程Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "API串口编程.h"
#include "API串口编程Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAPIDlg dialog

CAPIDlg::CAPIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAPIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAPIDlg)
	m_recv = _T("");
	m_send = _T("");
	m_recv2 = _T("");
	m_send2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAPIDlg)
	DDX_Text(pDX, IDC_RECV, m_recv);
	DDX_Text(pDX, IDC_SEND, m_send);
	DDX_Text(pDX, IDC_RECV2, m_recv2);
	DDX_Text(pDX, IDC_SEND2, m_send2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAPIDlg, CDialog)
	//{{AFX_MSG_MAP(CAPIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SENDBTN, OnSendbtn)
	ON_BN_CLICKED(IDC_RECVBTN, OnRecvbtn)
	ON_BN_CLICKED(IDC_SENDBTN2, OnSendbtn2)
	ON_BN_CLICKED(IDC_RECVBTN2, OnRecvbtn2)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAPIDlg message handlers

BOOL CAPIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//初始化COM2
	//获取文件句柄
	handleFile = CreateFile("COM2",GENERIC_READ | GENERIC_WRITE,0,0,
		OPEN_EXISTING,0,0);
	if(handleFile == INVALID_HANDLE_VALUE)
	{
		MessageBox("Error in CreateFile");
		return FALSE;
	}

	//串口参数设置失败
	DCB dcb;
	GetCommState(handleFile,&dcb);
	dcb.BaudRate = 9600;
	dcb.ByteSize = 8;
	dcb.fParity = FALSE;
	dcb.StopBits = ONESTOPBIT;
	BOOL isTrue;
	isTrue = SetCommState(handleFile,&dcb);
	if(isTrue == FALSE)
	{
		MessageBox("串口参数设置失败");
		return FALSE;
	}

	//设置串口超时
	COMMTIMEOUTS	timeous;
	timeous.ReadIntervalTimeout = 1000;		//读取间隔超时设置为2秒
	isTrue = SetCommTimeouts(handleFile,&timeous);
	if(isTrue == FALSE)
	{
		MessageBox("串口超时设置失败");
		return FALSE;
	}

	//设置各缓冲区的大小
	SetupComm(handleFile,1024,1024);
	//清除缓冲区的内容
	isTrue = PurgeComm(handleFile,PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	if(isTrue == FALSE)
	{
		MessageBox("清除缓冲区操作失败");
		return FALSE;
	}

	//初始化COM4
	//获取文件句柄
	handleFile2 = CreateFile("COM4",GENERIC_READ | GENERIC_WRITE,0,0,
		OPEN_EXISTING,0,0);
	if(handleFile2 == INVALID_HANDLE_VALUE)
	{
		MessageBox("Error in CreateFile");
		return FALSE;
	}

	//串口参数设置失败
	DCB dcb2;
	GetCommState(handleFile2,&dcb2);
	dcb2.BaudRate = 9600;
	dcb2.ByteSize = 8;
	dcb2.fParity = FALSE;
	dcb2.StopBits = ONESTOPBIT;
	isTrue = SetCommState(handleFile2,&dcb2);
	if(isTrue == FALSE)
	{
		MessageBox("串口参数设置失败");
		return FALSE;
	}

	//设置串口超时
	COMMTIMEOUTS	timeous2;
	timeous2.ReadIntervalTimeout = 1000;		//读取间隔超时设置为2秒
	isTrue = SetCommTimeouts(handleFile2,&timeous2);
	if(isTrue == FALSE)
	{
		MessageBox("串口超时设置失败");
		return FALSE;
	}

	//设置各缓冲区的大小
	SetupComm(handleFile2,1024,1024);
	//清除缓冲区的内容
	isTrue = PurgeComm(handleFile2,PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	if(isTrue == FALSE)
	{
		MessageBox("清除缓冲区操作失败");
		return FALSE;
	}		

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAPIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAPIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAPIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAPIDlg::OnSendbtn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	DWORD	dwError;
	COMSTAT	comstat;
	ClearCommError(handleFile,&dwError,&comstat);
	DWORD	dword;
	BOOL isTrue = WriteFile(handleFile,m_send.GetBuffer(1),m_send.GetLength() + 1,&dword,0);
	if(isTrue)
	{
		MessageBox("发送成功");
	}
}

void CAPIDlg::OnRecvbtn() 
{
	// TODO: Add your control notification handler code here
	char	buff[1024];
	DWORD	dword;
	BOOL isTrue = ReadFile(handleFile,buff,1024,&dword,0);
	if(isTrue)
	{
		MessageBox("读取成功");
	}
	PurgeComm(handleFile,PURGE_RXABORT | PURGE_RXCLEAR | PURGE_TXABORT | PURGE_TXCLEAR);
	m_recv = buff;
	UpdateData(false);
}

void CAPIDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	if(handleFile)
		CloseHandle(handleFile);
	if(handleFile2)
		CloseHandle(handleFile2);
	
	CDialog::OnCancel();
}

void CAPIDlg::OnSendbtn2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	DWORD	dwError;
	COMSTAT	comstat;
	ClearCommError(handleFile2,&dwError,&comstat);
	DWORD	dword;
	BOOL isTrue = WriteFile(handleFile2,m_send2.GetBuffer(1),m_send2.GetLength() + 1,&dword,0);
	if(isTrue)
	{
		MessageBox("发送成功");
	}
}

void CAPIDlg::OnRecvbtn2() 
{
	// TODO: Add your control notification handler code here
	char	buff[1024];
	DWORD	dword;
	BOOL isTrue = ReadFile(handleFile2,buff,1024,&dword,0);
	if(isTrue)
	{
		MessageBox("读取成功");
	}
	PurgeComm(handleFile2,PURGE_RXABORT | PURGE_RXCLEAR | PURGE_TXABORT | PURGE_TXCLEAR);
	m_recv2 = buff;
	UpdateData(false);
}

void CAPIDlg::OnCancel2() 
{
	// TODO: Add your control notification handler code here
	if(handleFile)
		CloseHandle(handleFile);
	if(handleFile)
		CloseHandle(handleFile2);
	
	CDialog::OnCancel();
}
