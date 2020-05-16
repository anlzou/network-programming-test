//Download by www.cctry.com
// APIÒì²½´®¿Ú±à³ÌDlg.h : header file
//

#if !defined(AFX_APIDLG_H__38AAA257_BC46_464E_830F_71887FEFF0A9__INCLUDED_)
#define AFX_APIDLG_H__38AAA257_BC46_464E_830F_71887FEFF0A9__INCLUDED_

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

	// Generated message map functions
	//{{AFX_MSG(CAPIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendbtn();
	afx_msg void OnRecvbtn();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APIDLG_H__38AAA257_BC46_464E_830F_71887FEFF0A9__INCLUDED_)
