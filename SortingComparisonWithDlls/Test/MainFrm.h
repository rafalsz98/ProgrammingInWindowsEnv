
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)

public:
	CMainFrame() noexcept;

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnWin1();
	afx_msg void OnWin2();
	afx_msg LRESULT OnWin1Close(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWin2Close(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStartWin2(WPARAM wParam, LPARAM lParam);

private:
	BOOL m_bStartWin1;
	BOOL m_bStartWin2;
};


