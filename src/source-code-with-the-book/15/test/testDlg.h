//Download by www.cctry.com
// testDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__0D06B317_4BAA_47EB_A62D_059F7E9E57C3__INCLUDED_)
#define AFX_TESTDLG_H__0D06B317_4BAA_47EB_A62D_059F7E9E57C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CComboBox	m_stopbit;
	CComboBox	m_pority;
	CComboBox	m_data;
	CComboBox	m_bo;
	CString	m_phonenum;
	CString	m_context;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConcomm();
	virtual void OnCancel();
	afx_msg void OnSendpdumsg();
	afx_msg void OnSendenglish();
	afx_msg void OnSendchinese();
	afx_msg void OnSendpdumsg2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__0D06B317_4BAA_47EB_A62D_059F7E9E57C3__INCLUDED_)
