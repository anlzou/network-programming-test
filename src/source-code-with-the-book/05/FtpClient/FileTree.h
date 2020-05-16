//Download by www.cctry.com
#if !defined(AFX_FILETREE_H__4CD45F39_CBD1_4ACC_ABC9_4544D405B1C3__INCLUDED_)
#define AFX_FILETREE_H__4CD45F39_CBD1_4ACC_ABC9_4544D405B1C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileTree view

class CFileTree : public CTreeView
{
protected:
	CFileTree();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFileTree)

// Attributes
public:
	CTreeCtrl		*tree;				//指向treeview本身
	CImageList		m_lpImagelist;		//存放自定义的文件和文件夹图标
	CImageList*		m_pDragImage;       //拖动时显示的图象列表
	HTREEITEM		m_hItemDragS;		//被拖动的标签项
	BOOL			m_bDragging;		//鼠标是否处于拖动状态
	CString			m_filename;			//被拖动的文件名
	CString			m_fileLname;		//保存父节点+子节点文件名，用来构造路径

// Operations
public:
	VOID BrowseDir(CString strDir,HTREEITEM hParent);	//遍历文件夹--由用户输入路径
	VOID deleteItem();									//删除树视图中的所有项
	void GetCtrlRect(CRect *rt);						//获取树视图窗口矩形大小

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileTree)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFileTree();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileTree)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETREE_H__4CD45F39_CBD1_4ACC_ABC9_4544D405B1C3__INCLUDED_)
