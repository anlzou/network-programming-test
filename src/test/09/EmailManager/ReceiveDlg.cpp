//Download by www.cctry.com
// ReceiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "emailmanager.h"
#include "ReceiveDlg.h"

//add new
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString g_strUser;
CString g_strPsd;
CString g_strServer;
CWnd *pWnd = NULL;

_bstr_t g_bstrFrom;
_bstr_t g_bstrSubject;
_bstr_t g_bstrBody;
COleDateTime g_oleDate;

long i = 0;				//列表插入点
CStringArray g_strDetailArray;	

/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg dialog

UINT ReceiveMail( LPVOID lparam)
{
	::CoInitialize(NULL);
	try
	{	
		pWnd->PostMessage(WM_MY_GET,1,0);
		jmail::IPOP3Ptr pPOP3("JMail.POP3");
		jmail::IMessagesPtr pMessages;
		
		// 设置连接服务器超时限制 30S
		pPOP3->Timeout = 30;
		
		// 连接邮件服务器，110为pop3默认端口号
		pPOP3->Connect((LPCTSTR)g_strUser,
			(LPCTSTR)g_strPsd, 
			(LPCTSTR)g_strServer, 
			110);
		
		pMessages = pPOP3->Messages;
		pWnd->PostMessage(WM_MY_GET,2,0);
		// 已下载的邮件的实际个数(因为第0个ITEM是未用的，所以-1)
		long lCount = pMessages->Count - 1;
		if(lCount == 0)
			AfxMessageBox("信箱为空");
		else
		{
			jmail::IMessagePtr pMessage;
			
			// 遍历每封信
			for( i = 1; i <= lCount; i++)
			{
				pMessage = pMessages->Item[i];
				//信件的具体信息
				g_bstrFrom = pMessage->From;
				g_bstrSubject = pMessage->Subject;
				g_bstrBody = pMessage->Body;
				g_oleDate = pMessage->Date;
				//往list控件中添加信件信息
				
				//显示信件的主体文本
				g_strDetailArray.Add((const char*)g_bstrBody);
				pWnd->PostMessage(WM_MY_GET,4,0);
				pMessage.Release();
			}
			pWnd->PostMessage(WM_MY_GET,3,0);
		}
		// 断开连接
		pPOP3->Disconnect();
	}
	//提示错误信息
	catch(_com_error e)
	{
		pWnd->PostMessage(WM_MY_GET,3,0);
		CString strErr;
		strErr.Format("错误信息：%s\r\n错误描述：%s", (LPCTSTR)e.ErrorMessage(),
			(LPCTSTR)e.Description());
		AfxMessageBox(strErr);		
	}
	return 0;
}	

int CReceiveDlg::getMail()
{
	pWnd = CWnd::FromHandle(m_hWnd);
	AfxBeginThread(ReceiveMail,NULL,0);
	return 0;
}

CReceiveDlg::CReceiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReceiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReceiveDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}

CReceiveDlg::CReceiveDlg(CString serverIP,CString user, CString psd)
					:CDialog(CReceiveDlg::IDD, NULL)
{
	g_strServer = serverIP;
	g_strUser = user;
	g_strPsd = psd;
}	

void CReceiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReceiveDlg)
	DDX_Control(pDX, IDC_CLEAR, m_bnClear);
	DDX_Control(pDX, IDC_UPDATE, m_bnUpdate);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReceiveDlg, CDialog)
	//{{AFX_MSG_MAP(CReceiveDlg)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MY_GET,OnProgress)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg message handlers

