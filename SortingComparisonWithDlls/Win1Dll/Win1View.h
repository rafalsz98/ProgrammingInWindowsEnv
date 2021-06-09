#pragma once


// CWin1View view

class CWin1View : public CView
{
	DECLARE_DYNCREATE(CWin1View)

protected:
	CWin1View();           // protected constructor used by dynamic creation
	virtual ~CWin1View();

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

public:
	afx_msg void OnButton1();
};


