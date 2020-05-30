//Download by www.cctry.com
// FtpClientDoc.h : interface of the CFtpClientDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPCLIENTDOC_H__9C7C7B19_2109_493C_8FBF_52395F3057E7__INCLUDED_)
#define AFX_FTPCLIENTDOC_H__9C7C7B19_2109_493C_8FBF_52395F3057E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFtpClientDoc : public CDocument
{
protected: // create from serialization only
	CFtpClientDoc();
	DECLARE_DYNCREATE(CFtpClientDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpClientDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFtpClientDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFtpClientDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCLIENTDOC_H__9C7C7B19_2109_493C_8FBF_52395F3057E7__INCLUDED_)
