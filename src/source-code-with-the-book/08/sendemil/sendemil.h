//Download by www.cctry.com
// sendemil.h : main header file for the SENDEMIL application
//

#if !defined(AFX_SENDEMIL_H__AA857E7A_D892_4711_B0BD_A256649E8F65__INCLUDED_)
#define AFX_SENDEMIL_H__AA857E7A_D892_4711_B0BD_A256649E8F65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSendemilApp:
// See sendemil.cpp for the implementation of this class
//

class CSendemilApp : public CWinApp
{
public:
	CSendemilApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendemilApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSendemilApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDEMIL_H__AA857E7A_D892_4711_B0BD_A256649E8F65__INCLUDED_)
