//Download by www.cctry.com
// IpCtrlDlg.h : header file
//

#if !defined(AFX_IPCTRLDLG_H__3E3992F0_3B23_45B0_BAB2_4595330CDD69__INCLUDED_)
#define AFX_IPCTRLDLG_H__3E3992F0_3B23_45B0_BAB2_4595330CDD69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIpCtrlDlg dialog

class CIpCtrlDlg : public CDialog
{
// Construction
public:
	CIpCtrlDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CIpCtrlDlg)
	enum { IDD = IDD_IPCTRL_DIALOG };
	CIPAddressCtrl	m_ipAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIpCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIpCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetip();
	afx_msg void OnClearip();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCTRLDLG_H__3E3992F0_3B23_45B0_BAB2_4595330CDD69__INCLUDED_)
