#pragma once

// CWin1Doc document

class CWin1Doc : public CDocument
{
	DECLARE_DYNCREATE(CWin1Doc)

public:
	CWin1Doc();
	virtual ~CWin1Doc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
