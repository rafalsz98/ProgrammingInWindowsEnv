
// CalculatorView.cpp : implementation of the CCalculatorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Calculator.h"
#endif

#include "CalculatorDoc.h"
#include "CalculatorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CalculatorDialog.h"


// CCalculatorView

IMPLEMENT_DYNCREATE(CCalculatorView, CView)

BEGIN_MESSAGE_MAP(CCalculatorView, CView)
	ON_COMMAND(ID_CALCULATOR_DIALOG, &CCalculatorView::OnCalculatorDialog)
END_MESSAGE_MAP()

// CCalculatorView construction/destruction

CCalculatorView::CCalculatorView() noexcept
{
	// TODO: add construction code here

}

CCalculatorView::~CCalculatorView()
{
}

BOOL CCalculatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCalculatorView drawing

void CCalculatorView::OnDraw(CDC* /*pDC*/)
{
	CCalculatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCalculatorView diagnostics

#ifdef _DEBUG
void CCalculatorView::AssertValid() const
{
	CView::AssertValid();
}

void CCalculatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCalculatorDoc* CCalculatorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCalculatorDoc)));
	return (CCalculatorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCalculatorView message handlers


void CCalculatorView::OnCalculatorDialog()
{
	CCalculatorDialog dlg;
	dlg.DoModal();
}
