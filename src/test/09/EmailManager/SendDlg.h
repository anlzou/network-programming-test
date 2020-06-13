//Download by www.cctry.com
#if !defined(AFX_SENDDLG_H__E5A38719_43C5_406D_960D_2024EDC82D24__INCLUDED_)
#define AFX_SENDDLG_H__E5A38719_43C5_406D_960D_2024EDC82D24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendDlg.h : header file
//

#include "BitButtonNL.h"

/////////////////////////////////////////////////////////////////////////////
// CSendDlg dialog

class CSendDlg : public CDialog
{

// Construction
public:
	CSendDlg(CWnd* pParent = NULL);   // standard constructor
	CString		m_sender;
	CString		m_sendPsd;

// Dialog Data
	//{{AFX_DATA(CSendDlg)
	enum { IDD = IDD_SEND };
	CBitButtonNL	m_bnClear;
	CBitButtonNL	m_bnSend;
	CString	m_filePath;
	CString	m_context;
	CString	m_recv;
	CString	m_subject;
	CString	m_smtp_ip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmap		m_bmBack;
	CBrush		m_brBack;

	// Generated message map functions
	//{{AFX_MSG(CSendDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnAppend();
	afx_msg void OnClear();
	afx_msg void OnBtnsend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDDLG_H__E5A38719_43C5_406D_960D_2024EDC82D24__INCLUDED_)
