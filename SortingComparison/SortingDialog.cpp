// SortingDialog.cpp : implementation file
//

#include "pch.h"
#include "SortingComparison.h"
#include "SortingDialog.h"
#include "afxdialogex.h"

// CSortingDialog dialog

IMPLEMENT_DYNAMIC(CSortingDialog, CDialog)

CSortingDialog::CSortingDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SORTING_DIALOG, pParent)
	, m_bBubble(FALSE)
	, m_bHalfInsertion(FALSE)
	, m_bHeap(FALSE)
	, m_bInsertion(FALSE)
	, m_bMixedBubble(FALSE)
	, m_bQuick(FALSE)
	, m_bSelection(FALSE)
	, m_nSize(0)
{

}

CSortingDialog::~CSortingDialog()
{
}

BOOL CSortingDialog::IsBubble()
{
	return m_bBubble;
}

BOOL CSortingDialog::IsHalfInsertion()
{
	return m_bHalfInsertion;
}

BOOL CSortingDialog::IsHeap()
{
	return m_bHeap;
}

BOOL CSortingDialog::IsInsertion()
{
	return m_bInsertion;
}

BOOL CSortingDialog::IsMixedBubble()
{
	return m_bMixedBubble;
}

BOOL CSortingDialog::IsQuick()
{
	return m_bQuick;
}

BOOL CSortingDialog::IsSelection()
{
	return m_bSelection;
}

int CSortingDialog::GetSize()
{
	return m_nSize;
}

void CSortingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_BUBBLE, m_bBubble);
	DDX_Check(pDX, IDC_HALFINSERTION, m_bHalfInsertion);
	DDX_Check(pDX, IDC_HEAP, m_bHeap);
	DDX_Check(pDX, IDC_INSERTION, m_bInsertion);
	DDX_Check(pDX, IDC_MIXEDBUBBLE, m_bMixedBubble);
	DDX_Check(pDX, IDC_QUICK, m_bQuick);
	DDX_Check(pDX, IDC_SELECTION, m_bSelection);
	DDX_Text(pDX, IDC_ARRAY_SIZE, m_nSize);
}


BEGIN_MESSAGE_MAP(CSortingDialog, CDialog)
	ON_BN_CLICKED(IDC_ALL, &CSortingDialog::OnBnClickedAll)
	ON_BN_CLICKED(IDOK, &CSortingDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_NONE, &CSortingDialog::OnBnClickedNone)
END_MESSAGE_MAP()


// CSortingDialog message handlers


void CSortingDialog::OnBnClickedAll()
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
		((CButton*)GetDlgItem(checkbox))->SetCheck(1);
}


void CSortingDialog::OnBnClickedOk()
{
	CDialog::OnOK();
}


void CSortingDialog::OnBnClickedNone()
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
