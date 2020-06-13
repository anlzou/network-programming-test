//Download by www.cctry.com
// sendemilDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sendemil.h"
#include "sendemilDlg.h"

#include "Base64.h"

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
// CSendemilDlg dialog

CSendemilDlg::CSendemilDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendemilDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendemilDlg)
	m_name = _T("");
	m_password = _T("");
	m_address = _T("");
	m_context = _T("");
	m_rely = _T("");
	m_subject = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendemilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendemilDlg)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_CONTEXT, m_context);
	DDX_Text(pDX, IDC_RELY, m_rely);
	DDX_Text(pDX, IDC_SUBJECT, m_subject);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendemilDlg, CDialog)
	//{{AFX_MSG_MAP(CSendemilDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SENDBTN, OnSendbtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendemilDlg message handlers

BOOL CSendemilDlg::OnInitDialog()
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

void CSendemilDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSendemilDlg::OnPaint() 
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
HCURSOR CSendemilDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendemilDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);
	//初始化套接字库
	WSADATA		wsadata;
	WORD		version;
	version = MAKEWORD(2,0);
	WSAStartup(version,&wsadata);

	//创建套接字
	socket_client = socket(AF_INET,SOCK_STREAM,NULL);
	if(INVALID_SOCKET == socket_client)
	{
		MessageBox("创建套接字失败");
		return;
	}

	//获取smtp服务器的IP地址
	hostent *host = gethostbyname(m_address);
	in_addr in_addr_string ;
	memmove(&in_addr_string,host->h_addr_list[0],4);
	
	//与服务器建立连接
	sockaddr_in	addr;
	memset(&addr,0,sizeof(sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(25);
	addr.sin_addr = in_addr_string;	
	if( connect(socket_client,(sockaddr *)&addr,sizeof(sockaddr)) )
	{
		int i =  WSAGetLastError();
		CString err = "";
		err.Format("连接失败，错误号：%d",i);
		MessageBox(err);
		return;
	}
	//接收来自服务器的信息，确认是否连接成功
	char buff[100] = "";		//接收来自服务器的信息
	if( !recv(socket_client,buff,100,NULL) )
	{
		MessageBox("来自服务器的数据接收失败");
		return;
	}
	MessageBox(buff);

	//发送hello smtp
	CString hel = "HELO smtp\r\n";
	if( send(socket_client,hel.GetBuffer(1),hel.GetLength(),NULL) == SOCKET_ERROR )
	{
		MessageBox("Error send HELO");
		return;
	}
	memset(buff,0,100);
	if( !recv(socket_client,buff,100,NULL))
	{
		MessageBox("Error recv HELO");
	}
	MessageBox(buff);

	//选择验证方式为LOGIN
	CString login = "auth login\r\n";
	send(socket_client,login.GetBuffer(1),login.GetLength(),NULL);
	memset(buff,0,100);
	recv(socket_client,buff,100,NULL);
	MessageBox(buff);

	CBase64 code;		//用于将验证信息加密
	CString login_name = m_name;
	login_name.Format("%s\r\n",code.Encode(login_name,login_name.GetLength()));
	send(socket_client,login_name.GetBuffer(1),login_name.GetLength(),NULL);
	memset(buff,0,100);
	recv(socket_client,buff,100,NULL);
	MessageBox(buff);

	CString login_pass = m_password;
	login_pass.Format("%s\r\n",code.Encode(login_pass,login_pass.GetLength()));
	send(socket_client,login_pass.GetBuffer(1),login_pass.GetLength(),NULL);
	memset(buff,0,100);
	recv(socket_client,buff,100,NULL);
	MessageBox(buff);

	MessageBox("成功登陆！");
}

void CSendemilDlg::OnSendbtn() 
{
	// TODO: Add your control notification handler code here
	//发送MAIL FROM:<发件人>
	UpdateData(true);
	CString  send_message = "";	//专用于发送信息
	char recv_message[512] = ""; //专用于接收信息
	send_message = "MAIL FROM:<" + m_name + ">\r\n";
	if(SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		int err_num = WSAGetLastError();
		MessageBox("Error send");
		return;
	}
	recv(socket_client,recv_message,512,NULL);
	MessageBox(recv_message);

	//发送RCPT TO:<收件人>
	send_message = "RCPT TO:<" + m_rely + ">\r\n";
	if(SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("Error send");
		return;
	}
	memset(recv_message,0,512);
	recv(socket_client,recv_message,512,NULL);
	MessageBox(recv_message);

	//发送"DATA\r\n"
	send_message = "DATA\r\n";
	if(SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("Error send");
		return;
	}
	memset(recv_message,0,512);
	recv(socket_client,recv_message,512,NULL);
	MessageBox(recv_message);

	//HEADER部分
	send_message = "From:"; //FROM:发件人
	send_message += m_name;
	send_message += "\r\n";

	send_message +="Subject:";//Subject:主题
	send_message += m_subject;
	send_message += "\r\n\r\n";

	send_message += m_context;//邮件内容
	send_message += "\r\n\r\n";
	send_message += "\r\n.\r\n";//邮件结束标志
	if(SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("Error send");
		return;
	}
	memset(recv_message,0,512);
	recv(socket_client,recv_message,512,NULL);

	//退出
	send_message = "QUIT\r\n";
	if(SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("Error send");
		return;
	}
	memset(recv_message,0,512);
	recv(socket_client,recv_message,512,NULL);
	MessageBox(recv_message);
}


void CSendemilDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	//关闭套接字
	closesocket(socket_client);
	//卸载socket库
	WSACleanup();

	CDialog::OnCancel();
}
