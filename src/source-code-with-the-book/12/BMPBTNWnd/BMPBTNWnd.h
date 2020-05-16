//Download by www.cctry.com
// BMPBTNWnd.h : main header file for the BMPBTNWND application
//

#if !defined(AFX_BMPBTNWND_H__C53B53B3_E015_4405_91CA_C19416F40C2C__INCLUDED_)
#define AFX_BMPBTNWND_H__C53B53B3_E015_4405_91CA_C19416F40C2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndApp:
// See BMPBTNWnd.cpp for the implementation of this class
//

class CBMPBTNWndApp : public CWinApp
{
public:
	CBMPBTNWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBMPBTNWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBMPBTNWndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBTNWND_H__C53B53B3_E015_4405_91CA_C19416F40C2C__INCLUDED_)
