//Download by www.cctry.com
// TCP客户端程序Dlg.h : header file
//

#if !defined(AFX_TCPDLG_H__F0FFC381_139D_4BAC_9B81_B103C49E225B__INCLUDED_)
#define AFX_TCPDLG_H__F0FFC381_139D_4BAC_9B81_B103C49E225B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_SOCKET WM_USER+100						//定义自定义消息
/////////////////////////////////////////////////////////////////////////////
// CTCPDlg dialog

class CTCPDlg : public CDialog
{
// Construction
public:
	CTCPDlg(CWnd* pParent = NULL);	// standard constructor

	SOCKET s;										//定义套接字对象
	sockaddr_in addr;								//定义套接字地址结构变量

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
	
	//自定义消息响应函数
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam); 

	// Generated message map functions
	//{{AFX_MSG(CTCPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDLG_H__F0FFC381_139D_4BAC_9B81_B103C49E225B__INCLUDED_)
