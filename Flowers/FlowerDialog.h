#pragma once


// CFlowerDialog dialog

#define TULIPAN_PRICE 4
#define ROZA_PRICE 3
#define FREZJA_PRICE 2

#define FOLIA_PRICE 2
#define PAPIER_PRICE 1

class CFlowerDialog : public CDialog
{
	DECLARE_DYNAMIC(CFlowerDialog)

public:
	CFlowerDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFlowerDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	int m_nTulipanCount;
	int m_nRozeCount;
	int m_nFrezjaCount;
	int m_nPackageKind;
	int m_nRabat;
public:
	afx_msg void OnBnClickedCalculate();
};
