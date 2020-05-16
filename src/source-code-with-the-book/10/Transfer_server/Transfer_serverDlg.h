//Download by www.cctry.com
// Transfer_serverDlg.h : header file
//

#if !defined(AFX_TRANSFER_SERVERDLG_H__567BEDC2_CB1C_44EA_ABE5_A93C7E31D844__INCLUDED_)
#define AFX_TRANSFER_SERVERDLG_H__567BEDC2_CB1C_44EA_ABE5_A93C7E31D844__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define		WM_SOCKET	WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CTransfer_serverDlg dialog

class CTransfer_serverDlg : public CDialog
{
// Construction
public:
	CTransfer_serverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransfer_serverDlg)
	enum { IDD = IDD_TRANSFER_SERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransfer_serverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	SOCKET	socket_server;
	SOCKET	socket_client;

	// Generated message map functions
	//{{AFX_MSG(CTransfer_serverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartrun();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSendfile();
	afx_msg void OnRecvfile();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFER_SERVERDLG_H__567BEDC2_CB1C_44EA_ABE5_A93C7E31D844__INCLUDED_)
