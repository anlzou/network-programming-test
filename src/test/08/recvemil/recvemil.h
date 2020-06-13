//Download by www.cctry.com
// recvemil.h : main header file for the RECVEMIL application
//

#if !defined(AFX_RECVEMIL_H__35C6C535_2441_42B5_A320_1AF17E0F1BEA__INCLUDED_)
#define AFX_RECVEMIL_H__35C6C535_2441_42B5_A320_1AF17E0F1BEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecvemilApp:
// See recvemil.cpp for the implementation of this class
//

class CRecvemilApp : public CWinApp
{
public:
	CRecvemilApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecvemilApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRecvemilApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECVEMIL_H__35C6C535_2441_42B5_A320_1AF17E0F1BEA__INCLUDED_)