BOOL CReceiveDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bmBack.DeleteObject();
	m_brBack.DeleteObject();
	m_bmBack.LoadBitmap(IDB_RECVBACK);					//导入背景图片
	m_brBack.CreatePatternBrush(&m_bmBack);		//保存窗体背景图片，供OnCtlColor()调用

	::SendMessage(m_list.m_hWnd,
		LVM_SETEXTENDEDLISTVIEWSTYLE,
		LVS_EX_FULLROWSELECT,
		LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0, "发件人", LVCFMT_LEFT, 130);
	m_list.InsertColumn(1, "主题", LVCFMT_LEFT, 350);
	m_list.InsertColumn(2, "日期", LVCFMT_LEFT, 100);

	CString strFontName = _T("隶书");

	//刷新列表
	
	//set bitmap
	m_bnUpdate.SetBitmaps(IDB_BTN_NORMAL, IDB_BTN_DOWN, IDB_BTN_HLIGHT);
	m_bnUpdate.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255));
	m_bnUpdate.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));
	m_bnUpdate.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnUpdate.SizeToContent();
	m_bnUpdate.SetWindowText(TEXT("刷新列表"));
	m_bnUpdate.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	
	//set font
	m_bnUpdate
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95))					//3d阴影颜色
		.SetFontBold(TRUE, FALSE)							//粗体
		.SetFontSize(18, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	//清空列表

	//set bitmap
	m_bnClear.SetBitmaps(IDB_BTN_NORMAL, IDB_BTN_DOWN, IDB_BTN_HLIGHT);
	m_bnClear.SetForceColor(RGB(255, 255, 0), RGB(255, 255, 255), RGB(255, 255, 255));
	m_bnClear.SetSound(MAKEINTRESOURCE(IDR_WAVEMOVE), ::GetModuleHandle(NULL));	
	m_bnClear.SetSound(MAKEINTRESOURCE(IDR_WAVECLICK), ::GetModuleHandle(NULL), TRUE);
	m_bnClear.SizeToContent();
	m_bnClear.SetWindowText(TEXT("清空列表"));
	m_bnClear.SetBtnCursor(IDC_CURSOR_HAND, FALSE);
	
	//set font
	m_bnClear
		.SetDrawText(TRUE, FALSE)							//是否显示按钮文字
		.SetFont3D(TRUE, 3, 2, FALSE)						//显示文字3d效果
		.SetText3DBKColor(RGB(95, 95, 95))					//3d阴影颜色
		.SetFontBold(TRUE, FALSE)							//粗体
		.SetFontSize(18, FALSE)								//字体大小
		.SetFontName(strFontName)							//字体名称
		;

	SetWindowText("收件箱");
	getMail();				//位图
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CReceiveDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
LRESULT CReceiveDlg::OnProgress(LPARAM lparam, WPARAM wparam)
{
	CProgressDlg dlg;
	
	CWnd *pWnd=FindWindow(NULL,"正在处理中...");  
	if(lparam == 1)
	{
		dlg.m_message = "正在连接邮箱服务器，\n请稍后……";
		dlg.DoModal();
	}
	else if(lparam == 2)
	{
		pWnd->SendMessage(WM_CLOSE);
		dlg.m_message = "连接成功，\n正在获取邮件……";
		dlg.DoModal();
	}
	else if(lparam == 3)
	{
		pWnd->SendMessage(WM_CLOSE);
	}
	else if( lparam == 4)
	{
		int nListItem = m_list.InsertItem(i, (const char*)g_bstrFrom);
		m_list.SetItem(nListItem, 1, LVIF_TEXT, (const char*)g_bstrSubject, 0, 0, 0, NULL);
		m_list.SetItem(nListItem, 2, LVIF_TEXT, (const char*)g_oleDate.Format("%Y-%m-%d"),
			0, 0, 0, NULL);
	}
	return 0;
}

void CReceiveDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_list.DeleteAllItems();
	m_edit = "";
	UpdateData(false);
}

void CReceiveDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//获取选定信件的指针
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if(pos)
	{
		int nItem = m_list.GetNextSelectedItem(pos);
		//显示内容
		m_edit= g_strDetailArray.GetAt(nItem);
		UpdateData(FALSE);
	}
	
	*pResult = 0;
}

void CReceiveDlg::OnUpdate() 
{
	// TODO: Add your control notification handler code here

	m_list.DeleteAllItems();
	m_edit = "";
	UpdateData(false);
	getMail();
}
