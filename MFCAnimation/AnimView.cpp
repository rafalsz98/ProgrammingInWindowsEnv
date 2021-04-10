
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
#include "MainFrm.h"

// CAnimView

IMPLEMENT_DYNCREATE(CAnimView, CView)

BEGIN_MESSAGE_MAP(CAnimView, CView)
	ON_COMMAND(ID_START_STOP, &CAnimView::OnStartStop)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_PLUS, &CAnimView::OnPlus)
	ON_COMMAND(ID_MINUS, &CAnimView::OnMinus)
	ON_UPDATE_COMMAND_UI(ID_PLUS, &CAnimView::OnUpdatePlus)
	ON_UPDATE_COMMAND_UI(ID_MINUS, &CAnimView::OnUpdateMinus)
	ON_WM_SIZE()
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
	m_bStart = FALSE;
	m_pClientRect = new CRect(0, 0, 0, 0);
	m_numberOfBalls = 1;
	m_nTimerID = NULL;
	m_ballsArray[m_numberOfBalls - 1] = generateRandomBall();
}

CAnimView::~CAnimView()
{
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

	for (int i = 0; i < m_numberOfBalls; i++)
	{
		m_ballsArray[i]->PaintBall(&memDC);
	}

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
	((CMainFrame*)GetParentFrame())->ChangeButton(m_bStart);
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

CBall* CAnimView::generateRandomBall()
{
	int R = rand() % 255;
	int G = rand() % 255;
	int B = rand() % 255;
	int size = rand() % (MAX_BALL_SIZE - MIN_BALL_SIZE) + MIN_BALL_SIZE;
	int movementX = rand() % (MAX_BALL_MOVE - MIN_BALL_MOVE) + MIN_BALL_MOVE;
	int movementY = rand() % (MAX_BALL_MOVE - MIN_BALL_MOVE) + MIN_BALL_MOVE;
	COLORREF color = RGB(R, G, B);
	return new CBall({ 0, 0 }, { size, size }, color, movementX, movementY, m_pClientRect);
}


void CAnimView::OnTimer(UINT_PTR nIDEvent)
{
	if (m_bStart)
	{
		for (int i = 0; i < m_numberOfBalls; i++)
			m_ballsArray[i]->Move();
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}


BOOL CAnimView::OnEraseBkgnd(CDC* pDC)
{
	return 1;
}


void CAnimView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	GetClientRect(m_pClientRect);

	CView::OnPrepareDC(pDC, pInfo);
}


void CAnimView::OnPlus()
{
	if (m_numberOfBalls < MAX_BALLS)
	{
		m_ballsArray[m_numberOfBalls] = generateRandomBall();
		m_numberOfBalls++;
		Invalidate();
	}
}


void CAnimView::OnMinus()
{
	if (m_numberOfBalls > 1)
	{
		m_numberOfBalls--;
		delete m_ballsArray[m_numberOfBalls];
		Invalidate();
	}
}


void CAnimView::OnUpdatePlus(CCmdUI* pCmdUI)
{
	bool enabled = m_numberOfBalls == MAX_BALLS ? false : true;
	pCmdUI->Enable(enabled);
}


void CAnimView::OnUpdateMinus(CCmdUI* pCmdUI)
{
	bool enabled = m_numberOfBalls == 1 ? false : true;
	pCmdUI->Enable(enabled);
}


void CAnimView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	for (int i = 0; i < m_numberOfBalls; i++)
		m_ballsArray[i]->SizeChanged();
	// TODO: Add your message handler code here

}
