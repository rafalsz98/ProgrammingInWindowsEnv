
// AnimView.cpp : implementation of the CAnimView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Anim.h"
#endif

#include "AnimDoc.h"
#include "AnimView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BALLSIZE 60
#define BLUE RGB(0, 0, 255)

// CAnimView

IMPLEMENT_DYNCREATE(CAnimView, CView)

BEGIN_MESSAGE_MAP(CAnimView, CView)
	ON_COMMAND(ID_START_STOP, &CAnimView::OnStartStop)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CALLBACK ZfxTimerProc(
	HWND hWnd,
	UINT nMsg,
	UINT nIDEvent,
	DWORD dwTime
)
{
	::SendMessage(hWnd, WM_TIMER, 0, 0);
}



// CAnimView construction/destruction

CAnimView::CAnimView() noexcept
{
	m_pBall = new CRect(20, 20, 20 + BALLSIZE, 20 + BALLSIZE);
	m_pBallPen = new CPen(PS_SOLID, 1, BLUE);
	m_pBallBrush = new CBrush(BLUE);
	m_nBallOffX = 3;
	m_nBallOffY = 1;
	m_bStart = FALSE;
	m_pClientRect = new CRect(0, 0, 0, 0);
}

CAnimView::~CAnimView()
{
	delete m_pBall;
	delete m_pBallPen;
	delete m_pBallBrush;
	delete m_pClientRect;
}

BOOL CAnimView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAnimView drawing

void CAnimView::OnDraw(CDC* pDC)
{
	CAnimDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC memDC;
	BOOL b = memDC.CreateCompatibleDC(pDC);
	ASSERT(b);

	CBitmap bmp;
	b = bmp.CreateCompatibleBitmap(pDC, m_pClientRect->Width(), m_pClientRect->Height());
	ASSERT(b);
	CBitmap* pOldBitmap = memDC.SelectObject(&bmp);
	memDC.FillSolidRect(m_pClientRect, RGB(230, 230, 200));

	CPen* pOldPen = memDC.SelectObject(m_pBallPen);
	CBrush* pOldBrush = memDC.SelectObject(m_pBallBrush);

	memDC.Ellipse(m_pBall);

	memDC.SelectObject(pOldPen);
	memDC.SelectObject(pOldBrush);

	b = pDC->BitBlt(0, 0, m_pClientRect->Width(), m_pClientRect->Height(), &memDC, 0, 0, SRCCOPY);
	ASSERT(b);

	memDC.SelectObject(pOldBitmap);
	bmp.DeleteObject();
	memDC.DeleteDC();
}


// CAnimView diagnostics

#ifdef _DEBUG
void CAnimView::AssertValid() const
{
	CView::AssertValid();
}

void CAnimView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnimDoc* CAnimView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnimDoc)));
	return (CAnimDoc*)m_pDocument;
}
#endif //_DEBUG


// CAnimView message handlers


void CAnimView::OnStartStop()
{
	m_bStart = !m_bStart;
}


void CAnimView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_nTimerID = SetTimer(WM_USER + 1, 20, ZfxTimerProc);
}


void CAnimView::OnDestroy()
{
	CView::OnDestroy();

	KillTimer(m_nTimerID);
}


void CAnimView::OnTimer(UINT_PTR nIDEvent)
{
	if (m_bStart)
	{
		m_pBall->OffsetRect(m_nBallOffX, m_nBallOffY);
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}


BOOL CAnimView::OnEraseBkgnd(CDC* pDC)
{
	return 1;
	//return CView::OnEraseBkgnd(pDC);
}


void CAnimView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	GetClientRect(m_pClientRect);

	CView::OnPrepareDC(pDC, pInfo);
}
