//Download by www.cctry.com
// BMPBTNWndDoc.h : interface of the CBMPBTNWndDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPBTNWNDDOC_H__654CA86E_75C1_4517_862E_C76670F3EC75__INCLUDED_)
#define AFX_BMPBTNWNDDOC_H__654CA86E_75C1_4517_862E_C76670F3EC75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBMPBTNWndDoc : public CDocument
{
protected: // create from serialization only
	CBMPBTNWndDoc();
	DECLARE_DYNCREATE(CBMPBTNWndDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBMPBTNWndDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBMPBTNWndDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBMPBTNWndDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBTNWNDDOC_H__654CA86E_75C1_4517_862E_C76670F3EC75__INCLUDED_)
