//Download by www.cctry.com
// MsgShow.cpp : implementation file
//

#include "stdafx.h"
#include "FtpClient.h"
#include "MsgShow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgShow

IMPLEMENT_DYNCREATE(CMsgShow, CEditView)

CMsgShow::CMsgShow()
{
	m_editView = &GetEditCtrl();
}

CMsgShow::~CMsgShow()
{
}


BEGIN_MESSAGE_MAP(CMsgShow, CEditView)
	//{{AFX_MSG_MAP(CMsgShow)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgShow drawing

void CMsgShow::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMsgShow diagnostics

#ifdef _DEBUG
void CMsgShow::AssertValid() const
{
	CEditView::AssertValid();
}

void CMsgShow::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMsgShow message handlers

void CMsgShow::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
}

void CMsgShow::ShowMsg(CString strMsg)
{
	CString strTemp;

	m_editView->GetWindowText(strTemp);
	if(strTemp.GetLength() != 0)
	{
		strTemp += "\r\n";
		strTemp += strMsg;
		m_editView->SetWindowText(strTemp);
		return;
	}
	else
	{
		m_editView->SetWindowText(strMsg);
	}
}
