//Download by www.cctry.com
// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "MySocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySocket

CMySocket::CMySocket()
{
	pWnd = NULL;
}

CMySocket::~CMySocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CMySocket, CSocket)
	//{{AFX_MSG_MAP(CMySocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CMySocket member functions

void CMySocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pWnd)
		pWnd->SendMessage(SOCKET_EVENT,(long)this,CLOSE);
	
	CSocket::OnClose(nErrorCode);
}

void CMySocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pWnd)
		pWnd->SendMessage(SOCKET_EVENT,(long)this,RETR);
	
	CSocket::OnReceive(nErrorCode);
}

void CMySocket::AttachCWnd(CWnd *pW)
{
	pWnd = pW;
}
