#pragma once

#include "Defs.h"
// SortingDialog dialog

class SortingDialog : public CDialog
{
	DECLARE_DYNAMIC(SortingDialog)

public:
	SortingDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SortingDialog();

	inline int GetSize() { return m_nSize; }
	inline bool GetBubble() { return m_bBubble; }
	inline bool GetHalfInsertion() { return m_bHalfInsertion; }
	inline bool GetHeap() { return m_bHeap; }
	inline bool GetInsertion() { return m_bInsertion; }
	inline bool GetMixedBubble() { return m_bMixedBubble; }
	inline bool GetQuick() { return m_bQuick; }
	inline bool GetSelection() { return m_bSelection; }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SORTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:

	int m_nSize;
	BOOL m_bBubble;
	BOOL m_bHalfInsertion;
	BOOL m_bHeap;
	BOOL m_bInsertion;
	BOOL m_bMixedBubble;
	BOOL m_bQuick;
	BOOL m_bSelection;
public:
	afx_msg void OnBnClickedNlognAll();
	afx_msg void OnBnClickedN2All();
	afx_msg void OnBnClickedNone();
};
