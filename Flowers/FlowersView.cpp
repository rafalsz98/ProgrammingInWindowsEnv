
// FlowersView.cpp : implementation of the CFlowersView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Flowers.h"
#endif

#include "FlowersDoc.h"
#include "FlowersView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "FlowerDialog.h"


// CFlowersView

IMPLEMENT_DYNCREATE(CFlowersView, CView)

BEGIN_MESSAGE_MAP(CFlowersView, CView)
	ON_COMMAND(ID_KWIACIARNIA_DIALOG, &CFlowersView::OnKwiaciarniaDialog)
END_MESSAGE_MAP()

// CFlowersView construction/destruction

CFlowersView::CFlowersView() noexcept
{
	// TODO: add construction code here

}

CFlowersView::~CFlowersView()
{
}

BOOL CFlowersView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFlowersView drawing

void CFlowersView::OnDraw(CDC* /*pDC*/)
{
	CFlowersDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFlowersView diagnostics

#ifdef _DEBUG
void CFlowersView::AssertValid() const
{
	CView::AssertValid();
}

void CFlowersView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlowersDoc* CFlowersView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlowersDoc)));
	return (CFlowersDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlowersView message handlers


void CFlowersView::OnKwiaciarniaDialog()
{
	CFlowerDialog dialog;
	if (dialog.DoModal() == IDOK)
	{
		AfxMessageBox(L"Exited the shop");
	}
	// TODO: Add your command handler code here
}
