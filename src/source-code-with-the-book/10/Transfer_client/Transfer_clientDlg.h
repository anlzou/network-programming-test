//Download by www.cctry.com
// Transfer_clientDlg.h : header file
//

#if !defined(AFX_TRANSFER_CLIENTDLG_H__D70A139A_5B08_470D_8749_9AE814C3021D__INCLUDED_)
#define AFX_TRANSFER_CLIENTDLG_H__D70A139A_5B08_470D_8749_9AE814C3021D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransfer_clientDlg dialog

class CTransfer_clientDlg : public CDialog
{
// Construction
public:
	CTransfer_clientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransfer_clientDlg)
	enum { IDD = IDD_TRANSFER_CLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransfer_clientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON	m_hIcon;
	SOCKET	socket_client;

	// Generated message map functions
	//{{AFX_MSG(CTransfer_clientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	virtual void OnCancel();
	afx_msg void OnSendfile();
	afx_msg void OnRecvfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFER_CLIENTDLG_H__D70A139A_5B08_470D_8749_9AE814C3021D__INCLUDED_)
