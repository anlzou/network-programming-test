//Download by www.cctry.com
// TCP客户端程序Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "TCP客户端程序.h"
#include "TCP客户端程序Dlg.h"

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
// CTCPDlg dialog

CTCPDlg::CTCPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTCPDlg, CDialog)
	//{{AFX_MSG_MAP(CTCPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_MESSAGE(WM_SOCKET,OnSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPDlg message handlers

BOOL CTCPDlg::OnInitDialog()
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
	GetDlgItem(IDC_TEXT)->EnableWindow(false);		//禁用消息显示框
	GetDlgItem(IDC_SENDTEXT)->EnableWindow(false);	//禁用发送消息编辑框
	GetDlgItem(IDC_SEND)->EnableWindow(false);		//禁用发送消息按钮	

	s=::socket(AF_INET,SOCK_STREAM,0);				//创建套接字并返回其句柄
	:: WSAAsyncSelect(s,this->m_hWnd,WM_SOCKET, FD_READ);
	//将套接字设置为异步模式
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTCPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTCPDlg::OnPaint() 
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
HCURSOR CTCPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTCPDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	CString str,str1;								//定义字符串
	int port;										//定义端口变量
	GetDlgItem(IDC_ADDR)->GetWindowText(str);		//获取服务器地址
	GetDlgItem(IDC_PORT)->GetWindowText(str1);		//获取端口号
	if(str==""||str1=="")								//判断用户输入是否为NULL
	{
		MessageBox("服务器地址或端口不能为NULL");			//显示提示信息
	}
	else
	{
		port=atoi(str1.GetBuffer(1));						//将端口字符串转换为数字
		addr.sin_family=AF_INET;
		addr.sin_addr.S_un.S_addr=inet_addr(str.GetBuffer(1));																	//转换服务器IP地址
		addr.sin_port=htons(port);
		GetDlgItem(IDC_TEXT)->SetWindowText("正在连接服务器......\r\n");															//提示用户正在连接服务器
		if(::connect(s,(sockaddr*)&addr,sizeof(addr)))																//连接服务器
		{
			GetDlgItem(IDC_TEXT)->GetWindowText(str);		//显示提示信息
			str+="连接服务器成功！\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(str);
			GetDlgItem(IDC_SENDTEXT)->EnableWindow(true);	//设置控件的显示状态
			GetDlgItem(IDC_SEND)->EnableWindow(true);
			GetDlgItem(IDC_ADDR)->EnableWindow(false);
			GetDlgItem(IDC_PORT)->EnableWindow(false);
		}
		else												//连接失败		
		{
			GetDlgItem(IDC_TEXT)->GetWindowText(str);
			str+="连接服务器失败！请重试\r\n";
			GetDlgItem(IDC_TEXT)->SetWindowText(str);
		}
	}	
}

void CTCPDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString str,str1;								//定义字符串变量
	GetDlgItem(IDC_SENDTEXT)->GetWindowText(str);	//获取用户发送的消息字符串
	if(str=="")										//不允许用户发送空消息
	{
		GetDlgItem(IDC_TEXT)->GetWindowText(str1);	//获取信息框中的内容
		str1+="\r\n";								//添加回车换行符
		str1+="消息不能为空\r\n";
		GetDlgItem(IDC_TEXT)->SetWindowText(str1);	//设置信息框中的内容
	}
	else												
	{
		::send(s,str.GetBuffer(1),str.GetLength(),0);	//发送信息到指定服务器
		GetDlgItem(IDC_TEXT)->GetWindowText(str1);	//获取信息框中的内容
		str1+="\r\n";								//添加回车换行符
		str1+=str;
		GetDlgItem(IDC_TEXT)->SetWindowText(str1);	//设置信息框中的内容
	}
}
void CTCPDlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	char cs[100]="";								//定义数据缓冲区
	if(lParam==FD_READ)								//如果是套接字读取时间
	{
		CString num="";								//定义字符串变量
		recv(s,cs,100,NULL);						//接收数据
		GetDlgItem(IDC_TEXT)->GetWindowText(num);	//获取消息框中的内容
		num+="\r\n服务器说：";						//添加回车换行符
		num+=(LPTSTR)cs;							//将接收到的数据转换为字符串
		GetDlgItem(IDC_TEXT)->SetWindowText(num);	//设置消息框内容
	}
}

