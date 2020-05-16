//Download by www.cctry.com
// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__B8CAD974_8477_412A_99C4_C3FC028681D1__INCLUDED_)
#define AFX_CLIENTDLG_H__B8CAD974_8477_412A_99C4_C3FC028681D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//add new
#include "MySocket.h"

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	~CClientDlg();

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CListCtrl	m_list;
	BOOL	m_check;
	CString	m_ectx;
	CString	m_esay;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString		m_Name;
	CImageList	m_ImageList;
	int			m_curIndex;

	CMySocket	m_socket;
	CBitmap m_bmBack;
	CBrush  m_brBack;

	CBitmapButton m_bSend;

// Implementation
protected:
	HICON m_hIcon;
	//维护用户名列表
	CString pName[100];
	//维护用户名列表项
	int curNum;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnsend();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnSocket(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__B8CAD974_8477_412A_99C4_C3FC028681D1__INCLUDED_)
