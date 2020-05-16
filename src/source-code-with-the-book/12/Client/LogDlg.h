//Download by www.cctry.com
#if !defined(AFX_LOGDLG_H__B882AD9F_0488_404F_953B_6809E7A70A82__INCLUDED_)
#define AFX_LOGDLG_H__B882AD9F_0488_404F_953B_6809E7A70A82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogDlg dialog

class CLogDlg : public CDialog
{
// Construction
public:
	CLogDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogDlg)
	enum { IDD = IDD_LOGIN };
	CBitmapButton	m_bnLogin;
	CIPAddressCtrl	m_IP;
	CComboBoxEx		m_Photo;
	CString			m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	//±£´æIP
	char			m_ipAddr[16];
	CImageList		m_imageList;
	int				m_imgNum;		//¼ÇÂ¼Í¼ÏñºÅÂë

// Implementation
protected:
	CBitmap m_bmBack;
	CBrush  m_brBack;

	// Generated message map functions
	//{{AFX_MSG(CLogDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGDLG_H__B882AD9F_0488_404F_953B_6809E7A70A82__INCLUDED_)
