// CalculatorDialog.cpp : implementation file
//

#include "pch.h"
#include "Calculator.h"
#include "CalculatorDialog.h"
#include "afxdialogex.h"
#include "Complex.h"


// CCalculatorDialog dialog

IMPLEMENT_DYNAMIC(CCalculatorDialog, CDialog)

CCalculatorDialog::CCalculatorDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CALCULATOR, pParent)
	, m_dIm1(0)
	, m_dIm2(0)
	, m_dRe1(0)
	, m_dRe2(0)
{

}

CCalculatorDialog::~CCalculatorDialog()
{
}

void CCalculatorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IM1, m_dIm1);
	DDX_Text(pDX, IDC_IM2, m_dIm2);
	DDX_Control(pDX, IDC_OPER, m_operations);
	DDX_Text(pDX, IDC_RE1, m_dRe1);
	DDX_Text(pDX, IDC_RE2, m_dRe2);
	DDX_Control(pDX, IDC_CALC_RES, m_results);
	DDX_Control(pDX, IDC_COUPLED1, m_coupled1);
	DDX_Control(pDX, IDC_COUPLED2, m_coupled2);
	DDX_Control(pDX, IDC_MODULE1, m_module1);
	DDX_Control(pDX, IDC_MODULE2, m_module2);
}


BEGIN_MESSAGE_MAP(CCalculatorDialog, CDialog)
	ON_BN_CLICKED(IDC_CALC_COUPLED, &CCalculatorDialog::OnBnClickedCalcCoupled)
	ON_BN_CLICKED(IDC_CALC, &CCalculatorDialog::OnBnClickedCalc)
END_MESSAGE_MAP()


// CCalculatorDialog message handlers


void CCalculatorDialog::OnBnClickedCalcOper()
{
	
}


void CCalculatorDialog::OnBnClickedCalcModule()
{
	UpdateData();

	CComplex c1{ m_dRe1, m_dIm1 };
	CComplex c2{ m_dRe2, m_dIm2 };


}


void CCalculatorDialog::OnBnClickedCalcCoupled()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorDialog::OnBnClickedCalc()
{
	UpdateData();

	CComplex c1{ m_dRe1, m_dIm1 };
	CComplex c2{ m_dRe2, m_dIm2 };

	CString str;
	str.Format(L"%.2f", c1.Module());
	m_module1.SetWindowTextW(str);
	str.Format(L"%.2f", c2.Module());
	m_module2.SetWindowTextW(str);

	CComplex c1Coupled = c1.Coupled();
	CComplex c2Coupled = c2.Coupled();

	char sign = c1Coupled.getIm() < 0 ? '-' : '+';
	str.Format(L"%.2f %c %.2f i", c1Coupled.getRe(), sign, fabs(c1Coupled.getIm()));
	m_coupled1.SetWindowTextW(str);
	sign = c2Coupled.getIm() < 0 ? '-' : '+';
	str.Format(L"%.2f %c %.2f i", c2Coupled.getRe(), sign, fabs(c2Coupled.getIm()));
	m_coupled2.SetWindowTextW(str);

	switch (m_operations.GetCurSel())
	{
	case 0:
		c1 -= c2;
		break;
	case 1:
		c1 *= c2;
		break;
	case 2:
		c1 /= c2;
		break;
	case 3:
		c1 += c2;
		break;
	default:
		c1.setComplex(0, 0);
		break;
	}

	sign = c1.getIm() < 0 ? '-' : '+';
	str.Format(L"%.2f %c %.2f i", c1.getRe(), sign, fabs(c1.getIm()));
	m_results.SetWindowTextW(str);
}
