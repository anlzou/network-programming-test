//Download by www.cctry.com
// BMPBTNWndView.cpp : implementation of the CBMPBTNWndView class
//

#include "stdafx.h"
#include "BMPBTNWnd.h"

#include "BMPBTNWndDoc.h"
#include "BMPBTNWndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndView

IMPLEMENT_DYNCREATE(CBMPBTNWndView, CView)

BEGIN_MESSAGE_MAP(CBMPBTNWndView, CView)
	//{{AFX_MSG_MAP(CBMPBTNWndView)
	ON_COMMAND(IDM_TEST, OnTest)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndView construction/destruction

CBMPBTNWndView::CBMPBTNWndView()
{
	// TODO: add construction code here
	m_flag = FALSE;
}

CBMPBTNWndView::~CBMPBTNWndView()
{
}

BOOL CBMPBTNWndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndView drawing

void CBMPBTNWndView::OnDraw(CDC* pDC)
{
	CBMPBTNWndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndView diagnostics

#ifdef _DEBUG
void CBMPBTNWndView::AssertValid() const
{
	CView::AssertValid();
}

void CBMPBTNWndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBMPBTNWndDoc* CBMPBTNWndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBMPBTNWndDoc)));
	return (CBMPBTNWndDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndView message handlers

void CBMPBTNWndView::OnTest() 
{
	// TODO: Add your command handler code here
	m_bmpBtn.EnableWindow(m_flag);
	m_flag = !m_flag;
}

int CBMPBTNWndView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_bmpBtn.Create("bmpBtn",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,
		CRect(20,20,190,60),this,NULL);
	
	m_bmpBtn.LoadBitmaps(IDB_BIT_UP,IDB_BIT_DOWN,IDB_BIT_FOCUS,IDB_BIT_DISABLE);

	return 0;
}
