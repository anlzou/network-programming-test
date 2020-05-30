//Download by www.cctry.com
// FtpClientView.cpp : implementation of the CFtpClientView class
//

#include "stdafx.h"
#include "FtpClient.h"

#include "FtpClientDoc.h"
#include "FtpClientView.h"

//add new
#include "MainFrm.h"
#include "FileTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView

IMPLEMENT_DYNCREATE(CFtpClientView, CListView)

BEGIN_MESSAGE_MAP(CFtpClientView, CListView)
	//{{AFX_MSG_MAP(CFtpClientView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView construction/destruction

CFtpClientView::CFtpClientView()
{
	// TODO: add construction code here
	filelist=&GetListCtrl();
	m_pImageList = NULL;
	m_isDragging = false;
	m_curPath	= "\\";
}

CFtpClientView::~CFtpClientView()
{
}

BOOL CFtpClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView drawing

void CFtpClientView::OnDraw(CDC* pDC)
{
	CFtpClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CFtpClientView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().

	SHFILEINFO		sfi;		//存放文件信息的结构

	//获得系统图像列表
	sys_large_icon = (HIMAGELIST)SHGetFileInfo(NULL,0,&sfi,sizeof(sfi),
		SHGFI_SYSICONINDEX|SHGFI_LARGEICON);	
	
	m_IconList.Attach (sys_large_icon);
	filelist->SetImageList(&m_IconList,LVSIL_NORMAL);
}

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView printing

BOOL CFtpClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFtpClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFtpClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView diagnostics

#ifdef _DEBUG
void CFtpClientView::AssertValid() const
{
	CListView::AssertValid();
}

void CFtpClientView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CFtpClientDoc* CFtpClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFtpClientDoc)));
	return (CFtpClientDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFtpClientView message handlers

VOID CFtpClientView::BrowseDir(CString strDir,CFtpConnection *ftpCon)
{
	CFtpFileFind Ffind(ftpCon);
	int col = 0;

	BOOL IsTrue = Ffind.FindFile(strDir + "*");

	while(IsTrue)
	{
		IsTrue = Ffind.FindNextFile();

		if( !Ffind.IsDots() && !Ffind.IsDirectory() )
		{
			filelist->InsertItem(col,(LPCTSTR)Ffind.GetFileName(),0);
			col++;
		}
	}
}

void CFtpClientView::GetCtrlRect(CRect *rt)
{	
	filelist->GetClientRect(rt);
	ClientToScreen(*rt);
}

void CFtpClientView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame* mFrm = (CMainFrame*)AfxGetMainWnd();
	CFileTree *pEView = (CFileTree *)(mFrm->m_splitter2.GetPane(0,0)); 
	
	//获取窗口矩形大小
	CRect listRt,treeRt;
	GetCtrlRect(&listRt);
	pEView->GetCtrlRect(&treeRt);
	
	//创建窗口矩形区域
	CRgn listRgn,treeRgn;
	listRgn.CreateRectRgn(listRt.left,listRt.top,listRt.right,listRt.bottom);
	treeRgn.CreateRectRgn(treeRt.left,treeRt.top,treeRt.right,treeRt.bottom);
	
	CPoint  pt = point;
	ClientToScreen(&pt);
	if( m_isDragging && (listRgn.PtInRegion(pt) || treeRgn.PtInRegion(pt) ) )  
	{   			
		CImageList::DragMove(pt);
	}
	
	CListView::OnMouseMove(nFlags, point);
}

void CFtpClientView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CMainFrame* mFrm = (CMainFrame*)AfxGetMainWnd();
	CFileTree *pEView = (CFileTree *)(mFrm->m_splitter2.GetPane(0,0)); 

	if( m_isDragging )   
	{   
		m_isDragging  =  false;
		CImageList::DragLeave(this);	//解锁窗口
		CImageList::EndDrag();  
		ReleaseCapture();
		
		ClientToScreen( &point);
		CPoint  pt = point;
		
		CRect treeRt;
		pEView->GetCtrlRect(&treeRt);
		
		CRgn treeRgn;
		treeRgn.CreateRectRgn(treeRt.left,treeRt.top,treeRt.right,treeRt.bottom);
		
		if( treeRgn.PtInRegion(pt))		//释放点的位置
		{   
			CString strTemp = "\\";
			//下载文件
			mFrm->m_pFtpConnection->GetFile(m_fileCopy,
				mFrm->strDisc + strTemp + m_filename);
		}
	} 	
	
	CListView::OnLButtonUp(nFlags, point);
}

void CFtpClientView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	//find the first item that matches the specified flags
	int nSelected = filelist->GetNextItem(-1, LVNI_SELECTED); 
	
	//得到用于拖动时显示的图象列表
	CPoint pt;	
	filelist->ClientToScreen( &pt );
	m_pImageList = filelist->CreateDragImage(nSelected, &pt); 
	if( !m_pImageList )
		return;
	
	//开始拖动
	m_isDragging  =  true; 
	m_pImageList->BeginDrag( 0, CPoint(8,8) ); 
	ClientToScreen( &pt );
	m_pImageList->DragEnter( NULL,pt );
	SetCapture();

	//获取选择项的文件路径
	POSITION pos = filelist->GetFirstSelectedItemPosition ();
	int nItem=filelist->GetNextSelectedItem (pos);
	m_filename=filelist->GetItemText (nItem,0);
	m_fileCopy = m_curPath + m_filename;	

	*pResult = 0;
}
VOID CFtpClientView::deleteItem()
{
	filelist->DeleteAllItems();
}


