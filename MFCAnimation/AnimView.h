
// AnimView.h : interface of the CAnimView class
//

#pragma once
#include "Ball.h"

#define MAX_BALLS 10
#define MIN_BALL_SIZE 30
#define MAX_BALL_SIZE 100
#define MIN_BALL_MOVE 1
#define MAX_BALL_MOVE 8


class CAnimView : public CView
{
protected: // create from serialization only
	CAnimView() noexcept;
	DECLARE_DYNCREATE(CAnimView)

// Attributes
public:
	CAnimDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CAnimView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStartStop();
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();

private:
	CBall* generateRandomBall();

	BOOL m_bStart;
	UINT_PTR m_nTimerID;
	CRect* m_pClientRect;
	int m_numberOfBalls;
	CBall* m_ballsArray[MAX_BALLS];

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	afx_msg void OnPlus();
	afx_msg void OnMinus();
	afx_msg void OnUpdatePlus(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMinus(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in AnimView.cpp
inline CAnimDoc* CAnimView::GetDocument() const
   { return reinterpret_cast<CAnimDoc*>(m_pDocument); }
#endif

