#pragma once


// CWin2ChildFrm frame

class CWin2ChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CWin2ChildFrm)
protected:
	CWin2ChildFrm();           // protected constructor used by dynamic creation
	virtual ~CWin2ChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};


