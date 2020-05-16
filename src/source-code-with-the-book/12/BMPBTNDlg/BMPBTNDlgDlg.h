//Download by www.cctry.com
// BMPBTNDlgDlg.h : header file
//

#if !defined(AFX_BMPBTNDLGDLG_H__56E49880_9257_49EE_A12D_20F5C6A2AFCA__INCLUDED_)
#define AFX_BMPBTNDLGDLG_H__56E49880_9257_49EE_A12D_20F5C6A2AFCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNDlgDlg dialog

class CBMPBTNDlgDlg : public CDialog
{
// Construction
public:
	CBMPBTNDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBMPBTNDlgDlg)
	enum { IDD = IDD_BMPBTNDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBMPBTNDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CBitmapButton	m_bmpBtn;
	BOOL			m_flag;

	// Generated message map functions
	//{{AFX_MSG(CBMPBTNDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDisable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBTNDLGDLG_H__56E49880_9257_49EE_A12D_20F5C6A2AFCA__INCLUDED_)
