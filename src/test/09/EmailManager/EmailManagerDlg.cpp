//Download by www.cctry.com
// EmailManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManager.h"
#include "EmailManagerDlg.h"

//add new
#include "SetDlg.h"
#include "ReceiveDlg.h"
#include "SendDlg.h"


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
// CEmailManagerDlg dialog

CEmailManagerDlg::CEmailManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmailManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmailManagerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEmailManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmailManagerDlg)
	DDX_Control(pDX, IDC_SET, m_bnSet);
	DDX_Control(pDX, IDC_SEND, m_bnSend);
	DDX_Control(pDX, IDC_RECEIVE, m_bnReceive);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEmailManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CEmailManagerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_RECEIVE, OnReceive)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailManagerDlg message handlers

BOOL CEmailManagerDlg::OnInitDialog()
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

	//主窗体背景
	
	//若占有资源，先释放
	m_bmBack.DeleteObject();
	m_brBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_MAINBACK);			//导入主窗体背景图片
	m_brBack.CreatePatternBrush(&m_bmBack);		//保存窗体背景图片，供OnCtlColor()调用

	CString strFontName = _T("楷体");
	
	//“收件箱”按钮设置
	//set bitmap
	m_bnReceive.SetBitmaps(IDB_BTN_NORMAL, IDB_BTN_DOWN, IDB_BTN_HLIGHT);
	//文字颜色
	m_bnReceive.SetForceColor(RGB(255,255,0), RGB(255, 255, 255), RGB(255, 255, 255));
	//鼠标移过
	m_bnReceive.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	//按下声音
	m_bnReceive.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	//按钮自动适应第一个图片大小
	m_bnReceive.SizeToContent();
	//改变按钮显示文字
	m_bnReceive.SetWindowText(TEXT("收件箱"));
	//按钮鼠标类型
	m_bnReceive.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	
	//set font
	m_bnReceive
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95))					//3d阴影颜色
		.SetFontBold(TRUE, FALSE)							//粗体
		.SetFontSize(18, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	//“发件箱”按钮设置
	//set bitmap
	m_bnSend.SetBitmaps(IDB_BTN_NORMAL, NULL, IDB_BTN_HLIGHT);
	m_bnSend.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255));
	m_bnSend.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	m_bnSend.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnSend.SizeToContent();
	m_bnSend.SetWindowText(TEXT("发件箱"));
	m_bnSend.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	
	//set font
	m_bnSend
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95))					//3d阴影颜色
		.SetFontBold(TRUE, FALSE)							//粗体
		.SetFontSize(18, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	//“设置”按钮
	//set bitmap
	m_bnSet.SetBitmaps(IDB_SET_NORMAL, IDB_SET_DOWN, IDB_SET_HLIGHT);
	m_bnSet.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255), FALSE);
	m_bnSet.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	m_bnSet.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnSet.SizeToContent();
	m_bnSet.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	m_bnSet.SetWindowText(TEXT("设置"));

	//set font
	m_bnSet
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95), FALSE)			//3d阴影颜色
		.SetFontSize(12, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEmailManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEmailManagerDlg::OnPaint() 
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
HCURSOR CEmailManagerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CEmailManagerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

	if(nCtlColor == CTLCOLOR_DLG )
	{
		pDC->SetBkMode(TRANSPARENT);
		return m_brBack;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CEmailManagerDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	CSetDlg dlg;
	dlg.m_ip = m_EM_ip;
	dlg.m_username = m_EM_username;
	dlg.m_password = m_EM_password;		
	
	if(dlg.DoModal() == IDOK)
	{
		m_EM_ip = dlg.m_ip;
		m_EM_username = dlg.m_username;
		m_EM_password = dlg.m_password;	
	}
}

void CEmailManagerDlg::OnReceive() 
{
	// TODO: Add your control notification handler code here
	CReceiveDlg dlg(m_EM_ip,m_EM_username,m_EM_password);
	dlg.DoModal();
}

void CEmailManagerDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	CSendDlg dlg;
	dlg.m_sender = m_EM_username;
	dlg.m_sendPsd = m_EM_password;
	dlg.DoModal();
}
