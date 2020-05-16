//Download by www.cctry.com
// ListCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrl.h"
#include "ListCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlDlg dialog

CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	count1 = count2 = 0;
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListCtrlDlg)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CListCtrlDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDNEW1, OnAddnew1)
	ON_BN_CLICKED(IDC_DELITEM1, OnDelitem1)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_ADDNEW2, OnAddnew2)
	ON_BN_CLICKED(IDC_DELITEM2, OnDelitem2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, OnClickList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlDlg message handlers

BOOL CListCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//初始化图像列表
	HICON	hImage[6];
	for(int i = 0;i < 6;i++)
	{
		hImage[i] = AfxGetApp()->LoadIcon(IDI_ICON1 + i);
	}

	m_imagelist.Create(32,32,ILC_COLOR32,6,6);

	for(int j = 0;j < 6;j++)
	{
		m_imagelist.Add(hImage[j]);
	}

	m_list.SetImageList(&m_imagelist,LVSIL_SMALL);
	m_list2.SetImageList(&m_imagelist,LVSIL_SMALL);

	m_list.InsertColumn(0,"头像",LVCFMT_LEFT,50);
	m_list.InsertColumn(1,"名称",LVCFMT_LEFT,100);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListCtrlDlg::OnPaint() 
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
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListCtrlDlg::OnAddnew1() 
{
	// TODO: Add your control notification handler code here
	
	CString strName;
	strName.Format("Name%d",count1);
	
	LVITEM	lvitem;
	memset(&lvitem,0,sizeof(LVITEM));
	lvitem.mask = LVIF_IMAGE;//LVIF_IMAGE | LVIF_TEXT;
	lvitem.iItem = count1;
	lvitem.iImage = count1 % 6;

	m_list.InsertItem(&lvitem);
	m_list.SetItemText(count1,1,strName.GetBuffer(0));
	count1++;
}

void CListCtrlDlg::OnDelitem1() 
{
	// TODO: Add your control notification handler code here
	
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	while(pos)
	{
		int index = m_list.GetNextSelectedItem(pos);
		m_list.DeleteItem(index);
		count1--;
	}
}

void CListCtrlDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	
	m_list.DeleteAllItems();
	count1 = 0;
	m_list2.DeleteAllItems();
	count2 = 0;
}

void CListCtrlDlg::OnAddnew2() 
{
	// TODO: Add your control notification handler code here
	
	CString strName;
	strName.Format("Name%d",count2);

	m_list2.InsertItem(count2,strName.GetBuffer(0),count2 % 6);
	count2++;
}

void CListCtrlDlg::OnDelitem2() 
{
	// TODO: Add your control notification handler code here
	if(count2 >= 0)
	{
		CString strName;
		strName.Format("Name%d",count2-1);
		
		LVFINDINFO findInfo;
		memset(&findInfo,0,sizeof(findInfo));
		findInfo.flags = LVFI_PARTIAL | LVFI_STRING;
		findInfo.psz = strName.GetBuffer(0);
		
		int f = m_list2.FindItem(&findInfo);
		if( -1 != f)
		{
			m_list2.DeleteItem(f);
		}
		
		count2--;		
	}
}

void CListCtrlDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index = m_list.GetNextItem(-1,LVNI_SELECTED);

	if( -1 != index )
	{
		CString strSay;
		strSay.Format("选中第%d项",index+1);
		AfxMessageBox(strSay);
	}

	*pResult = 0;
}

void CListCtrlDlg::OnClickList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index = m_list2.GetNextItem(-1,LVNI_SELECTED);
	
	if( -1 != index )
	{
		CString strSay;
		strSay.Format("选中第%d项",index+1);
		AfxMessageBox(strSay);
	}
	
	*pResult = 0;
}
