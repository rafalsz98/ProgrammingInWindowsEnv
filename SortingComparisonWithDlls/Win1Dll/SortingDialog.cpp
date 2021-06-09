// SortingDialog.cpp : implementation file
//

#include "pch.h"
#include "Win1Dll.h"
#include "SortingDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// SortingDialog dialog

IMPLEMENT_DYNAMIC(SortingDialog, CDialog)

SortingDialog::SortingDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SORTING_DIALOG, pParent)
	, m_nSize(0)
	, m_bBubble(FALSE)
	, m_bHalfInsertion(FALSE)
	, m_bHeap(FALSE)
	, m_bInsertion(FALSE)
	, m_bMixedBubble(FALSE)
	, m_bQuick(FALSE)
	, m_bSelection(FALSE)
{

}

SortingDialog::~SortingDialog()
{
}

void SortingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ARRAYSIZE, m_nSize);
	DDX_Check(pDX, IDC_BUBBLE, m_bBubble);
	DDX_Check(pDX, IDC_HALFINSERTION, m_bHalfInsertion);
	DDX_Check(pDX, IDC_HEAP, m_bHeap);
	DDX_Check(pDX, IDC_INSERTION, m_bInsertion);
	DDX_Check(pDX, IDC_MIXEDBUBBLE, m_bMixedBubble);
	DDX_Check(pDX, IDC_QUICK, m_bQuick);
	DDX_Check(pDX, IDC_SELECTION, m_bSelection);
}


BEGIN_MESSAGE_MAP(SortingDialog, CDialog)
	ON_BN_CLICKED(IDC_NLOGN_ALL, &SortingDialog::OnBnClickedNlognAll)
	ON_BN_CLICKED(IDC_N2_ALL, &SortingDialog::OnBnClickedN2All)
	ON_BN_CLICKED(IDC_NONE, &SortingDialog::OnBnClickedNone)
END_MESSAGE_MAP()


// SortingDialog message handlers


void SortingDialog::OnBnClickedNlognAll()
{
	const int checkboxes[] = {
		IDC_HEAP,
		IDC_QUICK,
	};

	for (auto checkbox : checkboxes)
		((CButton*)GetDlgItem(checkbox))->SetCheck(1);
}


void SortingDialog::OnBnClickedN2All()
{
	const int checkboxes[] = {
		IDC_BUBBLE,
		IDC_HALFINSERTION,
		IDC_INSERTION,
		IDC_MIXEDBUBBLE,
		IDC_SELECTION
	};

	for (auto checkbox : checkboxes)
		((CButton*)GetDlgItem(checkbox))->SetCheck(1);
}


void SortingDialog::OnBnClickedNone()
{
	const int checkboxes[] = {
		IDC_BUBBLE,
		IDC_HALFINSERTION,
		IDC_HEAP,
		IDC_INSERTION,
		IDC_MIXEDBUBBLE,
		IDC_QUICK,
		IDC_SELECTION
	};

	for (auto checkbox : checkboxes)
		((CButton*)GetDlgItem(checkbox))->SetCheck(0);
}
