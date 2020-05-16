//Download by www.cctry.com
// MyTool.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "MyTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTool dialog


CMyTool::CMyTool(CWnd* pParent /*=NULL*/)
	: CDialog(CMyTool::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyTool)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyTool)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyTool, CDialog)
	//{{AFX_MSG_MAP(CMyTool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTool message handlers

