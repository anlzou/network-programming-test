//Download by www.cctry.com
#if !defined(AFX_SETDLG_H__0D982D9B_11C6_482A_9345_2DF3FEB11C0B__INCLUDED_)
#define AFX_SETDLG_H__0D982D9B_11C6_482A_9345_2DF3FEB11C0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//add new
#include "BitButtonNL.h"

// SetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog

class CSetDlg : public CDialog
{
// Construction
public:
	CSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetDlg)
	enum { IDD = IDD_SET };
	CBitButtonNL	m_bnCancel;
	CBitButtonNL	m_bnOk;
	CString	m_ip;
	CString	m_password;
	CString	m_username;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmap m_bmBack;
	CBrush	m_brBack;

	// Generated message map functions
	//{{AFX_MSG(CSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDLG_H__0D982D9B_11C6_482A_9345_2DF3FEB11C0B__INCLUDED_)
