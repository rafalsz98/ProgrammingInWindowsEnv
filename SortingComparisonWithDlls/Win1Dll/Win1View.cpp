// Win1View.cpp : implementation file
//

#include "pch.h"
#include "Win1Dll.h"
#include "Win1View.h"
#include "resource.h"


// CWin1View

IMPLEMENT_DYNCREATE(CWin1View, CView)

CWin1View::CWin1View()
{

}

CWin1View::~CWin1View()
{
}

BEGIN_MESSAGE_MAP(CWin1View, CView)
	
END_MESSAGE_MAP()


// CWin1View drawing

void CWin1View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here

	pDC->TextOutW(50, 50, L"This is a window from Win1Dll");
}


// CWin1View diagnostics

#ifdef _DEBUG
void CWin1View::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWin1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CWin1View message handlers










