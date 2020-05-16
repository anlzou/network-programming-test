//Download by www.cctry.com
// IpCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IpCtrl.h"
#include "IpCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIpCtrlDlg dialog

CIpCtrlDlg::CIpCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIpCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIpCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIpCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIpCtrlDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ipAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIpCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CIpCtrlDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETIP, OnGetip)
	ON_BN_CLICKED(IDC_CLEARIP, OnClearip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIpCtrlDlg message handlers

BOOL CIpCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ipAddress.SetFieldRange(2,0,20);
	m_ipAddress.SetAddress(127,0,0,1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIpCtrlDlg::OnPaint() 
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
HCURSOR CIpCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIpCtrlDlg::OnGetip() 
{
	// TODO: Add your control notification handler code here
	if(m_ipAddress.IsBlank())
	{
		AfxMessageBox("忘记填写了吧...");
		return;
	}

/*	BYTE f0,f1,f2,f3;
	if(4 != m_ipAddress.GetAddress(f0,f1,f2,f3) )
	{
		AfxMessageBox("有忘记填写的地方哦...");
		return;
	}


	CString strIp;
	strIp.Format("%d:%d:%d:%d",f0,f1,f2,f3);
	AfxMessageBox(strIp);	*/

	DWORD	f;
	if( 4 != m_ipAddress.GetAddress(f) )
	{
		AfxMessageBox("有忘记填写的地方哦...");
		return;
	}

	CString strIp;
	strIp.Format("%d:%d:%d:%d",
				(f & 0xFF000000) >> 24,
				(f & 0x00FF0000) >> 16,
				(f & 0x0000FF00) >> 8,
				(f & 0x000000FF)	);
	AfxMessageBox(strIp);
}

void CIpCtrlDlg::OnClearip() 
{
	// TODO: Add your control notification handler code here
	m_ipAddress.ClearAddress();
	m_ipAddress.SetFieldFocus(0);
}
