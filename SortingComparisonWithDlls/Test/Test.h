
// Test.h : main header file for the Test application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTestApp:
// See Test.cpp for the implementation of this class
//

class CTestApp : public CWinApp
{
	CMultiDocTemplate* m_pWin1Template;
	CMultiDocTemplate* m_pWin2Template;

public:
	CTestApp() noexcept;

public:
	CMultiDocTemplate* getWin2Template() { return m_pWin2Template; }

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWin1();
	afx_msg void OnWin2();
};

extern CTestApp theApp;
