#pragma once


// CCalculatorDialog dialog

class CCalculatorDialog : public CDialog
{
	DECLARE_DYNAMIC(CCalculatorDialog)

public:
	CCalculatorDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCalculatorDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	double m_dIm1;
	double m_dIm2;
	CComboBox m_operations;
	double m_dRe1;
	double m_dRe2;
public:
	afx_msg void OnBnClickedCalcOper();
	CStatic m_results;
	afx_msg void OnBnClickedCalcModule();
	afx_msg void OnBnClickedCalcCoupled();
private:
	CStatic m_coupled1;
	CStatic m_coupled2;
	CStatic m_module1;
	CStatic m_module2;
public:
	afx_msg void OnBnClickedCalc();
};
