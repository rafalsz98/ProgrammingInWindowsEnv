#pragma once

// CWin2Doc document

class CWin2Doc : public CDocument
{
	DECLARE_DYNCREATE(CWin2Doc)

public:
	CWin2Doc();
	virtual ~CWin2Doc();
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
