//Download by www.cctry.com
// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CHtmlView)

BEGIN_MESSAGE_MAP(CTestView, CHtmlView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_LAST, OnLast)
	ON_COMMAND(ID_NEXT, OnNext)
	ON_COMMAND(ID_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CTestView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	//	Navigate2("www.baidu.com",NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing


/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers



void CTestView::OnLast() 
{
	// TODO: Add your command handler code here
	this->GoBack();
}

void CTestView::OnNext() 
{
	// TODO: Add your command handler code here
	this->GoForward();
}

void CTestView::OnRefresh() 
{
	// TODO: Add your command handler code here
	this->Refresh();
}


