//Download by www.cctry.com
// ChildDlg.h : header file
//

#if !defined(AFX_CHILDDLG_H__E80F3BEE_6005_47C0_AC1B_C6B6747373F2__INCLUDED_)
#define AFX_CHILDDLG_H__E80F3BEE_6005_47C0_AC1B_C6B6747373F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildDlg dialog

class CChildDlg : public CDialog
{
// Construction
public:
	CChildDlg(CWnd* pParent = NULL);	// standard constructor
	~CChildDlg();

// Dialog Data
	//{{AFX_DATA(CChildDlg)
	enum { IDD = IDD_CHILD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChildDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	HANDLE hRead;
	HANDLE hWrite;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDLG_H__E80F3BEE_6005_47C0_AC1B_C6B6747373F2__INCLUDED_)
