//Download by www.cctry.com
// API´®¿Ú±à³ÌDlg.h : header file
//

#if !defined(AFX_APIDLG_H__10DDC432_19C0_478D_882B_757C72D5716A__INCLUDED_)
#define AFX_APIDLG_H__10DDC432_19C0_478D_882B_757C72D5716A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAPIDlg dialog

class CAPIDlg : public CDialog
{
// Construction
public:
	CAPIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAPIDlg)
	enum { IDD = IDD_API_DIALOG };
	CString	m_recv;
	CString	m_send;
	CString	m_recv2;
	CString	m_send2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAPIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE handleFile;
	HANDLE handleFile2;

	// Generated message map functions
	//{{AFX_MSG(CAPIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendbtn();
	afx_msg void OnRecvbtn();
	virtual void OnCancel();
	afx_msg void OnSendbtn2();
	afx_msg void OnRecvbtn2();
	afx_msg void OnCancel2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APIDLG_H__10DDC432_19C0_478D_882B_757C72D5716A__INCLUDED_)
