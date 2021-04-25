
// FlowersView.h : interface of the CFlowersView class
//

#pragma once


class CFlowersView : public CView
{
protected: // create from serialization only
	CFlowersView() noexcept;
	DECLARE_DYNCREATE(CFlowersView)

// Attributes
public:
	CFlowersDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CFlowersView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKwiaciarniaDialog();
};

#ifndef _DEBUG  // debug version in FlowersView.cpp
inline CFlowersDoc* CFlowersView::GetDocument() const
   { return reinterpret_cast<CFlowersDoc*>(m_pDocument); }
#endif

