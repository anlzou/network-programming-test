//Download by www.cctry.com
// ÍøÂçÍ¨ÐÅClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__4318B779_995D_486A_A464_7F683E41B4B7__INCLUDED_)
#define AFX_CLIENTDLG_H__4318B779_995D_486A_A464_7F683E41B4B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_SOCKET	WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CString	m_ip;
	CString	m_recv;
	CString	m_send;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON	m_hIcon;
	SOCKET	socket_client;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSendbtn();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__4318B779_995D_486A_A464_7F683E41B4B7__INCLUDED_)
