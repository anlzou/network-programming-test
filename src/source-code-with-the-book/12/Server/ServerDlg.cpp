//Download by www.cctry.com
// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_Ctx = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_LISTUSER, m_List);
	DDX_Text(pDX, IDC_CTX, m_Ctx);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTNRUN, OnBtnrun)
	//}}AFX_MSG_MAP
	ON_MESSAGE(SOCKET_EVENT,OnSocket)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//修改主对话框的背景
	m_brBack.DeleteObject();
	m_bmBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_SBACK);
	m_brBack.CreatePatternBrush(&m_bmBack);

	//初始化列表控件的列标头
	m_List.InsertColumn(0,"用户名",LVCFMT_LEFT,120);		//第一列表头
	m_List.InsertColumn(1,"IP",LVCFMT_LEFT,100);		//第二列表头
	m_List.InsertColumn(2,"消息数",LVCFMT_LEFT,130);		//第三列表头
	m_List.InsertColumn(3,"头像",LVCFMT_LEFT,60);		//第四列表头

	m_bnRun.AutoLoad(IDC_BTNRUN,this);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CServerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_DLG)
	{
		return m_brBack;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
//wParam对应于相应客户端通信的SOCKET指针，也有可能是主SOCKET，lParam对应事件类型
void CServerDlg::OnSocket(WPARAM wParam, LPARAM lParam)
{
	CMySocket	*sock = (CMySocket*)wParam;
	CMySocket	*c;
	//SOCKADDR_IN是一个结构，表示IP地址、端口号等
	SOCKADDR_IN sockAddr;
	int			nSize = sizeof(sockAddr);
	BOOL		res;
	
	switch(lParam)
	{
	//新的连接消息
	case ACCEPT:
		//创建一个新的SOCKET
		c = new CMySocket;
		//将连接绑定到本窗体
		c->AttachCWnd(this);
		
		//主SOCKET指派新创建的SOCKET与客户端通信
		res = sock->Accept(*c,(SOCKADDR *)&sockAddr,&nSize);
		if(res == FALSE)
		{
			MessageBox("Accept Error!");
		}
		break;

	//连接关闭消息
	case CLOSE:
		//关闭连接
		ClosePlayer(sock);
		break;
		
	//收到数据消息
	case RETR:
		ParserPkt(sock);									//解析消息
		break;
	}
}

//处理用户退出事件
void CServerDlg::ClosePlayer(CMySocket *from)
{
	int		i , msg_len;
	char	out_msg[200];

	//returns the number of bytes stored in buffer, 
	//not counting the terminating null character.
	msg_len = sprintf(out_msg," %s 退出聊天室\r\n",from->m_Player) + 1;

	//保存退出命令和用户名
	char	nbuf[100];

	m_csList.Lock();

	//删除退出用户的信息
	for(i = 0; i < m_List.GetItemCount(); i++)
	{
		//GetItemData() - This value is the lParam member of the LVITEM structure
		//Retrieves the 32-bit application-specific value
		//associated with the item specified by nItem. 
		if(m_List.GetItemData(i) == (DWORD)from)
		{
			//删除套接字
			delete from;

			//用户退出的命令
			nbuf[0] = 0x41;
			m_List.GetItemText(i,0,nbuf + 1, 100);	 
			m_List.DeleteItem(i);					//删除退出用户在列表中的信息
			break;
		}
	}

	//将用户退出消息发送给各个用户
	for(i = 0; i < m_List.GetItemCount(); i++)
	{
		CMySocket *s;
		
		s = (CMySocket*)m_List.GetItemData(i);

		s->Send(nbuf,100);							//发送消息
	}

	m_csList.Unlock();
	
	Append(out_msg);
}

//追加消息体
void CServerDlg::Append(char *msg)
{
	//读取消息框中所有的消息
	m_Ctx += msg;
	UpdateData(FALSE);
}

//解析收到的数据
void CServerDlg::ParserPkt(CMySocket *from)
{
	char SendBuff[4096];		//发送缓冲
	char ShowBuff[4096];		//显示缓冲
	char nbuf[100];				//临时缓冲区

	//初始化各缓冲区
	memset(SendBuff,0,4096);
	memset(ShowBuff,0,4096);
	memset(nbuf,0,100);

	int len;					//记录发送长度
	int item;					//列表序号
	char pic[2];				//图像序号		
	CMySocket *s1;				//发送一般消息的Socket		
	CMySocket *s;				//发送用户进入信息的Socket


	//读取数据
	len = from->Receive(SendBuff,4096);

	//0---连接关闭，-1---发送错误
	if(len < 1)	
	{
		AfxMessageBox("消息解析--接收消息Error");
		return;
	}

	//0x11---服务器接收用户进入聊天室
	if(SendBuff[0] == 0x11)	
	{
		CString ipaddr;				//IP字符串	
		UINT port;					//端口号

		//取得与该套接字链接的对方的IP地址、端口号
		from->GetPeerName(ipaddr,port);
		//与SOCKET通信的用户的称谓
		from->m_Player = SendBuff + 2;//名称的记录会在为空时停止--great!

		//头像序号处理
		pic[0] = SendBuff[1] + 0x30;	//找到字符‘1’的位置--great! '1'的ascii为0x31
		pic[1] = '\0';

		//向列表中插入一项
		m_csList.Lock();

		//列表中插入一行，返回插入的行号
		item = m_List.InsertItem(0,SendBuff+2);
		//保存该SOCKET指针到该行的附加数据域
		m_List.SetItemData(item,(DWORD)from);
		//设置第2列，IP地址列
		m_List.SetItemText(item,1,ipaddr);
		//设置第3列，用户头像
		m_List.SetItemText(item,3,pic);

		m_csList.Unlock();

		//s1中保存新加入用户的socket
		s1 = (CMySocket*)m_List.GetItemData(item);

		//通知所有用户有新用户加入
		m_csList.Lock();

		for(item = 0; item < m_List.GetItemCount(); item++)
		{
			s = (CMySocket*)m_List.GetItemData(item);
			len = sprintf(ShowBuff ," %s 进入聊室\r\n",from->m_Player);
			
			Sleep(200);

			//发送图标号和用户名
			if( s != from )	
			{
				//发送指令为0x11的命令
				s->Send(SendBuff,len+1);

				//向新用户发送已登录用户信息
			
				//获取图标号
				m_List.GetItemText(item,3,&pic[0],2);
				//0x31---已登录用户信息，
				nbuf[0] = 0x31;
				nbuf[1] = pic[0];
				//获取用户名
				m_List.GetItemText(item,0,nbuf+2,100);
				len = strlen(nbuf);
				s1->Send(nbuf,len+1);		//发送用户名+头像号
			}
			else
			{
				//新用户消息加1
				char tot[10];

				sprintf(tot,"%u",from->m_Total);
				//设置第2列，消息数列
				m_List.SetItemText(item,2,tot);
			}
		}

		m_csList.Unlock();
	}
	//私聊信息---不同的消息格式
	else if(SendBuff[0] == 0x51)	//根据用户名转发了
	{
		char pName[100],bName[100];
		memset(pName,0,100);
		memset(bName,0,100);

		//按照私聊的用户名查找
		strcpy(pName,SendBuff +1);
		for(item = 0; item < m_List.GetItemCount(); item++)
		{
			m_List.GetItemText(item,0,bName,100);

			if(0 == strcmp(pName,bName))
			{
				s = (CMySocket*)m_List.GetItemData(item);
				//同样直接发送了文本
			    s->Send(SendBuff + 99 ,len);
			}
		}
	}
	//公聊信息
	else	//向所有用户转发消息	
	{
		m_csList.Lock();

		for(item = 0; item < m_List.GetItemCount(); item++)
		{
			s = (CMySocket*)m_List.GetItemData(item);
			s->Send(SendBuff,len);

			if(s == from)
			{
				char tot[10];
				sprintf(tot,"%u",from->m_Total);
				m_List.SetItemText(item,2,tot);				//设置第2列，消息数列
			}
		}
		memcpy(ShowBuff,SendBuff+1,4096);

		m_csList.Unlock();
	}

	//无论怎样都会有信息被写？包括2类：用户进入、私聊信息、不记录公聊天信息？
	Append(ShowBuff);
}

void CServerDlg::OnBtnrun() 
{
	// TODO: Add your control notification handler code here

	//socket
	m_socket.AttachCWnd(this);
	BOOL isTrue = m_socket.Create(0x8123,SOCK_STREAM);
	if(isTrue)
	{
		m_socket.Listen();
		AfxMessageBox("开启成功！");
		GetDlgItem(IDC_BTNRUN)->EnableWindow(FALSE);
		return;
	}
	AfxMessageBox("不好意思，出了点问题...");
}
