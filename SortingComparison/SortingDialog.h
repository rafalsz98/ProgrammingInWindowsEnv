#pragma once


// CSortingDialog dialog

class CSortingDialog : public CDialog
{
	DECLARE_DYNAMIC(CSortingDialog)

public:
	CSortingDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSortingDialog();

	BOOL IsBubble();
	BOOL IsHalfInsertion();
	BOOL IsHeap();
	BOOL IsInsertion();
	BOOL IsMixedBubble();
	BOOL IsQuick();
	BOOL IsSelection();
	int GetSize();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SORTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


private:
	BOOL m_bBubble;
	BOOL m_bHalfInsertion;
	BOOL m_bHeap;
	BOOL m_bInsertion;
	BOOL m_bMixedBubble;
	BOOL m_bQuick;
	BOOL m_bSelection;
	int m_nSize;
public:
	afx_msg void OnBnClickedAll();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedNone();
};
