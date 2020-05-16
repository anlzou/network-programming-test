//Download by www.cctry.com
// ComboExCtrlDlg.h : header file
//

#if !defined(AFX_COMBOEXCTRLDLG_H__42EDE470_2DBD_42B6_9AA3_0F4572E1FDFC__INCLUDED_)
#define AFX_COMBOEXCTRLDLG_H__42EDE470_2DBD_42B6_9AA3_0F4572E1FDFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboExCtrlDlg dialog

class CComboExCtrlDlg : public CDialog
{
// Construction
public:
	CComboExCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComboExCtrlDlg)
	enum { IDD = IDD_COMBOEXCTRL_DIALOG };
	CComboBoxEx	m_comboEx;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboExCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CImageList m_imagelist;
	// Generated message map functions
	//{{AFX_MSG(CComboExCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetsel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOEXCTRLDLG_H__42EDE470_2DBD_42B6_9AA3_0F4572E1FDFC__INCLUDED_)
