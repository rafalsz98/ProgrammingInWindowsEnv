// dllmain.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include <afxwin.h>
#include <afxdllx.h>

#include "Win1Dll.h"
#include "resource.h"
#include "Win1Doc.h"
#include "Win1View.h"
#include "Win1ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE Win1DllDLL = { false, nullptr };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("Win1Dll.DLL Initializing!\n");

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(Win1DllDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		//new CDynLinkLibrary(Win1DllDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("Win1Dll.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(Win1DllDLL);
	}
	return 1;   // ok
}

extern "C" CMultiDocTemplate* WINAPI InitWin1Dll()
{
	new CDynLinkLibrary(Win1DllDLL);

	CWinApp* pApp = AfxGetApp();
	ASSERT(pApp != NULL);

	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(WIN1_IDR_MAINFRAME,
		RUNTIME_CLASS(CWin1Doc),
		RUNTIME_CLASS(CWin1ChildFrm),
		RUNTIME_CLASS(CWin1View)
	);
	pApp->AddDocTemplate(pTemplate);
	return pTemplate;
}