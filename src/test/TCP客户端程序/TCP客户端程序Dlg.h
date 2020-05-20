// TCP¿Í»§¶Ë³ÌÐòDlg.h : header file
//

#if !defined(AFX_TCPDLG_H__7900D206_C4BF_4F30_8086_3F2EF2197314__INCLUDED_)
#define AFX_TCPDLG_H__7900D206_C4BF_4F30_8086_3F2EF2197314__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPDlg dialog

class CTCPDlg : public CDialog
{
// Construction
public:
	CTCPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPDlg)
	enum { IDD = IDD_TCP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDLG_H__7900D206_C4BF_4F30_8086_3F2EF2197314__INCLUDED_)
