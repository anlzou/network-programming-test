//Download by www.cctry.com
#if !defined(AFX_RECEIVEDLG_H__5D70E4B9_4C13_4DF2_82FE_5D0FD6F7ABCD__INCLUDED_)
#define AFX_RECEIVEDLG_H__5D70E4B9_4C13_4DF2_82FE_5D0FD6F7ABCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReceiveDlg.h : header file
//

//add new
#include "BitButtonNL.h"

#define WM_MY_GET (WM_USER +100)
/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg dialog

class CReceiveDlg : public CDialog
{
// Construction
public:
	CReceiveDlg(CString serverIP,CString user, CString psd);
	CReceiveDlg(CWnd* pParent = NULL);   // standard constructor

	int getMail();
	LRESULT OnProgress(LPARAM lparam, WPARAM wparam);

// Dialog Data
	//{{AFX_DATA(CReceiveDlg)
	enum { IDD = IDD_RECVDLG };
	CBitButtonNL	m_bnClear;
	CBitButtonNL	m_bnUpdate;
	CListCtrl	m_list;
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmap	m_bmBack;
	CBrush	m_brBack;

//	CString m_R_ip;
//	CString m_R_username;
//	CString m_R_password;

	// Generated message map functions
	//{{AFX_MSG(CReceiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClear();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEDLG_H__5D70E4B9_4C13_4DF2_82FE_5D0FD6F7ABCD__INCLUDED_)
