//Download by www.cctry.com
// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//add new
#include "LogDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_check = FALSE;
	m_ectx = _T("");
	m_esay = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	curNum = 0;
	m_check = false;
}


void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Check(pDX, IDC_CHECK, m_check);
	DDX_Text(pDX, IDC_ECTX, m_ectx);
	DDX_Text(pDX, IDC_ESAY, m_esay);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTNSEND, OnBtnsend)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	//}}AFX_MSG_MAP
	ON_MESSAGE(SOCKET_EVENT,OnSocket)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//设置对话框背景
	m_bmBack.DeleteObject();
	m_brBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_CBACK);
	m_brBack.CreatePatternBrush(&m_bmBack);	

tryagain:
	//先弹出登录对话框
	CLogDlg ld;
	if(ld.DoModal() != IDOK)		//没有按确认键
	{
		PostQuitMessage(0);			//退出程序
		return TRUE;
	}
	
	//进行输入信息校验
	if(strlen(ld.m_ipAddr) == 0)
	{
		MessageBox("请输入服务器地址!");
		goto tryagain;
	}
	
	if(ld.m_name.IsEmpty())
	{
		MessageBox("请输入你的称谓!");
		goto tryagain;
	}

	m_Name = ld.m_name;
	char im = ld.m_imgNum + 1;

	CString	msg;
	DWORD	err;

	//把SOCKET与对话框联系起来，SOCKET有消息就通知本对话框
	m_socket.AttachCWnd(this);
	
	if(m_socket.Create() == FALSE)			//自动完成SOCKET的初始化、设置
	{
		err = GetLastError();
		msg.Format("创建Socket失败!\r\n错误代码:%d",err);//sprintf相同
		goto msgbox;
	}
	
	//设置对话框的标题     
	SetWindowText("正在连接到服务器...");
	
	//连接到服务器计算机，端口为0x8123的程序
	if(m_socket.Connect(ld.m_ipAddr,0x8123) == FALSE)
	{
		//如果连接成功，对方创建新的SOCKET，新的端口号，就与新的SOCKET，新的端口号通信。
		err = GetLastError();
		msg.Format("连接服务器失败! \r\n错误代码:%d",err);

msgbox:
		MessageBox(msg);
		PostQuitMessage(0);           //退出
		return TRUE;
	}	
	
	char	pkt[200];
	sprintf(pkt,"%s 已连接到服务器!",m_Name);

	//再次设置对话框的标题
	SetWindowText(pkt);
	
	Sleep(1000);

	//构造协议信息

	//功能码，登入聊天室，自己定义
	pkt[0] = 0x11;
	pkt[1] = im;
	strncpy(pkt+2,m_Name,98);        //将称谓拷到功能码后面

	//发送
	int l = strlen(pkt)+1;
	if(m_socket.Send(pkt,l) == FALSE)
	{
		MessageBox("发送数据错误!");
	}		

	//载入图标头像
	HICON myIcon[6];
	int i;
	for( i=0;i<6;i++)
	{
		myIcon[i] = AfxGetApp()->LoadIcon(IDI_ICON1 + i);
	}
	
	//创建图像列表
	m_ImageList.Create(32, 32, ILC_COLOR32, 6, 6); 
	for( i=0; i < 6; i++) 
	{ 
		m_ImageList.Add(myIcon[i]); 
	} 

	m_list.SetImageList(&m_ImageList, LVSIL_SMALL); 
	
	m_bSend.AutoLoad(IDC_BTNSEND,this);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
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

HBRUSH CClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CClientDlg::OnSocket(WPARAM wParam, LPARAM lParam)
{
	char	pkt[4096];
	memset(pkt,0,4096);

	LVFINDINFO   info;
	LVITEM lvitem; 

	switch(lParam)
	{
	case RETR:
		m_socket.Receive(pkt,4096);

		switch(pkt[0])
		{
		case 0x11:
			pName[curNum] = pkt +2;
			curNum++;
			m_ectx += pkt + 2;
			m_ectx += " 进入聊室。\r\n";
			
			lvitem.mask = LVIF_IMAGE|LVIF_TEXT; 
			lvitem.iItem = curNum; 
			lvitem.pszText = pkt + 2; 
			lvitem.iImage = pkt[1] - 1; 
			lvitem.iSubItem = 0; 

			m_list.InsertItem(&lvitem);
			
			break;
		//已加入用户信息
		case 0x31:
			pName[curNum] = pkt +2;
			curNum++;

			lvitem.mask = LVIF_IMAGE|LVIF_TEXT; 
			lvitem.iItem = curNum; 
			lvitem.pszText = pkt + 2; 
			lvitem.iImage = pkt[1] - 0x31; 
			lvitem.iSubItem = 0; 

			m_list.InsertItem(&lvitem); 
			break;

		case 0x41:
			//pkt + 1保存的是用户名
			m_ectx += pkt + 1;
			m_ectx += " 退出聊室\r\n";

			info.flags = LVFI_PARTIAL|LVFI_STRING;  
			info.psz   = pkt + 1;
			int item;
			item = m_list.FindItem(&info);

			if(item != -1)
			{
				m_list.DeleteItem(item);
			}
			break;
		default:
			//对于没有任何命令的消息，直接显示在消息框中
			m_ectx += pkt + 1;
		}
		
		UpdateData(false);
		break;
		
		case CLOSE:
			MessageBox("服务器已关闭!");
			break;
	}
}

void CClientDlg::OnBtnsend() 
{
	// TODO: Add your control notification handler code here

	UpdateData();

	char pkt[4096];
	memset(pkt,0,sizeof(pkt));

	int			len;
	
	if(m_check)
	{
		//私聊信息
		pkt[0] = 0x51;
		strcpy(pkt + 1,pName[m_curIndex]);
		len = sprintf(pkt + 100 ,"私聊：%s：%s\r\n",m_Name,m_esay);
		m_socket.Send(pkt,len + 100);
		
		sprintf(pkt + 100 ,"私聊：对%s说：%s\r\n",pName[m_curIndex],m_esay);
		m_ectx += pkt +100;
		m_esay.Empty();
	}
	else
	{	
		//群发信息
		pkt[0] = 0x21;										//填入功能码0x21
		len = sprintf(pkt+1,"%s说: %s\r\n",m_Name,m_esay);	//len是长度
		m_socket.Send(pkt,len + 3);							//字符串以零结尾。多发两个零
		
		m_esay.Empty();		
	}
	UpdateData(FALSE);
}

void CClientDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	m_curIndex   =m_list.GetNextItem(-1,   LVNI_SELECTED);
	if(m_curIndex == -1)
	{
		AfxMessageBox("还没有选择私聊的用户...");
		return;
	}

	m_check =true;
	UpdateData(false);

	*pResult = 0;
}

CClientDlg::~CClientDlg()
{
	m_socket.Close();
}	
