// Win2ChildFrm.cpp : implementation file
//

#include "pch.h"
#include "Win2Dll.h"
#include "Win2ChildFrm.h"
#include "Defs.h"


// CWin2ChildFrm

IMPLEMENT_DYNCREATE(CWin2ChildFrm, CMDIChildWnd)

CWin2ChildFrm::CWin2ChildFrm()
{

}

CWin2ChildFrm::~CWin2ChildFrm()
{
}


BEGIN_MESSAGE_MAP(CWin2ChildFrm, CMDIChildWnd)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CWin2ChildFrm message handlers


void CWin2ChildFrm::OnClose()
{
	CWnd* pWnd = AfxGetMainWnd();
	pWnd->SendMessageW(WIN2_CLOSE);

	CMDIChildWnd::OnClose();
}
