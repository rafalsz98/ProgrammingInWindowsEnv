// dllmain.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include <afxwin.h>
#include <afxdllx.h>

#include "Win2Dll.h"
#include "Win2ChildFrm.h"
#include "Win2Doc.h"
#include "Win2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "resource.h"

static AFX_EXTENSION_MODULE Win2DllDLL = { false, nullptr };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("Win2Dll.DLL Initializing!\n");

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(Win2DllDLL, hInstance))
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

		//new CDynLinkLibrary(Win2DllDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("Win2Dll.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(Win2DllDLL);
	}
	return 1;   // ok
}

extern "C" AFX_EXT_API CMultiDocTemplate* WINAPI InitWin2Dll()
{
	new CDynLinkLibrary(Win2DllDLL);

	CWinApp* pApp = AfxGetApp();
	ASSERT(pApp != NULL);

	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(WIN2_IDR_MAINFRAME,
		RUNTIME_CLASS(CWin2Doc),
		RUNTIME_CLASS(CWin2ChildFrm),
		RUNTIME_CLASS(CWin2View)
	);
	pApp->AddDocTemplate(pTemplate);
	return pTemplate;
}
