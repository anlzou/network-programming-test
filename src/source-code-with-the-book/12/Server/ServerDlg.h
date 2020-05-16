//Download by www.cctry.com
// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__4A17D344_E7AD_4EAD_BD42_F8015CBF679D__INCLUDED_)
#define AFX_SERVERDLG_H__4A17D344_E7AD_4EAD_BD42_F8015CBF679D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//add new
#include <afxmt.h>			//引入临界区的支持

#include "MySocket.h"

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

	//有用户退出
	void ClosePlayer(CMySocket *from);

	//解析消息
	void ParserPkt(CMySocket *from);

	//向聊天室追加动态信息
	void Append(char *msg);


// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CListCtrl	m_List;
	CString		m_Ctx;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:

	CMySocket	m_socket;
	CCriticalSection m_csList;
	CBitmapButton m_bnRun;

// Implementation
protected:
	HICON m_hIcon;
	CBitmap m_bmBack;
	CBrush  m_brBack;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnrun();
	//}}AFX_MSG
	afx_msg void OnSocket(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__4A17D344_E7AD_4EAD_BD42_F8015CBF679D__INCLUDED_)
