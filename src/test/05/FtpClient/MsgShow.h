//Download by www.cctry.com
#if !defined(AFX_MSGSHOW_H__F658ED20_C3CC_4D9E_BD60_8FB3251FCB22__INCLUDED_)
#define AFX_MSGSHOW_H__F658ED20_C3CC_4D9E_BD60_8FB3251FCB22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgShow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgShow view

class CMsgShow : public CEditView
{
protected:
	CMsgShow();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMsgShow)

// Attributes
public:
	//add new
	CEdit	*m_editView;

// Operations
public:
	void ShowMsg(CString strMsg);	//用于窗体显示信息

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgShow)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMsgShow();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMsgShow)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGSHOW_H__F658ED20_C3CC_4D9E_BD60_8FB3251FCB22__INCLUDED_)
