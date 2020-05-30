//Download by www.cctry.com
// FTP_clientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTP_client.h"
#include "FTP_clientDlg.h"

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
// CFTP_clientDlg dialog

CFTP_clientDlg::CFTP_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFTP_clientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFTP_clientDlg)
	m_host = _T("");
	m_password = _T("");
	m_username = _T("");
	m_port = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTP_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFTP_clientDlg)
	DDX_Control(pDX, IDC_LISTFILE, m_listfile);
	DDX_Control(pDX, IDC_LISTINFO, m_listinfo);
	DDX_Text(pDX, IDC_HOST, m_host);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_username);
	DDX_Text(pDX, IDC_PORT, m_port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFTP_clientDlg, CDialog)
	//{{AFX_MSG_MAP(CFTP_clientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_LBN_DBLCLK(IDC_LISTFILE, OnDblclkListfile)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_STOREFILE, OnStorefile)
	ON_BN_CLICKED(IDC_LOADFILE, OnLoadfile)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTP_clientDlg message handlers

BOOL CFTP_clientDlg::OnInitDialog()
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

void CFTP_clientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFTP_clientDlg::OnPaint() 
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
HCURSOR CFTP_clientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFTP_clientDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here

	//创建socket
	if( !sock_client.Create() )		//important
	{
		AfxMessageBox("socket创建失败");
		return;
	}

	UpdateData(true);

	//连接服务器
	if( !sock_client.Connect(m_host,m_port) )
	{
		AfxMessageBox("socket连接服务器失败");
		return;
	}	
	MySockRecv();

	CString	send_msg;	//专用来发送命令

	//发送用户名
	send_msg = "USER ";
	send_msg += m_username;
	send_msg += "\r\n";	
	MySockSend(send_msg);
	MySockRecv();

	//发送密码
	send_msg = "PASS ";
	send_msg += m_password;
	send_msg += "\r\n";	
	MySockSend(send_msg);
	MySockRecv();

	//禁用4个文本编辑框，1个按钮
	GetDlgItem(IDC_HOST)->EnableWindow(false);
	GetDlgItem(IDC_PORT)->EnableWindow(false);
	GetDlgItem(IDC_USERNAME)->EnableWindow(false);
	GetDlgItem(IDC_PASSWORD)->EnableWindow(false);
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
}

//接收并解析文件列表信息
void CFTP_clientDlg::Parse_list()
{
	//用新的socket和端口接收文件信息
	char  filelist[1024] = "";
	if( SOCKET_ERROR == sock_temp.Receive(filelist,1024) )
	{
		AfxMessageBox("数据接收失败");
		return;
	}
	CString parselist = filelist;

	//字符串的长度
	long len = parselist.GetLength();

	//解析到所有的文件名
	char filename[32] = "";
	int index_rn = parselist.Find("\r\n");
	int i,j = 0;

	while(len-1 != index_rn+1)
	{
		for(i = index_rn-1;parselist.GetAt(i) != ' ';i--);	//获取文件名起始位置
		for(i = i+1;i<index_rn;i++)
		{
			filename[j++] = parselist.GetAt(i);
		}
		j = 0;
		index_rn = parselist.Find("\r\n",index_rn+2);
		if(filename[0] == '.')
		{
			memset(filename,0,32);
			continue;
		}
		m_listfile.AddString(filename);
		memset(filename,0,32);
	}

	//获取最后一个文件名
	for(i = index_rn-1;parselist.GetAt(i) != ' ';i--);	//获取文件名起始位置
	for(i = i+1;i<index_rn;i++)
	{
		filename[j++] = parselist.GetAt(i);
	}
	if(filename[0] == '.')
	{
		return;
	}
	m_listfile.AddString(filename);	
}

//使得服务器进入被动模式，新建套接字连接新开的端口
BOOL CFTP_clientDlg::Pasv_mode()
{
	//创建新的socket
	if( !sock_temp.Create() )
	{
		AfxMessageBox("sock_temp创建失败");
		return false;
	}

	CString send_msg;	//专用于发送信息

	//让服务器进入被动模式，命令：PASV
	send_msg = "PASV\r\n";
	MySockSend(send_msg);

	//接收信息
	char buf_recv[64] = "";
	if( SOCKET_ERROR == sock_client.Receive(buf_recv,63) )
	{
		AfxMessageBox("数据接收失败");
		sock_temp.Close();
		return false;
	}
	CString show_msg = "响应：";
	show_msg += buf_recv;
	m_listinfo.AddString(show_msg);
	//获取新开的端口号，正常情况下返回值类似：227 Entering Passive Mode (192,168,0,101,194,73)
	//计算公式 新开端口号 = 194*256 + 73

	//解析返回的信息
	CString parse_str = buf_recv;
	int index_first = 0,index_mid = 0,index_end = 0;

	//定位
	index_end   = parse_str.Find(')');
	index_mid   = parse_str.ReverseFind(',');
	for(int ind = 0;ind < 4;ind++)
	{
		index_first = parse_str.Find(',',index_first+1);
	}
	
	//计算端口号
	char port_str[4] = "";
	int i,j = 0;
	for(i = index_first+1;i < index_mid;i++)
	{
		port_str[j++] = parse_str.GetAt(i);
	}

	int port_int = atoi(port_str);
	j = 0;
	memset(port_str,0,4);
	for(i = index_mid+1;i < index_end;i++)
	{
		port_str[j++] = parse_str.GetAt(i);
	}

	//计算得出新开的端口号
	port_int = port_int*256 + atoi(port_str);

	//用新的sock连接服务器
	if( !sock_temp.Connect(m_host,port_int) )	//可以使用网址
	{
		int ErrorNum = GetLastError();
		AfxMessageBox("sock_temp连接服务器失败");
		sock_temp.Close();
		return false;
	}
	return true;
}

