// MfcTcpServerDlg.h : header file
//

#if !defined(AFX_MFCTCPSERVERDLG_H__D9539CC7_D071_4C88_952A_981307DCDA8C__INCLUDED_)
#define AFX_MFCTCPSERVERDLG_H__D9539CC7_D071_4C88_952A_981307DCDA8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMfcTcpServerDlg dialog

class CMfcTcpServerDlg : public CDialog
{
// Construction
public:
	CMfcTcpServerDlg(CWnd* pParent = NULL);	// standard constructor

	//anlzou add 
	SOCKET s,s1;						//定义套接字句柄
	sockaddr_in addr,add1;					//定义套接字地址结构变量
	int n;
	//anlzou add end.

// Dialog Data
	//{{AFX_DATA(CMfcTcpServerDlg)
	enum { IDD = IDD_MFCTCPSERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcTcpServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMfcTcpServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG

	//anlzou add
	afx_msg void OnSend();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);	//自定义消息响应函数
	//anlzou add end.
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTCPSERVERDLG_H__D9539CC7_D071_4C88_952A_981307DCDA8C__INCLUDED_)
