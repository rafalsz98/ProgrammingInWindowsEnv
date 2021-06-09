#pragma once


// CWin2View view
#include "Sorts.h"
#include <vector>

#define MARGIN 50
#define LINES_DENSITY 20

#define RED			RGB(127,  0,  0)
#define GREEN		RGB(  0,127,  0)
#define BLUE		RGB(  0,  0,127)
#define LIGHTRED	RGB(255,  0,  0)
#define LIGHTGREEN	RGB(  0,255,  0)
#define LIGHTBLUE	RGB(  0,  0,255)
#define YELLOW		RGB(255,255,0)
#define BLACK		RGB(  0,  0,  0)
#define WHITE		RGB(255,255,255)
#define GRAY		RGB(192,192,192)

class CWin2View : public CView
{
	DECLARE_DYNCREATE(CWin2View)

protected:
	CWin2View();           // protected constructor used by dynamic creation
	virtual ~CWin2View();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

private:
	const std::vector<CString> m_sortsNames;
	const std::vector<CPen*> m_pens;
	const std::vector<CBrush*> m_brushes;
	std::vector<double> m_sortTimes;

	CFont* m_pTimesFont;
	Sorts* m_sorts;
	CRect* m_pClientRect;
	int m_nNameDistance;
	int m_nLineDistance;

	void DrawBackground(CDC* pDC);
	void DrawData(CDC* pDC);

public:
	afx_msg LRESULT OnShowInfo(WPARAM wParam, LPARAM lParam);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};


