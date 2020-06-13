//Download by www.cctry.com
// EmailManagerDlg.h : header file
//

#if !defined(AFX_EMAILMANAGERDLG_H__0FB85727_A646_4D88_BEAC_1FAE5E7BAF49__INCLUDED_)
#define AFX_EMAILMANAGERDLG_H__0FB85727_A646_4D88_BEAC_1FAE5E7BAF49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BitButtonNL.h"

/////////////////////////////////////////////////////////////////////////////
// CEmailManagerDlg dialog

class CEmailManagerDlg : public CDialog
{
// Construction
public:
	CEmailManagerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
//{{AFX_DATA(CEmailManagerDlg)
enum { IDD = IDD_EMAILMANAGER_DIALOG };
CBitButtonNL	m_bnSet;
CBitButtonNL	m_bnSend;
CBitButtonNL	m_bnReceive;
//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString m_EM_ip;
	CString m_EM_username;
	CString m_EM_password;

// Implementation
protected:
	HICON m_hIcon;

	CBitmap m_bmBack;
	CBrush m_brBack;

	// Generated message map functions
	//{{AFX_MSG(CEmailManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSet();
	afx_msg void OnReceive();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILMANAGERDLG_H__0FB85727_A646_4D88_BEAC_1FAE5E7BAF49__INCLUDED_)
