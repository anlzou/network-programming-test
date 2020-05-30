//Download by www.cctry.com
// FileTree.cpp : implementation file
//

#include "stdafx.h"
#include "FtpClient.h"
#include "FileTree.h"

//add new
#include "MainFrm.h"
#include "FtpClientView.h"
#include "MsgShow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileTree

IMPLEMENT_DYNCREATE(CFileTree, CTreeView)

CFileTree::CFileTree()
{
	tree = &GetTreeCtrl();
	m_bDragging = false;
}

CFileTree::~CFileTree()
{
}


BEGIN_MESSAGE_MAP(CFileTree, CTreeView)
	//{{AFX_MSG_MAP(CFileTree)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileTree drawing

void CFileTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CFileTree diagnostics

#ifdef _DEBUG
void CFileTree::AssertValid() const
{
	CTreeView::AssertValid();
}

void CFileTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileTree message handlers
VOID CFileTree::deleteItem()
{
	tree->DeleteAllItems();
}

//注：函数只适用于遍历目录，而非查找文件
VOID CFileTree::BrowseDir(CString strDir,HTREEITEM hParent)
{
	CFileFind	fFind;
	CString		strFileName;
	
	if(strDir.Right(2) != "\\")		//important!
	{
		strDir += "\\*.*";
	}
	
	BOOL IsTrue = fFind.FindFile(strDir);
	
	while(IsTrue)
	{
		IsTrue = fFind.FindNextFile();
		
		if( fFind.IsDirectory() && !fFind.IsDots() )
		{
			CString		strPath = fFind.GetFilePath();
			strFileName = fFind.GetFileName();
			
			HTREEITEM	hChild = tree->InsertItem(strFileName,0,0,hParent);
			
			BrowseDir(strPath,hChild);
		}	
		else  if( !fFind.IsDirectory() && !fFind.IsDots() )
		{
			strFileName = fFind.GetFileName();
			
			tree->InsertItem(strFileName,1,1,hParent);
		}
	}
	
	fFind.Close();
}


BOOL CFileTree::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class

	//add new 更改控件的style
	cs.style |= TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT|TVS_EDITLABELS;
	
	return CTreeView::PreCreateWindow(cs);
}

void CFileTree::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	//获取图标句柄
	HICON hicon1 = AfxGetApp()->LoadIcon(IDI_ICON1);
	HICON hicon2 = AfxGetApp()->LoadIcon(IDI_ICON2);
	
	//创建图标列表
	m_lpImagelist.Create(16,16,ILC_COLOR16,2,2);
	m_lpImagelist.Add(hicon1);
	m_lpImagelist.Add(hicon2);
	
	//关联图像列表
	tree->SetImageList(&m_lpImagelist,TVSIL_NORMAL);
}

void CFileTree::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	//树的叶子节点
	m_hItemDragS = pNMTreeView->itemNew.hItem;

	//获取选择的文件名
	m_filename = tree->GetItemText(m_hItemDragS);

	//有父节点的话，需要获取父节点的文本
	HTREEITEM	m_pParentCode = tree->GetParentItem(m_hItemDragS);
	m_fileLname = m_filename;
	while(m_pParentCode)
	{
		CString strTemp = m_fileLname;
		m_fileLname = tree->GetItemText(m_pParentCode);
		m_fileLname += "\\";
		m_fileLname += strTemp; 
		m_pParentCode = tree->GetParentItem(m_pParentCode);
	}
	
	//得到用于拖动时显示的图象列表
	m_pDragImage = tree->CreateDragImage( m_hItemDragS );
	if( !m_pDragImage )
		return;
	
	//开始拖动
	m_bDragging = true;
	//拖动时的图像索引、鼠标指针相对于图像的位置
	m_pDragImage->BeginDrag ( 0,CPoint(16,8) );	

	CPoint  pt = pNMTreeView->ptDrag;
	ClientToScreen( &pt );
	m_pDragImage->DragEnter(NULL,pt );  //"this"将拖动操作限制在该窗口

	//捕获鼠标的所有事件
	SetCapture();

	*pResult = 0;
}

