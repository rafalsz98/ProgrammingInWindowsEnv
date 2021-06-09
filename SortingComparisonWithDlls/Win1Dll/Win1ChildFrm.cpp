// Win1ChildFrm.cpp : implementation file
//

#include "pch.h"
#include "Win1Dll.h"
#include "Win1ChildFrm.h"
#include "resource.h"
#include "SortingDialog.h"


// CWin1ChildFrm

IMPLEMENT_DYNCREATE(CWin1ChildFrm, CMDIChildWnd)

CWin1ChildFrm::CWin1ChildFrm()
{
	m_pInfo = new (std::nothrow) Win2Info;
	ASSERT(m_pInfo);
}

CWin1ChildFrm::~CWin1ChildFrm()
{
	delete m_pInfo;
}


BEGIN_MESSAGE_MAP(CWin1ChildFrm, CMDIChildWnd)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_COMMAND(ID_SETTINGS, &CWin1ChildFrm::OnSettings)
END_MESSAGE_MAP()


// CWin1ChildFrm message handlers


BOOL CWin1ChildFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return CMDIChildWnd::PreCreateWindow(cs);
}


void CWin1ChildFrm::OnClose()
{
	CWnd* pWnd = AfxGetMainWnd();
	pWnd->SendMessageW(WIN1_CLOSE);

	CMDIChildWnd::OnClose();
}

int CWin1ChildFrm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if(CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
	return -1;

	if (!m_wndToolBar.CreateEx(this, 
		TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_WIN1_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	return 0;
}

//#define DATASIZE 10
//void CWin1ChildFrm::OnSendToWin2()
//{
//	m_pInfo->W2_pData = new (std::nothrow) int [DATASIZE];
//	ASSERT(m_pInfo->W2_pData);
//	m_pInfo->W2_nSize = DATASIZE;
//	srand( (unsigned) time (NULL));
//
//	for (int i = 0; i < DATASIZE; i++)
//		m_pInfo->W2_pData[i] = rand() % DATASIZE;
//
//	m_pInfo->W2_sName = CString("From Win1 DLL");
//
//	CFrameWnd* pFrameWnd = (CFrameWnd*) AfxGetMainWnd();
//	pFrameWnd->SendMessage(W2_ID_STARTWIN2, 0, (LPARAM) m_pInfo);
//}

void CWin1ChildFrm::OnSettings()
{
	SortingDialog dialog;
	if (dialog.DoModal() == IDOK)
	{
		m_pInfo->W2_bBubble = dialog.GetBubble();
		m_pInfo->W2_bHalfInsertion = dialog.GetHalfInsertion();
		m_pInfo->W2_bHeap = dialog.GetHeap();
		m_pInfo->W2_bInsertion = dialog.GetInsertion();
		m_pInfo->W2_bMixedBubble = dialog.GetMixedBubble();
		m_pInfo->W2_bQuick = dialog.GetQuick();
		m_pInfo->W2_bSelection = dialog.GetSelection();
		m_pInfo->W2_nSize = dialog.GetSize();

		CFrameWnd* pFrameWnd = (CFrameWnd*)AfxGetMainWnd();
		pFrameWnd->SendMessage(W2_ID_STARTWIN2, 0, (LPARAM)m_pInfo);
	}
}
