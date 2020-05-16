//Download by www.cctry.com
// Transfer_serverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Transfer_server.h"
#include "Transfer_serverDlg.h"

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
// CTransfer_serverDlg dialog

CTransfer_serverDlg::CTransfer_serverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransfer_serverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransfer_serverDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransfer_serverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransfer_serverDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTransfer_serverDlg, CDialog)
	//{{AFX_MSG_MAP(CTransfer_serverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STARTRUN, OnStartrun)
	ON_MESSAGE(WM_SOCKET,OnSocket)
	ON_BN_CLICKED(IDC_SENDFILE, OnSendfile)
	ON_BN_CLICKED(IDC_RECVFILE, OnRecvfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransfer_serverDlg message handlers

BOOL CTransfer_serverDlg::OnInitDialog()
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

void CTransfer_serverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTransfer_serverDlg::OnPaint() 
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
HCURSOR CTransfer_serverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTransfer_serverDlg::OnStartrun() 
{
	// TODO: Add your control notification handler code here
	//加载socket库
	WORD	ver = MAKEWORD(2,0);
	WSADATA	wsadata;
	
	if( WSAStartup(ver,&wsadata) )
	{
		MessageBox("socket库加载失败");
		return;
	}
	
	//创建socket
	socket_server = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if( INVALID_SOCKET == socket_server)
	{
		MessageBox("socket创建失败");
		socket_server = NULL;
		return;
	}

	//绑定IP和端口
	sockaddr_in addr_server;
	memset(&addr_server,0,sizeof(sockaddr_in));
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(3000);
	addr_server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if( bind(socket_server,(sockaddr *)&addr_server,sizeof(sockaddr)) )
	{
		MessageBox("绑定服务器出错");
		return;
	}

	//监听来自客户端的连接
	listen(socket_server,5);

	//设置异步套接字
	WSAAsyncSelect(socket_server,this->m_hWnd,WM_SOCKET,FD_ACCEPT);

	MessageBox("服务器开启成功");
}

//编写消息响应
void CTransfer_serverDlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	//接收连接消息
	if(lParam == FD_ACCEPT)
	{
		sockaddr_in addr_client;
		memset(&addr_client,0,sizeof(sockaddr_in));
		int length_addr = sizeof(sockaddr_in);
		socket_client = accept(socket_server,(sockaddr *)&addr_client,&length_addr);
		MessageBox("建立连接成功");
	}
}

void CTransfer_serverDlg::OnSendfile() 
{
	// TODO: Add your control notification handler code here

	//文件打开对话框
	CFileDialog send_dlg(TRUE);
	if( IDOK == send_dlg.DoModal() )
	{
		//获取文件路径
		CString path_name = send_dlg.GetPathName();

		//创建CFile
		CFile file_context(path_name,CFile::modeRead);
		char context[256] = "";

		//读取文件内容
		while( file_context.Read(context,255) )
		{
			//发送文件内容
			if( SOCKET_ERROR == send(socket_client,context,255,NULL) )
			{
				MessageBox("文件内容发送失败");
				return;
			}
			memset(context,0,256);
		}

		//文件关闭
		file_context.Close();
		MessageBox("文件发送完毕");
	}
}

void CTransfer_serverDlg::OnRecvfile() 
{
	// TODO: Add your control notification handler code here

	//指定文件保存路径
	CFileDialog recv_dlg(false);
	if(IDOK == recv_dlg.DoModal())
	{
		CString file_path =	recv_dlg.GetPathName();

		//在指定文件路径出创建文件
		CFile file_recv(file_path,CFile::modeCreate | CFile::modeWrite);
		
		//接收文件内容
		if(socket_client)
		{
			char recv_context[256] = "";
			while(recv(socket_client,recv_context,255,NULL))
			{
				//填写内容
				file_recv.Write(recv_context,strlen(recv_context));
				if(strlen(recv_context)<255)
					break;
			}
		}
		//文件关闭
		file_recv.Close();
		MessageBox("文本保存完毕");
	}
}

void CTransfer_serverDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	closesocket(socket_server);
	closesocket(socket_client);
	WSACleanup();
	CDialog::OnCancel();
}
