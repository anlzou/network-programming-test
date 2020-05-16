//Download by www.cctry.com
// sendemilDlg.h : header file
//

#if !defined(AFX_SENDEMILDLG_H__CEBEBC52_6933_461C_B104_2B5C5A021DF8__INCLUDED_)
#define AFX_SENDEMILDLG_H__CEBEBC52_6933_461C_B104_2B5C5A021DF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CSendemilDlg dialog

class CSendemilDlg : public CDialog
{
// Construction
public:
	CSendemilDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendemilDlg)
	enum { IDD = IDD_SENDEMIL_DIALOG };
	CString	m_name;
	CString	m_password;
	CString	m_address;
	CString	m_context;
	CString	m_rely;
	CString	m_subject;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendemilDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON	m_hIcon;
	SOCKET	socket_client;

	// Generated message map functions
	//{{AFX_MSG(CSendemilDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSendbtn();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDEMILDLG_H__CEBEBC52_6933_461C_B104_2B5C5A021DF8__INCLUDED_)
