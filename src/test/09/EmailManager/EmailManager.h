//Download by www.cctry.com
// EmailManager.h : main header file for the EMAILMANAGER application
//

#if !defined(AFX_EMAILMANAGER_H__BFA617E4_9679_4580_A598_E2092F4F4384__INCLUDED_)
#define AFX_EMAILMANAGER_H__BFA617E4_9679_4580_A598_E2092F4F4384__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmailManagerApp:
// See EmailManager.cpp for the implementation of this class
//

class CEmailManagerApp : public CWinApp
{
public:
	CEmailManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEmailManagerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILMANAGER_H__BFA617E4_9679_4580_A598_E2092F4F4384__INCLUDED_)
