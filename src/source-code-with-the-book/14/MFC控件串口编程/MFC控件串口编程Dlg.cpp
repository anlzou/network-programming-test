//Download by www.cctry.com
// MFC控件串口编程Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC控件串口编程.h"
#include "MFC控件串口编程Dlg.h"

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
// CMFCDlg dialog

CMFCDlg::CMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCDlg)
	m_recv1 = _T("");
	m_recv2 = _T("");
	m_send1 = _T("");
	m_send2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCDlg)
	DDX_Text(pDX, IDC_RECV1, m_recv1);
	DDX_Text(pDX, IDC_RECV2, m_recv2);
	DDX_Text(pDX, IDC_SEND1, m_send1);
	DDX_Text(pDX, IDC_SEND2, m_send2);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscom1);
	DDX_Control(pDX, IDC_MSCOMM2, m_mscom2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SENDBTN1, OnSendbtn1)
	ON_BN_CLICKED(IDC_SENDBTN2, OnSendbtn2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg message handlers

BOOL CMFCDlg::OnInitDialog()
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
	m_mscom1.SetCommPort(2);		//COM2
    m_mscom1.SetInBufferSize(1024); //设置输入缓冲区的大小，Bytes 
    m_mscom1.SetOutBufferSize(512); //设置输出缓冲区的大小，Bytes 
	if(!m_mscom1.GetPortOpen())		//打开串口
	{
    	m_mscom1.SetPortOpen(true);
	}
	
	m_mscom1.SetInputMode(1);		//设置输入方式为二进制方式 
	m_mscom1.SetSettings("9600,n,8,1"); //设置波特率等参数 
	m_mscom1.SetRThreshold(1);		//为1表示有一个字符即引发事件 
	m_mscom1.SetInputLen(0);

    //初始化COM4
	m_mscom2.SetCommPort(4);		//COM4
    m_mscom2.SetInBufferSize(1024); //设置输入缓冲区的大小，Bytes 
    m_mscom2.SetOutBufferSize(512); //设置输入缓冲区的大小，Bytes 
	if(!m_mscom2.GetPortOpen())		//打开串口
	{
    	m_mscom2.SetPortOpen(true);
	}
	
	m_mscom2.SetInputMode(1);		//设置输入方式为二进制方式 
	m_mscom2.SetSettings("9600,n,8,1"); //设置波特率等参数 
	m_mscom2.SetRThreshold(1);		//为1表示有一个字符即引发事件 
	m_mscom2.SetInputLen(0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCDlg::OnPaint() 
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
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCDlg::OnSendbtn1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CByteArray sendArr;
	WORD wLen;
	//获得发送数据长度
	wLen=m_send1.GetLength();
	//给变量sendArr设置长度
    sendArr.SetSize(wLen);
	//把数据赋给CByteArray类型变量用于发送数据
	for(int i=0;i<wLen;i++)
	{
		sendArr.SetAt(i,m_send1.GetAt(i));
	}
	//发送数据
    m_mscom1.SetOutput(COleVariant(sendArr));	
}

void CMFCDlg::OnSendbtn2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CByteArray sendArr;
	WORD wLen;
	//获得发送数据长度
	wLen=m_send2.GetLength();
	//给变量sendArr设置长度
    sendArr.SetSize(wLen);
	//把数据赋给CByteArray类型变量用于发送数据
	for(int i=0;i<wLen;i++)
	{
		sendArr.SetAt(i,m_send2.GetAt(i));
	}
	//发送数据
    m_mscom2.SetOutput(COleVariant(sendArr));	
}

BEGIN_EVENTSINK_MAP(CMFCDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMFCDlg)
	ON_EVENT(CMFCDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	ON_EVENT(CMFCDlg, IDC_MSCOMM2, 1 /* OnComm */, OnOnCommMscomm2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMFCDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//定义一些临时变量
	VARIANT variant_inp;  
	COleSafeArray safearray_inp;
    long i=0;
	int len;
	BYTE rxdata[1000];

	switch(m_mscom1.GetCommEvent())
	{
    	case 2:     //表示接收缓冲区内有字符
			{
				//读取缓冲区数据
                variant_inp=m_mscom1.GetInput();
				//将VARIANT型变量值赋给ColeSafeArray类型变量
			    safearray_inp=variant_inp;
				//获得数据长度
			    len=safearray_inp.GetOneDimSize();
				//将数据保存到字符数组中
			    for(i=0;i<len;i++)
				{
                    safearray_inp.GetElement(&i,&rxdata[i]);
				}
                //字符串结束
				rxdata[i]='\0';
			}
        	m_recv1 += rxdata;
            UpdateData(false);
			break;
		default:
			break;
	}	
}

void CMFCDlg::OnOnCommMscomm2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//定义一些临时变量
	VARIANT variant_inp;  
	COleSafeArray safearray_inp;
    long i=0;
	int len;
	BYTE rxdata[1000];
	
	switch(m_mscom2.GetCommEvent())
	{
	case 2:     //表示接收缓冲区内有字符
		{
			//读取缓冲区数据
			variant_inp=m_mscom2.GetInput();
			//将VARIANT型变量值赋给ColeSafeArray类型变量
			safearray_inp=variant_inp;
			//获得数据长度
			len=safearray_inp.GetOneDimSize();
			//将数据保存到字符数组中
			for(i=0;i<len;i++)
			{
				safearray_inp.GetElement(&i,&rxdata[i]);
			}
			//字符串结束
			rxdata[i]='\0';
		}
		m_recv2+= rxdata;
		UpdateData(false);
		break;
	default:
		break;
	}	
}
