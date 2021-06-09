// Win2View.cpp : implementation file
//

#include "pch.h"
#include "Win2View.h"
#include "resource.h"
#include "Defs.h"
#include <algorithm>


// CWin2View

IMPLEMENT_DYNCREATE(CWin2View, CView)

CWin2View::CWin2View()
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
	m_sorts = nullptr;
	m_sortTimes.resize(m_sortsNames.size());
	m_nLineDistance = 0;
	m_nNameDistance = 0;
	m_pTimesFont = new CFont();
	m_pTimesFont->CreatePointFont(100, L"Garamond");
}

CWin2View::~CWin2View()
{
	delete m_pClientRect;
	for (auto pen : m_pens) delete pen;
	for (auto brush : m_brushes) delete brush;
	if (m_sorts != nullptr) delete m_sorts;
	delete m_pTimesFont;
}

BEGIN_MESSAGE_MAP(CWin2View, CView)
	ON_MESSAGE(W2_ID_SHOWINFO, CWin2View::OnShowInfo)
END_MESSAGE_MAP()


// CWin2View drawing

void CWin2View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DrawBackground(pDC);
	DrawData(pDC);
}


// CWin2View diagnostics

#ifdef _DEBUG
void CWin2View::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWin2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


void CWin2View::DrawBackground(CDC* pDC)
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

void CWin2View::DrawData(CDC* pDC)
{
	double max = *std::max_element(m_sortTimes.begin(), m_sortTimes.end());
	if (fabs(max) < 1e-3) return;

	double step = max / LINES_DENSITY;
	double value = max;
	CFont* oldFont = pDC->SelectObject(m_pTimesFont);
	for (int i = 0; i < LINES_DENSITY; i++)
	{
		CString str;
		str.Format(L"%.3f", value);
		pDC->TextOutW(MARGIN - 40, MARGIN + i * m_nLineDistance - 5, str);
		value -= step;
	}
	pDC->SelectObject(oldFont);
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

// CWin2View message handlers
LRESULT CWin2View::OnShowInfo(WPARAM wParam, LPARAM lParam)
{
	LP_Win2Info pInfo = (LP_Win2Info)lParam;
	CString str;
	if (pInfo->W2_nSize <= 0) return FALSE;

	if (m_sorts != nullptr) delete m_sorts;
	m_sorts = new Sorts(pInfo->W2_nSize);
	std::fill(m_sortTimes.begin(), m_sortTimes.end(), 0);

	if (pInfo->W2_bBubble) m_sortTimes[0] = m_sorts->MeasureExecutionTime(SortMethod::Bubble);
	if (pInfo->W2_bHalfInsertion) m_sortTimes[1] = m_sorts->MeasureExecutionTime(SortMethod::HalfInsertion);
	if (pInfo->W2_bInsertion) m_sortTimes[2] = m_sorts->MeasureExecutionTime(SortMethod::Insertion);
	if (pInfo->W2_bMixedBubble) m_sortTimes[3] = m_sorts->MeasureExecutionTime(SortMethod::MixedBubble);
	if (pInfo->W2_bSelection) m_sortTimes[4] = m_sorts->MeasureExecutionTime(SortMethod::Selection);
	if (pInfo->W2_bQuick) m_sortTimes[5] = m_sorts->MeasureExecutionTime(SortMethod::Quick);
	if (pInfo->W2_bHeap) m_sortTimes[6] = m_sorts->MeasureExecutionTime(SortMethod::Heap);

	return TRUE;
}



void CWin2View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	GetClientRect(m_pClientRect);
	m_nNameDistance = (m_pClientRect->right - 2 * MARGIN) / m_sortsNames.size();
	m_nLineDistance = (m_pClientRect->bottom - 2 * MARGIN) / LINES_DENSITY;

	CView::OnPrepareDC(pDC, pInfo);
}
