//Download by www.cctry.com
#if !defined(AFX_MYTOOL_H__B3A65113_1733_40EB_8219_CDCB09DB0072__INCLUDED_)
#define AFX_MYTOOL_H__B3A65113_1733_40EB_8219_CDCB09DB0072__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTool.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTool dialog

class CMyTool : public CDialog
{
// Construction
public:
	CMyTool(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyTool)
	enum { IDD = IDR_MAINFRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTool)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyTool)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTOOL_H__B3A65113_1733_40EB_8219_CDCB09DB0072__INCLUDED_)
