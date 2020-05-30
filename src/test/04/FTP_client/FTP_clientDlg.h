//Download by www.cctry.com
// FTP_clientDlg.h : header file
//

#if !defined(AFX_FTP_CLIENTDLG_H__FABA9B10_B549_46B5_82FF_A08A709B355A__INCLUDED_)
#define AFX_FTP_CLIENTDLG_H__FABA9B10_B549_46B5_82FF_A08A709B355A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFTP_clientDlg dialog

class CFTP_clientDlg : public CDialog
{
// Construction
public:
	CFTP_clientDlg(CWnd* pParent = NULL);	// standard constructor

	//连接控制：命令的发送和消息的接收
	void MySockRecv();					//接收信息
	void MySockSend(CString send_msg);	//发送信息

	//数据接收
	BOOL Pasv_mode();					//进入被动模式，接收列表信息
	void Parse_list();					//解析文件列表消息
	void fileStore(CString filename);	//保存文件内容

// Dialog Data
	//{{AFX_DATA(CFTP_clientDlg)
	enum { IDD = IDD_FTP_CLIENT_DIALOG };
	CListBox	m_listfile;
	CListBox	m_listinfo;
	CString	m_host;
	CString	m_password;
	CString	m_username;
	int		m_port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTP_clientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON			m_hIcon;
	CSocket			sock_client;
	CSocket			sock_temp;

	// Generated message map functions
	//{{AFX_MSG(CFTP_clientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnDblclkListfile();
	afx_msg void OnUpdate();
	afx_msg void OnStorefile();
	virtual void OnCancel();
	afx_msg void OnLoadfile();
	afx_msg void OnQuit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_CLIENTDLG_H__FABA9B10_B549_46B5_82FF_A08A709B355A__INCLUDED_)
