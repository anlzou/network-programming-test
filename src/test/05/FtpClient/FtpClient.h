//Download by www.cctry.com
// FtpClient.h : main header file for the FTPCLIENT application
//

#if !defined(AFX_FTPCLIENT_H__07B19186_0074_4BED_9022_CCEA73CBA048__INCLUDED_)
#define AFX_FTPCLIENT_H__07B19186_0074_4BED_9022_CCEA73CBA048__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtpClientApp:
// See FtpClient.cpp for the implementation of this class
//

class CFtpClientApp : public CWinApp
{
public:
	CFtpClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFtpClientApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCLIENT_H__07B19186_0074_4BED_9022_CCEA73CBA048__INCLUDED_)
