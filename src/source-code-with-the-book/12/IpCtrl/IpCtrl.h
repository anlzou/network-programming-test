//Download by www.cctry.com
// IpCtrl.h : main header file for the IPCTRL application
//

#if !defined(AFX_IPCTRL_H__6DE32B9A_4F70_45B5_84DB_337BF238DA15__INCLUDED_)
#define AFX_IPCTRL_H__6DE32B9A_4F70_45B5_84DB_337BF238DA15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIpCtrlApp:
// See IpCtrl.cpp for the implementation of this class
//

class CIpCtrlApp : public CWinApp
{
public:
	CIpCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIpCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIpCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCTRL_H__6DE32B9A_4F70_45B5_84DB_337BF238DA15__INCLUDED_)