void CFTP_clientDlg::MySockRecv()
{
	char buf_recv[128] = "";
	if( SOCKET_ERROR == sock_client.Receive(buf_recv,127) )
	{
		AfxMessageBox("数据接收失败");
		return;
	}
	//将信息显示在ListBox上
	CString show_msg = "响应：";
	show_msg += buf_recv;
	m_listinfo.AddString(show_msg);	
}

void CFTP_clientDlg::MySockSend(CString send_msg)
{
	if( SOCKET_ERROR == sock_client.Send( send_msg,send_msg.GetLength() ) )
	{
		AfxMessageBox("数据发送失败");
		return;
	}
	//将信息显示在ListBox上
	CString show_msg = "命令：";
	show_msg += send_msg;
	m_listinfo.AddString(show_msg);
}

void CFTP_clientDlg::OnDblclkListfile() 
{
	// TODO: Add your control notification handler code here
	//服务器进入被动模式
	if( !Pasv_mode() )
		return;

	//获取选择的文件名
	int index = m_listfile.GetCurSel();
	CString filename = "";
	m_listfile.GetText(index,filename);

	//下载文件，命令：RETR 文件名
	CString send_msg = "RETR ";
	send_msg += filename;
	send_msg += "\r\n";
	MySockSend(send_msg);
	MySockRecv();

	//写入接收文件内容
	fileStore(filename);

	//提示信息
	AfxMessageBox("文件已保存");
}

//创建文件，并写入内容
void CFTP_clientDlg::fileStore(CString filename)
{

	//文件保存对话框
	CFileDialog save_dlg(false,NULL,filename);

	if( save_dlg.DoModal() == IDOK)
	{
		CString full_name = save_dlg.GetPathName();
		//新建文件
		CFile	file(full_name,CFile::modeCreate | CFile::modeWrite);
		
		//用新的socket和端口接收文件信息
		char  fileContext[128] = "";
		while( 0 != sock_temp.Receive(fileContext,127) )
		{
			file.Write(fileContext,strlen(fileContext));
			memset(fileContext,0,128);
		}
		//关闭文件
		file.Close();
		//关闭新建立的连接
		sock_temp.Close();
	}
}

void CFTP_clientDlg::OnUpdate()
{
	// TODO: Add your control notification handler code here

	//使服务器进入被动模式
	if( !Pasv_mode() )
		return;
	
	//获取当前服务器根目录下的文件名，命令：LIST
	CString send_msg = "LIST\r\n";
	MySockSend(send_msg);
	MySockRecv();	//150 Opening ASCII mode data connection for /bin/ls.
	
	//解析列表信息
	Parse_list();

	//关闭新建立的连接
	sock_temp.Close();
}

void CFTP_clientDlg::OnStorefile() 
{
	// TODO: Add your control notification handler code here
	//显示打开文件对话框
	CFileDialog open_dlg(true);

	CString full_name;	//文件名全路径
	CString file_name;

	if(open_dlg.DoModal() == IDOK)
	{
		full_name = open_dlg.GetPathName();
		file_name = open_dlg.GetFileName();
		
		//进入被动模式
		if( !Pasv_mode() )
			return;

		//发送命令：STOR 文件名
		CString send_msg = "STOR ";
		send_msg += file_name;
		send_msg += "\r\n";
		MySockSend(send_msg);
		MySockRecv();

		//打开文件
		CFile file_read(full_name,CFile::modeRead);
		
		//发送文件内容
		char buf_read[128] = "";
		while( 0 != file_read.Read(buf_read,127) )
		{
			//上传文件
			sock_temp.Send(buf_read,128);
			memset(buf_read,0,128);
		}

		//关闭连接
		sock_temp.Close();
		file_read.Close();
		AfxMessageBox("上传完毕");
	}
}

void CFTP_clientDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CFTP_clientDlg::OnLoadfile() 
{
	// TODO: Add your control notification handler code here
	//服务器进入被动模式
	if( !Pasv_mode() )
		return;
	
	//获取选择的文件名
	int index = m_listfile.GetCurSel();
	CString filename = "";
	m_listfile.GetText(index,filename);
	
	//下载文件，命令：RETR 文件名
	CString send_msg = "RETR ";
	send_msg += filename;
	send_msg += "\r\n";
	MySockSend(send_msg);
	MySockRecv();
	
	//写入接收文件内容
	fileStore(filename);
	
	//提示信息
	AfxMessageBox("文件已保存");
}

void CFTP_clientDlg::OnQuit() 
{
	// TODO: Add your control notification handler code here
	//发送命令：QUIT
	CString send_msg = "QUIT\r\n";
	MySockSend(send_msg);
	MySockRecv();

	sock_client.Close();
}
