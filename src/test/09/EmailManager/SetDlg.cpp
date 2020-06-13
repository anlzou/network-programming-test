//Download by www.cctry.com
// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "emailmanager.h"
#include "SetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDlg)
	m_ip = _T("");
	m_password = _T("");
	m_username = _T("");
	//}}AFX_DATA_INIT
}


void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_Control(pDX, IDCANCEL, m_bnCancel);
	DDX_Control(pDX, IDOK, m_bnOk);
	DDX_Text(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

BOOL CSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bmBack.DeleteObject();
	m_brBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_SETBACK);					//导入背景图片
	m_brBack.CreatePatternBrush(&m_bmBack);		//保存窗体背景图片，供OnCtlColor()调用

	CString strFontName = _T("隶书");
	
	//////////////////////////////////////////////////////////////////////////

	//“确定”按钮

	//set bitmap
	m_bnOk.SetBitmaps(IDB_SET_NORMAL, IDB_SET_DOWN, IDB_SET_HLIGHT, 0);
	m_bnOk.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255), FALSE);
	m_bnOk.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	m_bnOk.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnOk.SizeToContent();
	m_bnOk.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	m_bnOk.SetWindowText(TEXT("确定"));
	//set font
	m_bnOk
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95), FALSE)			//3d阴影颜色
		.SetFontSize(14, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	//“取消”按钮

	//set bitmap
	m_bnCancel.SetBitmaps(IDB_SET_NORMAL, IDB_SET_DOWN, IDB_SET_HLIGHT, 0);
	m_bnCancel.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255), FALSE);
	m_bnCancel.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	m_bnCancel.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnCancel.SizeToContent();
	m_bnCancel.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	m_bnCancel.SetWindowText(TEXT("取消"));
	
	//set font
	m_bnCancel
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95), FALSE)			//3d阴影颜色
		.SetFontSize(14, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	SetWindowText("邮箱设置");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_DLG)
	{
		pDC->SetBkMode(TRANSPARENT);
		return m_brBack;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
