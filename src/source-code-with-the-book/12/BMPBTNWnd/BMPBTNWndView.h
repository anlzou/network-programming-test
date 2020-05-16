//Download by www.cctry.com
// BMPBTNWndView.h : interface of the CBMPBTNWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPBTNWNDVIEW_H__DB0FF1A4_D83A_4AD5_BE89_F44EC4E93DCA__INCLUDED_)
#define AFX_BMPBTNWNDVIEW_H__DB0FF1A4_D83A_4AD5_BE89_F44EC4E93DCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CBMPBTNWndView : public CView
{
protected: // create from serialization only
	CBMPBTNWndView();
	DECLARE_DYNCREATE(CBMPBTNWndView)

// Attributes
public:
	CBMPBTNWndDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBMPBTNWndView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBMPBTNWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CBitmapButton	m_bmpBtn;
	BOOL			m_flag;

// Generated message map functions
protected:
	//{{AFX_MSG(CBMPBTNWndView)
	afx_msg void OnTest();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BMPBTNWndView.cpp
inline CBMPBTNWndDoc* CBMPBTNWndView::GetDocument()
   { return (CBMPBTNWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBTNWNDVIEW_H__DB0FF1A4_D83A_4AD5_BE89_F44EC4E93DCA__INCLUDED_)
