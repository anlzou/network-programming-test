//Download by www.cctry.com
// BMPBTNWndDoc.cpp : implementation of the CBMPBTNWndDoc class
//

#include "stdafx.h"
#include "BMPBTNWnd.h"

#include "BMPBTNWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndDoc

IMPLEMENT_DYNCREATE(CBMPBTNWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CBMPBTNWndDoc, CDocument)
	//{{AFX_MSG_MAP(CBMPBTNWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndDoc construction/destruction

CBMPBTNWndDoc::CBMPBTNWndDoc()
{
	// TODO: add one-time construction code here

}

CBMPBTNWndDoc::~CBMPBTNWndDoc()
{
}

BOOL CBMPBTNWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndDoc serialization

void CBMPBTNWndDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndDoc diagnostics

#ifdef _DEBUG
void CBMPBTNWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBMPBTNWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBMPBTNWndDoc commands
