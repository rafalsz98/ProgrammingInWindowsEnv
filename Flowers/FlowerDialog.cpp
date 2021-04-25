// FlowerDialog.cpp : implementation file
//

#include "pch.h"
#include "Flowers.h"
#include "FlowerDialog.h"
#include "afxdialogex.h"


// CFlowerDialog dialog

IMPLEMENT_DYNAMIC(CFlowerDialog, CDialog)

CFlowerDialog::CFlowerDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG, pParent)
	, m_nTulipanCount(0)
	, m_nRozeCount(0)
	, m_nFrezjaCount(0)
	, m_nPackageKind(0)
	, m_nRabat(0)
{

}

CFlowerDialog::~CFlowerDialog()
{
}

void CFlowerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TULIPAN_COUNT, m_nTulipanCount);
	DDX_Text(pDX, IDC_ROZE_COUNT, m_nRozeCount);
	DDX_Text(pDX, IDC_FREZJA_COUNT, m_nFrezjaCount);
	DDX_Radio(pDX, IDC_RODZAJ_FOLIA, m_nPackageKind);
	DDX_Text(pDX, IDC_RABAT, m_nRabat);
}


BEGIN_MESSAGE_MAP(CFlowerDialog, CDialog)
	ON_BN_CLICKED(IDC_CALCULATE, &CFlowerDialog::OnBnClickedCalculate)
END_MESSAGE_MAP()


// CFlowerDialog message handlers


void CFlowerDialog::OnBnClickedCalculate()
{
	UpdateData();
	double price = 0;
	price =
		(double)m_nTulipanCount * TULIPAN_PRICE +
		(double)m_nRozeCount * ROZA_PRICE +
		(double)m_nFrezjaCount * FREZJA_PRICE;
	if (m_nPackageKind == 0) price += FOLIA_PRICE;
	else if (m_nPackageKind == 1) price += PAPIER_PRICE;

	if (m_nRabat != 0) price *= (1.0 - (m_nRabat / 100.0));

	CString str;
	str.Format(L"%.2f zl", price);

	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	pWnd->SetWindowTextW(str);
}
