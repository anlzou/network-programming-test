//Download by www.cctry.com
// ComboExCtrl.h : main header file for the COMBOEXCTRL application
//

#if !defined(AFX_COMBOEXCTRL_H__6638A2E8_B654_4044_BD49_10CC0F9E1234__INCLUDED_)
#define AFX_COMBOEXCTRL_H__6638A2E8_B654_4044_BD49_10CC0F9E1234__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboExCtrlApp:
// See ComboExCtrl.cpp for the implementation of this class
//

class CComboExCtrlApp : public CWinApp
{
public:
	CComboExCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboExCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComboExCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOEXCTRL_H__6638A2E8_B654_4044_BD49_10CC0F9E1234__INCLUDED_)
