//Download by www.cctry.com
// recvemilDlg.h : header file
//

#if !defined(AFX_RECVEMILDLG_H__CD083589_D5E1_4E44_8CBB_F4F8AE47AF15__INCLUDED_)
#define AFX_RECVEMILDLG_H__CD083589_D5E1_4E44_8CBB_F4F8AE47AF15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRecvemilDlg dialog

class CRecvemilDlg : public CDialog
{
// Construction
public:
	CRecvemilDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRecvemilDlg)
	enum { IDD = IDD_RECVEMIL_DIALOG };
	CListBox	m_list;
	CString	m_address;
	CString	m_password;
	CString	m_username;
	CString	m_context;
	CString	m_from;
	CString	m_subject;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecvemilDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON	m_hIcon;
	SOCKET	socket_client;

	// Generated message map functions
	//{{AFX_MSG(CRecvemilDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList();
	afx_msg void OnConnect();
	afx_msg void OnGet();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECVEMILDLG_H__CD083589_D5E1_4E44_8CBB_F4F8AE47AF15__INCLUDED_)
