
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "Anim.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

UINT CMainFrame::m_buttonsIDs[]
{
	ID_START_STOP,
	ID_PLUS,
	ID_MINUS,
	ID_APP_ABOUT
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmapW(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(m_buttonsIDs, sizeof(m_buttonsIDs) / sizeof(UINT))
		)
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
	CToolBarCtrl& BarCtrl = m_wndToolBar.GetToolBarCtrl();
	BarCtrl.SetBitmapSize(CSize(22, 22));
	BarCtrl.SetButtonSize(CSize(30, 30));

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	srand((unsigned int)time(NULL));

	return 0;
}

void CMainFrame::ChangeButton(BOOL state)
{
	if (state)
		m_wndToolBar.SetButtonInfo(0, ID_START_STOP, TBBS_BUTTON, 4);
	else
		m_wndToolBar.SetButtonInfo(0, ID_START_STOP, TBBS_BUTTON, 0);
	m_wndToolBar.Invalidate();
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

