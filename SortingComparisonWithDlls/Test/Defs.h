#pragma once

#include <atlstr.h>  // CString


typedef struct tagWin2Info
{
	BOOL W2_bBubble;
	BOOL W2_bHalfInsertion;
	BOOL W2_bHeap;
	BOOL W2_bInsertion;
	BOOL W2_bMixedBubble;
	BOOL W2_bQuick;
	BOOL W2_bSelection;
	int W2_nSize;

	tagWin2Info() 
	{ 
		W2_bBubble = FALSE;
		W2_bHalfInsertion = FALSE;
		W2_bHeap = FALSE;
		W2_bInsertion = FALSE;
		W2_bMixedBubble = FALSE;
		W2_bQuick = FALSE;
		W2_bSelection = FALSE;
		W2_nSize = 0;
	}
} Win2Info, *LP_Win2Info;


// messages
#define W2_ID_STARTWIN2 21000		// win2dll starts resources with 20000
#define W2_ID_SHOWINFO  21001
#define WIN2_CLOSE      21002

#define WIN1_CLOSE		15000		// win1dll starts resources with 10000