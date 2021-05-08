
// SortingComparisonView.h : interface of the CSortingComparisonView class
//

#pragma once
#include "SortingDialog.h"
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

class CSortingComparisonView : public CView
{
protected: // create from serialization only
	CSortingComparisonView() noexcept;
	DECLARE_DYNCREATE(CSortingComparisonView)

// Attributes
public:
	CSortingComparisonDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSortingComparisonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSortShuffle();
	afx_msg void OnSortRun();
	afx_msg void OnSortSettings();

private:
	const std::vector<CString> m_sortsNames;
	const std::vector<CPen*> m_pens;
	const std::vector<CBrush*> m_brushes;
	std::vector<double> m_sortTimes;

	CSortingDialog m_sortingDialog;
	Sorts* m_sorts;
	CRect* m_pClientRect;
	int m_nNameDistance;
	int m_nLineDistance;
	BOOL m_bDrawData;

	void DrawBackground(CDC* pDC);
	void DrawData(CDC* pDC);



public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // debug version in SortingComparisonView.cpp
inline CSortingComparisonDoc* CSortingComparisonView::GetDocument() const
   { return reinterpret_cast<CSortingComparisonDoc*>(m_pDocument); }
#endif

