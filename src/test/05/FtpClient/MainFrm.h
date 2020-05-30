//Download by www.cctry.com
// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__166EC115_44D2_42BC_B717_685753E286B6__INCLUDED_)
#define AFX_MAINFRM_H__166EC115_44D2_42BC_B717_685753E286B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//add new
#include < afxinet.h >		//为了使用CFtpConnect CInternetSession

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CSplitterWnd	m_splitter1;
	CSplitterWnd	m_splitter2;
	BOOL			m_bConnect;			//与FTP服务器的连接状态
	CFtpConnection	*m_pFtpConnection;
	CInternetSession *m_pInetSession; 
	CString			m_curPath;			//服务器根目录
	CString			strDisc;			//本地文件路径--由用户输入

	CDialogBar		m_myDlg;			//浮动对话框

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
//	CStatusBar  m_wndStatusBar;
//	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG

	//add new
	afx_msg void OnConnect();
	afx_msg void OnChooseDisc();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__166EC115_44D2_42BC_B717_685753E286B6__INCLUDED_)
