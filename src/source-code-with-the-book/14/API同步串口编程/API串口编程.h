//Download by www.cctry.com
// API串口编程.h : main header file for the API串口编程 application
//

#if !defined(AFX_API_H__32C50196_D66D_4C95_AFF8_990B539C09D9__INCLUDED_)
#define AFX_API_H__32C50196_D66D_4C95_AFF8_990B539C09D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAPIApp:
// See API串口编程.cpp for the implementation of this class
//

class CAPIApp : public CWinApp
{
public:
	CAPIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAPIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAPIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_API_H__32C50196_D66D_4C95_AFF8_990B539C09D9__INCLUDED_)
