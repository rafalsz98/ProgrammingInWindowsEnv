
// CalculatorView.h : interface of the CCalculatorView class
//

#pragma once


class CCalculatorView : public CView
{
protected: // create from serialization only
	CCalculatorView() noexcept;
	DECLARE_DYNCREATE(CCalculatorView)

// Attributes
public:
	CCalculatorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CCalculatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCalculatorDialog();
};

#ifndef _DEBUG  // debug version in CalculatorView.cpp
inline CCalculatorDoc* CCalculatorView::GetDocument() const
   { return reinterpret_cast<CCalculatorDoc*>(m_pDocument); }
#endif

