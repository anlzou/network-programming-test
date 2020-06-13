//Download by www.cctry.com
// ÍøÂçÍ¨ÐÅServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__90BC8A7A_00CB_4656_9D02_81E41CCF7EE8__INCLUDED_)
#define AFX_SERVERDLG_H__90BC8A7A_00CB_4656_9D02_81E41CCF7EE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog
#define		WM_SOCKET	WM_USER + 100

class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CString	m_status;
	CString	m_recv;
	CString	m_send;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	SOCKET socket_server;
	SOCKET socket_client;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartrun();
	virtual void OnCancel();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSendbtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__90BC8A7A_00CB_4656_9D02_81E41CCF7EE8__INCLUDED_)
