//Download by www.cctry.com
// recvemilDlg.cpp : implementation file
//

#include "stdafx.h"
#include "recvemil.h"
#include "recvemilDlg.h"

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
// CRecvemilDlg dialog

CRecvemilDlg::CRecvemilDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecvemilDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecvemilDlg)
	m_address = _T("");
	m_password = _T("");
	m_username = _T("");
	m_context = _T("");
	m_from = _T("");
	m_subject = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRecvemilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecvemilDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_username);
	DDX_Text(pDX, IDC_CONTEXT, m_context);
	DDX_Text(pDX, IDC_FROM, m_from);
	DDX_Text(pDX, IDC_SUBJECT, m_subject);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRecvemilDlg, CDialog)
	//{{AFX_MSG_MAP(CRecvemilDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST, OnDblclkList)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_GET, OnGet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecvemilDlg message handlers

BOOL CRecvemilDlg::OnInitDialog()
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

void CRecvemilDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRecvemilDlg::OnPaint() 
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
HCURSOR CRecvemilDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRecvemilDlg::OnDblclkList() 
{
	// TODO: Add your control notification handler code here
	m_from = "";
	m_subject = "";
	m_context = "";
	UpdateData(false);	//清空以便重新填写

	int index = m_list.GetCurSel();
	int length = m_list.GetTextLen(index);
	char *buff = new char[length+1];
	m_list.GetText(index,buff);

	//发送RETR，返回邮件信息
	CString send_message;
	send_message  = "RETR ";
	send_message += buff[0];
	delete buff;
	send_message += "\r\n";
	if( SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("发送信息出错");
		return;
	}
	char recv_message[256] = "";
	if( SOCKET_ERROR == recv(socket_client,recv_message,256,NULL) )
	{
		MessageBox("接收信息出错");
		return;
	}
	MessageBox(recv_message);					//显示接收的信息

	//循环读取
	BOOL flag_from = false,flag_subject = false,flag_context = false;	//判断发件人、主题信息和邮件内容是否已经获取
	memset(recv_message,0,256);
	int count = recv(socket_client,recv_message,255,NULL);
	int check = 0;	//遍历接收内容
	while(count != SOCKET_ERROR)
	{
		//提取需要的内容
		while(recv_message[check])
		{
			if(flag_from == false)	//筛选发件人信息
			{
				if(recv_message[check] == 'F' && recv_message[check+4] == ':')
				{
					char recv_from[30] = "";
					int recv_i = 0;
					while(recv_message[check+5+recv_i] != '\r' &&recv_message[check+6+recv_i] != '\n')
					{
						recv_from[recv_i] = recv_message[check+5+recv_i];
						recv_i++;
					}
					m_from = recv_from;
					UpdateData(false);
					flag_from = true;
				}
			}
			if(flag_subject == false)//筛选主题信息
			{
				if(recv_message[check] == 'S' && recv_message[check+7] == ':')
				{
					char recv_subject[30] = "";
					int recv_i = 0;
					while(recv_message[check+8+recv_i] != '\r' &&recv_message[check+9+recv_i] != '\n')
					{
						recv_subject[recv_i] = recv_message[check+8+recv_i];
						recv_i++;
					}
					m_subject = recv_subject;
					UpdateData(false);
					flag_subject = true;
				}
			}
			if(flag_context == true || (recv_message[check] == '\r' && recv_message[check+1] == '\n' &&
				recv_message[check+2] == '\r' && recv_message[check+3] == '\n') )//筛选邮件正文
			{
				
				if(flag_context == false)
				{
					char recv_context[256] = "";
					int recv_i = 0;
					while(recv_message[check+4+recv_i] != NULL &&
						  recv_message[check+4+recv_i] != '.')
					{
						recv_context[recv_i] = recv_message[check+4+recv_i];
						recv_i++;
					}
					if(recv_message[check+4+recv_i] == NULL)
					{
						m_context += recv_context;
						if(!flag_context)
							flag_context = true;
						break;			//退出内层循环	
					}	
					if(recv_message[check+4+recv_i] == '.')
					{
						m_context += recv_context;
						UpdateData(false);
						break;			//退出内层循环
					}
				}
				if(flag_context == true)
				{
					char recv_context[256] = "";
					int recv_i = 0;
					while(recv_message[check+recv_i] != '.')
					{
						recv_context[recv_i] = recv_message[check+recv_i];
						recv_i++;
					}
					m_context += recv_context;
					if(recv_message[check+recv_i] == '.')
					{
						UpdateData(false);
						break;			//退出循环	
					}
				}
			}
			check++;
		}//while
		check = 0;	//保证上面的循环再回到起始位置

		//接收内容结束判断
		int length = strlen(recv_message);
		if(recv_message[length-3] == '.')
			break;		//不再接收

		//循环前的准备工作
		memset(recv_message,0,256);
		count = recv(socket_client,recv_message,255,NULL);
	}//while
	MessageBox("文件读取完毕");
}

void CRecvemilDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	//加载套接字库
	WORD ver = MAKEWORD(2,0);
	WSADATA	wsadata;
	if( WSAStartup(ver,&wsadata) )
	{
		MessageBox("加载套接库失败");
		return;
	}

	//创建套接字
	socket_client = socket(AF_INET,SOCK_STREAM,NULL);
	if(socket_client == INVALID_SOCKET)
	{
		MessageBox("套接字创建失败");
		return;
	}

	//获取服务器IP地址
	hostent *host = gethostbyname(m_address);
	in_addr addr;
	memmove(&addr,host->h_addr_list[0],4);
	
	//连接服务器
	sockaddr_in socketaddr;
	memset(&socketaddr,0,sizeof(sockaddr_in));
	socketaddr.sin_family = AF_INET;
	socketaddr.sin_port	= htons(110);
	socketaddr.sin_addr	= addr;

	if( connect( socket_client,(sockaddr *)&socketaddr,sizeof(sockaddr) ) )
	{
		MessageBox("与服务器的连接失败");
		return;
	}
	char recv_message[256] = "";		//专用于接收返回信息
	if( SOCKET_ERROR == recv(socket_client,recv_message,256,NULL) )
	{
		MessageBox("接收信息出错");
		return;
	}
	MessageBox(recv_message);

	//用户名验证
	CString send_message;				//专用于发送信息
	send_message  = "USER ";			//USER 用户名
	send_message += m_username;
	send_message += "\r\n";	
	if( SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("发送信息出错");
		return;
	}
	memset(recv_message,0,256);
	if( SOCKET_ERROR == recv(socket_client,recv_message,256,NULL) )
	{
		MessageBox("接收信息出错");
		return;
	}
	MessageBox(recv_message);

	//密码验证
	send_message  = "PASS ";			//PASS 密码
	send_message += m_password;
	send_message += "\r\n";		
	if( SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("发送信息出错");
		return;
	}
	memset(recv_message,0,256);
	if( SOCKET_ERROR == recv(socket_client,recv_message,256,NULL) )
	{
		MessageBox("接收信息出错");
		return;
	}
	MessageBox(recv_message);
	MessageBox("Congratulation! 连接并登陆成功");

	GetDlgItem(IDC_ADDRESS)->EnableWindow(false);
	GetDlgItem(IDC_USERNAME)->EnableWindow(false);
	GetDlgItem(IDC_PASSWORD)->EnableWindow(false);
}

void CRecvemilDlg::OnGet() 
{
	// TODO: Add your control notification handler code here
	//发送LIST命令
	CString send_message;
	send_message  = "LIST\r\n";
	if( SOCKET_ERROR == send(socket_client,send_message,send_message.GetLength(),NULL) )
	{
		MessageBox("发送信息出错");
		return;
	}
	char recv_message[256] = "";
	if( SOCKET_ERROR == recv(socket_client,recv_message,256,NULL) )
	{
		MessageBox("接收信息出错");
		return;
	}
	MessageBox(recv_message);
	char list_message[20] = "";
	int j = 0;
	for(int i = 0;recv_message[i] != NULL;i++)
	{
		if(recv_message[i] == '\r' && recv_message[i+1] == '\n')
		{
			if(list_message[0] == '+' || list_message[0] == '.')
			{
				memset(list_message,0,20);
				j = 0;
				i = i+1;
				continue;
			}
			m_list.AddString(list_message);
			memset(list_message,0,20);
			j = 0;
			i = i+1;
			continue;
		}
		list_message[j++] = recv_message[i];
	}
}


void CRecvemilDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	closesocket(socket_client);
	WSACleanup();

	CDialog::OnCancel();
}
