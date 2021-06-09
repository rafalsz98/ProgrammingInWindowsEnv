#pragma once

#include "Defs.h"


// CWin1ChildFrm frame

class CWin1ChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CWin1ChildFrm)
protected:
	CWin1ChildFrm();           // protected constructor used by dynamic creation
	virtual ~CWin1ChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg void OnClose();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

protected:
	CToolBar m_wndToolBar;

public:
	tagWin2Info* m_pInfo;
	
	afx_msg void OnSettings();
};


