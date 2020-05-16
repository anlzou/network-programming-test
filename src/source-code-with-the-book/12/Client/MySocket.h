//Download by www.cctry.com
#if !defined(AFX_MYSOCKET_H__329D897B_F2A6_44B1_95E9_C242FF12E48C__INCLUDED_)
#define AFX_MYSOCKET_H__329D897B_F2A6_44B1_95E9_C242FF12E48C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//

#define SOCKET_EVENT WM_USER + 1001

enum {ACCEPT = 0,SEND = 1,RETR = 2,CLOSE = 3};

/////////////////////////////////////////////////////////////////////////////
// CMySocket command target

class CMySocket : public CSocket
{
// Attributes
public:
	CWnd *pWnd;

// Operations
public:
	CMySocket();
	virtual ~CMySocket();
	void AttachCWnd(CWnd *pWnd);

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySocket)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__329D897B_F2A6_44B1_95E9_C242FF12E48C__INCLUDED_)