void CFileTree::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame* mFrm = (CMainFrame*)AfxGetMainWnd();
	CFtpClientView *pEView = (CFtpClientView *)(mFrm->m_splitter2.GetPane(0,1));
	CMsgShow	*pShowMsg = (CMsgShow	*)(mFrm->m_splitter1.GetPane(0,0));

	if(m_bDragging)
	{
		m_bDragging = false;

		//DragLeave() -- Unlocks the window specified by pWndLock and hides the drag image, 
		//allowing the window to be updated. 
		CImageList::DragLeave(this);	//解锁窗口
		CImageList::EndDrag();			//结束拖放
		ReleaseCapture();				//释放鼠标

		//Call this function to redraw the item 
		//in the style used to indicate the target of a drag-and-drop operation. 
		tree->SelectDropTarget(NULL);
		
		CPoint  pt = point;
		ClientToScreen(&pt);
		
		CRect listRt;
		pEView->GetCtrlRect(&listRt);
		
		CRgn listRgn;
		listRgn.CreateRectRgn(listRt.left,listRt.top,listRt.right,listRt.bottom);

		//若文件拖动到了服务器视图的区域内
		if( listRgn.PtInRegion(pt) )  
		{   
			//构建路径
			CString sourFile = mFrm->strDisc + "\\" + m_fileLname;
			CString destFile = "//" + m_filename;

			BOOL IsTrue = mFrm->m_pFtpConnection->PutFile(sourFile, destFile);
			//有错时的提示
			if(!IsTrue)
			{
				DWORD errorNum = GetLastError();
				CString strNum;
				strNum.Format("发生错误，错误号：%d",errorNum);
				AfxMessageBox(strNum);
				return;
			}

			//填写消息提示窗口
			CString strMsg = "成功添加文件：";
			strMsg += m_filename;
			pShowMsg->ShowMsg(strMsg);
		}
	}

	CTreeView::OnLButtonUp(nFlags, point);
}

void CFileTree::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HTREEITEM  hItem;
	
	CMainFrame* mFrm = (CMainFrame*)AfxGetMainWnd();
	CFtpClientView *pEView = 
		(CFtpClientView *)(mFrm->m_splitter2.GetPane(0,1)); 

//	CRect rect;
//	::GetClientRect(mFrm->GetSafeHwnd(),&rect);	//CWnd::GetSafeHwnd()获取窗体的句柄m_hWnd
	
	//矩形位置
	CRect listRt,treeRt;
	pEView->GetCtrlRect(&listRt);	//自定义的函数
	GetCtrlRect(&treeRt);
	
	//区域
	CRgn listRgn,treeRgn;
	listRgn.CreateRectRgn(listRt.left,listRt.top,listRt.right,listRt.bottom);
	treeRgn.CreateRectRgn(treeRt.left,treeRt.top,treeRt.right,treeRt.bottom);

	CPoint  pt = point;
	ClientToScreen(&pt);
	
	//PtInRegion() -- Determines whether a specified point is in the region. 
	if( m_bDragging && ( listRgn.PtInRegion(pt) || treeRgn.PtInRegion(pt) ) )  
	{   			
		CImageList::DragMove( pt );
	}
	else
	{
		//HitTest() -- Returns the current position of the cursor
		//related to the CTreeCtrl object. 
		if( (hItem = tree->HitTest(point)) != NULL )
		{
			//鼠标经过时高亮显示
			tree->SelectDropTarget( hItem );
		}
	}
	
	CTreeView::OnMouseMove(nFlags, point);
}
void CFileTree::GetCtrlRect(CRect *rt)
{
	tree->GetClientRect(rt);
	ClientToScreen(*rt);
}
