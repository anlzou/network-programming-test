//Download by www.cctry.com
// FTP_client.h : main header file for the FTP_CLIENT application
//

#if !defined(AFX_FTP_CLIENT_H__6A3B7E64_5169_49A6_854E_66656C2B1093__INCLUDED_)
#define AFX_FTP_CLIENT_H__6A3B7E64_5169_49A6_854E_66656C2B1093__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTP_clientApp:
// See FTP_client.cpp for the implementation of this class
//

class CFTP_clientApp : public CWinApp
{
public:
	CFTP_clientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTP_clientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFTP_clientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_CLIENT_H__6A3B7E64_5169_49A6_854E_66656C2B1093__INCLUDED_)