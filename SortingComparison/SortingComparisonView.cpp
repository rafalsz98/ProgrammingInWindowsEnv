
// SortingComparisonView.cpp : implementation of the CSortingComparisonView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SortingComparison.h"
#endif

#include "SortingComparisonDoc.h"
#include "SortingComparisonView.h"
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSortingComparisonView

IMPLEMENT_DYNCREATE(CSortingComparisonView, CView)

BEGIN_MESSAGE_MAP(CSortingComparisonView, CView)
	ON_COMMAND(ID_SORT_SHUFFLE, &CSortingComparisonView::OnSortShuffle)
	ON_COMMAND(ID_SORT_RUN, &CSortingComparisonView::OnSortRun)
	ON_COMMAND(ID_SORT_SETTINGS, &CSortingComparisonView::OnSortSettings)
END_MESSAGE_MAP()

// CSortingComparisonView construction/destruction

CSortingComparisonView::CSortingComparisonView() noexcept
	:
	m_sortsNames({
		L"Bubble",
		L"Half-insertion",
		L"Insertion",
		L"Mixed-bubble",
		L"Selection",
		L"Quick",
		L"Heap"
		}),
	m_pens({
		new CPen{ PS_SOLID, 1, BLACK },
		new CPen{ PS_DASH, 1, GRAY },
		new CPen{ PS_SOLID, 1, RED },
		new CPen{ PS_SOLID, 1, GREEN },
		new CPen{ PS_SOLID, 1, BLUE },
		new CPen{ PS_SOLID, 1, LIGHTRED },
		new CPen{ PS_SOLID, 1, LIGHTGREEN },
		new CPen{ PS_SOLID, 1, LIGHTBLUE },
		new CPen{ PS_SOLID, 1, YELLOW }
		}),
	m_brushes({
		new CBrush { BLACK },
		new CBrush { GRAY },
		new CBrush { RED },
		new CBrush { GREEN },
		new CBrush { BLUE },
		new CBrush { LIGHTRED },
		new CBrush { LIGHTGREEN },
		new CBrush { LIGHTBLUE },
		new CBrush { YELLOW },
	})
{
	m_pClientRect = new CRect(0, 0, 0, 0);
	m_bDrawData = FALSE;
	m_sorts = nullptr;
	m_sortTimes.resize(m_sortsNames.size());
	m_nLineDistance = 0;
	m_nNameDistance = 0;
}

CSortingComparisonView::~CSortingComparisonView()
{
	delete m_pClientRect;
	for (auto pen : m_pens) delete pen;
	for (auto brush : m_brushes) delete brush;
	if (m_sorts != nullptr) delete m_sorts;
}

BOOL CSortingComparisonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSortingComparisonView drawing

void CSortingComparisonView::OnDraw(CDC* pDC)
{
	CSortingComparisonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DrawBackground(pDC);
	DrawData(pDC);
}


// CSortingComparisonView diagnostics

#ifdef _DEBUG
void CSortingComparisonView::AssertValid() const
{
	CView::AssertValid();
}

void CSortingComparisonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSortingComparisonDoc* CSortingComparisonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortingComparisonDoc)));
	return (CSortingComparisonDoc*)m_pDocument;
}
#endif //_DEBUG


// CSortingComparisonView message handlers


void CSortingComparisonView::OnSortShuffle()
{
	if (m_sorts != nullptr)
		m_sorts->ShuffleArray();
}


void CSortingComparisonView::OnSortRun()
{
	if (m_sortingDialog.GetSize() <= 0) return;
	m_bDrawData = TRUE;

	if (m_sorts != nullptr) delete m_sorts;
	m_sorts = new Sorts(m_sortingDialog.GetSize());
	std::fill(m_sortTimes.begin(), m_sortTimes.end(), 0);

	if (m_sortingDialog.IsBubble()) m_sortTimes[0] = m_sorts->MeasureExecutionTime(SortMethod::Bubble);
	if (m_sortingDialog.IsHalfInsertion()) m_sortTimes[1] = m_sorts->MeasureExecutionTime(SortMethod::HalfInsertion);
	if (m_sortingDialog.IsInsertion()) m_sortTimes[2] = m_sorts->MeasureExecutionTime(SortMethod::Insertion);
	if (m_sortingDialog.IsMixedBubble()) m_sortTimes[3] = m_sorts->MeasureExecutionTime(SortMethod::MixedBubble);
	if (m_sortingDialog.IsSelection()) m_sortTimes[4] = m_sorts->MeasureExecutionTime(SortMethod::Selection);
	if (m_sortingDialog.IsQuick()) m_sortTimes[5] = m_sorts->MeasureExecutionTime(SortMethod::Quick);
	if (m_sortingDialog.IsHeap()) m_sortTimes[6] = m_sorts->MeasureExecutionTime(SortMethod::Heap);

	Invalidate();
}

void CSortingComparisonView::OnSortSettings()
{
	m_sortingDialog.DoModal();
}

void CSortingComparisonView::DrawBackground(CDC* pDC)
{
	CPen* old = pDC->SelectObject(m_pens[0]);
	pDC->MoveTo(MARGIN, MARGIN);
	pDC->LineTo(MARGIN, m_pClientRect->bottom - MARGIN);
	pDC->LineTo(m_pClientRect->right - MARGIN, m_pClientRect->bottom - MARGIN);

	for (size_t i = 0; i < m_sortsNames.size(); i++)
	{
		pDC->TextOutW(MARGIN + (int)m_nNameDistance * i, m_pClientRect->bottom - MARGIN + 5, m_sortsNames[i]);
	}

	pDC->SelectObject(m_pens[1]);
	for (int i = 0; i < LINES_DENSITY; i++)
	{
		pDC->MoveTo(MARGIN, MARGIN + m_nLineDistance * i);
		pDC->LineTo(m_pClientRect->right - MARGIN, MARGIN + m_nLineDistance * i);
	}

	pDC->SelectObject(old);
}

void CSortingComparisonView::DrawData(CDC* pDC)
{
	double max = *std::max_element(m_sortTimes.begin(), m_sortTimes.end());
	if (fabs(max) < 1e-3) return;

	double step = max / LINES_DENSITY;
	double value = max;
	for (int i = 0; i < LINES_DENSITY; i++)
	{
		CString str;
		str.Format(L"%.3f", value);
		pDC->TextOutW(MARGIN - 40, MARGIN + i * m_nLineDistance - 5, str);
		value -= step;
	}

	for (size_t i = 0; i < m_sortTimes.size(); i++)
	{
		if (fabs(m_sortTimes[i]) < 1e-3) continue;

		int height = (int)(m_sortTimes[i] / max * (m_pClientRect->bottom - 2.0 * MARGIN));

		CPen* oldPen = pDC->SelectObject(m_pens[i + 2]);
		CBrush* oldBrush = pDC->SelectObject(m_brushes[i + 2]);
		pDC->Rectangle(
			MARGIN + m_nNameDistance * i,
			m_pClientRect->bottom - MARGIN,
			MARGIN + m_nNameDistance * (i + 1),
			m_pClientRect->bottom - MARGIN - height
		);


		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
	}
}


void CSortingComparisonView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	GetClientRect(m_pClientRect);
	m_nNameDistance = (m_pClientRect->right - 2 * MARGIN) / m_sortsNames.size();
	m_nLineDistance = (m_pClientRect->bottom - 2 * MARGIN) / LINES_DENSITY;

	CView::OnPrepareDC(pDC, pInfo);
}
