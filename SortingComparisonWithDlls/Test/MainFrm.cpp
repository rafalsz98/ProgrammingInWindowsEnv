
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "Test.h"

#include "MainFrm.h"
#include "Win1Dll.h"
#include "Win2Dll.h"
#include "Defs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_WIN1, &CMainFrame::OnWin1)
	ON_COMMAND(ID_WIN2, &CMainFrame::OnWin2)
	ON_MESSAGE(WIN1_CLOSE, CMainFrame::OnWin1Close)
	ON_MESSAGE(WIN2_CLOSE, CMainFrame::OnWin2Close)
	ON_MESSAGE(W2_ID_STARTWIN2, CMainFrame::OnStartWin2)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
	m_bStartWin1 = FALSE;
	m_bStartWin2 = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, 
		TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnWin1()
{
	if (!m_bStartWin1)
	{
		m_bStartWin1 = TRUE;
		((CTestApp*)AfxGetApp())->OnWin1();

		CMDIChildWnd* pChild = ((CMDIFrameWnd*)AfxGetMainWnd())->MDIGetActive();
		CView* pViewWnd = pChild->GetActiveView();
		ASSERT(pViewWnd);
	}
}

LRESULT CMainFrame::OnWin1Close(WPARAM wParam, LPARAM lParam)
{
	m_bStartWin1 = FALSE;
	return TRUE;
}


void CMainFrame::OnWin2()
{
	if (!m_bStartWin2)
	{
		m_bStartWin2 = TRUE;
		((CTestApp*)AfxGetApp())->OnWin2();

		CMDIChildWnd* pChild = ((CMDIFrameWnd*)AfxGetMainWnd())->MDIGetActive();
		CView* pViewWnd = pChild->GetActiveView();
		ASSERT(pViewWnd);
	}
}

LRESULT CMainFrame::OnWin2Close(WPARAM wParam, LPARAM lParam)
{
	m_bStartWin2 = FALSE;
	return TRUE;
}

LRESULT CMainFrame::OnStartWin2(WPARAM wParam, LPARAM lParam)
{
	CView* pViewWnd = NULL;
	if (!m_bStartWin2)
	{
		OnWin2();
		CMDIChildWnd* pChild = ((CMDIFrameWnd*) AfxGetMainWnd())->MDIGetActive();
		pViewWnd = pChild->GetActiveView();
		ASSERT(pViewWnd);
	}
	else
	{
		CDocTemplate* pCDocTemp = (CDocTemplate*)((CTestApp*)AfxGetApp())->getWin2Template();
		POSITION pos = pCDocTemp->GetFirstDocPosition();
		CDocument* pCDoc = pCDocTemp->GetNextDoc(pos);

		pos = pCDoc->GetFirstViewPosition();
		pViewWnd = pCDoc->GetNextView(pos);
		ASSERT(pViewWnd);

		CMDIFrameWnd* pFrame = (CMDIFrameWnd*)pViewWnd->GetParentFrame();
		((CMDIFrameWnd*)this)->MDIActivate(pFrame);
		pViewWnd->PostMessage(W2_ID_SHOWINFO, 0, lParam);

		return TRUE;
	}
}