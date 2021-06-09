// Win1Doc.cpp : implementation file
//

#include "pch.h"
#include "Win1Dll.h"
#include "Win1Doc.h"


// CWin1Doc

IMPLEMENT_DYNCREATE(CWin1Doc, CDocument)

CWin1Doc::CWin1Doc()
{
}

BOOL CWin1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CWin1Doc::~CWin1Doc()
{
}


BEGIN_MESSAGE_MAP(CWin1Doc, CDocument)
END_MESSAGE_MAP()


// CWin1Doc diagnostics

#ifdef _DEBUG
void CWin1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CWin1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CWin1Doc serialization

void CWin1Doc::Serialize(CArchive& ar)
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
#endif


// CWin1Doc commands
