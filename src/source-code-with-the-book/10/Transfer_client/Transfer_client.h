//Download by www.cctry.com
// Transfer_client.h : main header file for the TRANSFER_CLIENT application
//

#if !defined(AFX_TRANSFER_CLIENT_H__33AA737C_071F_4183_928E_5F0E46E9C11E__INCLUDED_)
#define AFX_TRANSFER_CLIENT_H__33AA737C_071F_4183_928E_5F0E46E9C11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransfer_clientApp:
// See Transfer_client.cpp for the implementation of this class
//

class CTransfer_clientApp : public CWinApp
{
public:
	CTransfer_clientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransfer_clientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransfer_clientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFER_CLIENT_H__33AA737C_071F_4183_928E_5F0E46E9C11E__INCLUDED_)
