//Download by www.cctry.com
// ComboExCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComboExCtrl.h"
#include "ComboExCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboExCtrlDlg dialog

CComboExCtrlDlg::CComboExCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboExCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComboExCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboExCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComboExCtrlDlg)
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_comboEx);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CComboExCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CComboExCtrlDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETSEL, OnGetsel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboExCtrlDlg message handlers

BOOL CComboExCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_imagelist.Create(32,32,ILC_COLOR16,6,6);
	for(int i = 0;i < 6;i++)
	{
		m_imagelist.Add(
			LoadIcon( AfxGetInstanceHandle(),MAKEINTRESOURCE( IDI_ICON1+i ) )
			);
	}

	m_comboEx.SetImageList(&m_imagelist);
	for(int j = 0;j < 6;j++)
	{
		CString strName;
		strName.Format("Image%d",j);

		COMBOBOXEXITEM comboEx;
		memset(&comboEx,0,sizeof(comboEx));
		comboEx.mask = CBEIF_IMAGE | CBEIF_TEXT | CBEIF_SELECTEDIMAGE;
		comboEx.iItem = j;
		comboEx.pszText = strName.GetBuffer(0);
		comboEx.iImage = j;
		comboEx.iSelectedImage = j;

		int index = m_comboEx.InsertItem(&comboEx);
		ASSERT(index == j);
	}

	m_comboEx.SetCurSel(0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboExCtrlDlg::OnPaint() 
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
HCURSOR CComboExCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CComboExCtrlDlg::OnGetsel() 
{
	// TODO: Add your control notification handler code here
		int index = m_comboEx.GetCurSel();

		CString strSel;
		strSel.Format("当前选中第%d项",index+1);

		AfxMessageBox(strSel);
}
