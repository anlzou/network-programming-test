//Download by www.cctry.com
// ListCtrl.h : main header file for the LISTCTRL application
//

#if !defined(AFX_LISTCTRL_H__E930D516_525D_48F0_BA93_F1146E4B68A8__INCLUDED_)
#define AFX_LISTCTRL_H__E930D516_525D_48F0_BA93_F1146E4B68A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListCtrlApp:
// See ListCtrl.cpp for the implementation of this class
//

class CListCtrlApp : public CWinApp
{
public:
	CListCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRL_H__E930D516_525D_48F0_BA93_F1146E4B68A8__INCLUDED_)
