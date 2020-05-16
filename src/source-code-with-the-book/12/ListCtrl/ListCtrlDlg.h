//Download by www.cctry.com
// ListCtrlDlg.h : header file
//

#if !defined(AFX_LISTCTRLDLG_H__52738C26_5E5F_40C0_84ED_755180A38853__INCLUDED_)
#define AFX_LISTCTRLDLG_H__52738C26_5E5F_40C0_84ED_755180A38853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListCtrlDlg dialog

class CListCtrlDlg : public CDialog
{

// Construction
public:
	CListCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtrlDlg)
	enum { IDD = IDD_LISTCTRL_DIALOG };
	CListCtrl	m_list2;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	int count1,count2;
	CImageList m_imagelist;

	// Generated message map functions
	//{{AFX_MSG(CListCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddnew1();
	afx_msg void OnDelitem1();
	afx_msg void OnClear();
	afx_msg void OnAddnew2();
	afx_msg void OnDelitem2();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLDLG_H__52738C26_5E5F_40C0_84ED_755180A38853__INCLUDED_)
