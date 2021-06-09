// Win2Doc.cpp : implementation file
//

#include "pch.h"
#include "Win2Doc.h"


// CWin2Doc

IMPLEMENT_DYNCREATE(CWin2Doc, CDocument)

CWin2Doc::CWin2Doc()
{
}

BOOL CWin2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CWin2Doc::~CWin2Doc()
{
}


BEGIN_MESSAGE_MAP(CWin2Doc, CDocument)
END_MESSAGE_MAP()


// CWin2Doc diagnostics

#ifdef _DEBUG
void CWin2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CWin2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CWin2Doc serialization

void CWin2Doc::Serialize(CArchive& ar)
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


// CWin2Doc commands
