//Download by www.cctry.com
// MFC¿Ø¼þ´®¿Ú±à³ÌDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_MFCDLG_H__689EFA08_8F30_4CFB_B4EE_E058932BC0AC__INCLUDED_)
#define AFX_MFCDLG_H__689EFA08_8F30_4CFB_B4EE_E058932BC0AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

class CMFCDlg : public CDialog
{
// Construction
public:
	CMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCDlg)
	enum { IDD = IDD_MFC_DIALOG };
	CString	m_recv1;
	CString	m_recv2;
	CString	m_send1;
	CString	m_send2;
	CMSComm	m_mscom1;
	CMSComm	m_mscom2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendbtn1();
	afx_msg void OnSendbtn2();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnOnCommMscomm2();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLG_H__689EFA08_8F30_4CFB_B4EE_E058932BC0AC__INCLUDED_)
