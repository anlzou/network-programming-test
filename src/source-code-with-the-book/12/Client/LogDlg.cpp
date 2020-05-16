//Download by www.cctry.com
// LogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "LogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogDlg dialog


CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogDlg)
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogDlg)
	DDX_Control(pDX, IDC_LOGIN, m_bnLogin);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_Photo);
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogDlg, CDialog)
	//{{AFX_MSG_MAP(CLogDlg)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogDlg message handlers

BOOL CLogDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//设置对话框背景
	m_bmBack.DeleteObject();
	m_brBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_LOGBACK);
	m_brBack.CreatePatternBrush(&m_bmBack);

	m_IP.SetWindowText("127.0.0.1");
	
	m_bnLogin.LoadBitmaps(IDB_LOGINUP,IDB_LOGINDOWN);
	
	//初始化图像列表
	m_imageList.Create(32, 32, ILC_COLOR16, 6, 6);
	for(int i = 0; i < 6; i++)
	{
		m_imageList.Add( 
			LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(132 + i) )
			);
	}

	//为组合框设置图像列表
	m_Photo.SetImageList(&m_imageList);
	
	//将图像插入到组合框中
	for(i=0; i<m_imageList.GetImageCount(); i++)
	{
		COMBOBOXEXITEM cbi ={0};
		CString str;
		int nItem;
		
		cbi.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
		
		cbi.iItem = i;
		str.Format(_T("%2d"), i+1);
		cbi.pszText = str.GetBuffer(0);
		cbi.cchTextMax = str.GetLength();
		cbi.iImage = i;
		cbi.iSelectedImage = i;

		//为组合框添加新项目
		nItem = m_Photo.InsertItem(&cbi);
		ASSERT(nItem == i);
	}

	//设置当前的选择
	m_Photo.SetCurSel(0);

	return TRUE;
}

HBRUSH CLogDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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


void CLogDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	//m_imgNum记录的是索引号
	m_imgNum = m_Photo.GetCurSel();
	m_IP.GetWindowText(m_ipAddr,16);

	OnOK();
}
