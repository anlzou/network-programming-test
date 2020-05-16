//Download by www.cctry.com
// 网络通信ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "网络通信Client.h"
#include "网络通信ClientDlg.h"

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_ip = _T("");
	m_recv = _T("");
	m_send = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Text(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_RECV, m_recv);
	DDX_Text(pDX, IDC_SEND, m_send);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_MESSAGE(WM_SOCKET,OnSocket)
	ON_BN_CLICKED(IDC_SENDBTN, OnSendbtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint() 
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	//加载Winsock dll
	WORD	version = MAKEWORD(2,0);
	WSADATA wsadata;
	if(WSAStartup(version,&wsadata))
	{
		MessageBox("加载Winsock dll 失败");
		return;
	}

	//创建套接字
	socket_client = socket(AF_INET,SOCK_STREAM,NULL);
	if(INVALID_SOCKET == socket_client)
	{
		MessageBox("套接字创建失败");
		return;
	}

	UpdateData(true);
	SOCKADDR_IN addr;
	memset(&addr,0,sizeof(SOCKADDR_IN));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(80);
	addr.sin_addr.S_un.S_addr = inet_addr(m_ip);
	if(connect(socket_client,(sockaddr *)&addr,sizeof(sockaddr)))
	{
		MessageBox("尝试与服务器的连接失败");
		return;
	}

	if( WSAAsyncSelect(socket_client,this->m_hWnd,WM_SOCKET,FD_READ))
	{
		MessageBox("异步设置出错");
		return;
	}
}

void CClientDlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	switch(lParam)
	{
	case FD_READ:
		{
			 UpdateData(true);
			 char buff[1024] = "";
			 if(!recv(socket_client,buff,1024,NULL))
			 {
				 MessageBox("数据接收出错");
				 return;
			 }
			 m_recv += "\r\n服务器端：";
			 m_recv += buff;
			 UpdateData(false);
		}
	}
}

void CClientDlg::OnSendbtn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(SOCKET_ERROR == send(socket_client,m_send.GetBuffer(1),m_send.GetLength(),NULL) )
	{
		MessageBox("消息发送出错");
		return;
	}
	m_recv += "\r\n客户端：";
	m_recv += m_send;
	m_send = "";
	UpdateData(false);
}

void CClientDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	if(WSACleanup())
	{
		MessageBox("卸载Winsock dll失败");
		return;
	}
	if(socket_client)
		closesocket(socket_client);
	CDialog::OnCancel();
}
