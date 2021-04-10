#pragma once
#include <atltypes.h>

class CBall : public CRect
{
public:
	CBall(
		int x1 = 0, 
		int y1 = 0, 
		int x2 = 0, 
		int y2 = 0,
		COLORREF ballColor = 0,
		int offsetX = 0,
		int offsetY = 0,
		CRect* boundRect = nullptr
	);
	CBall(
		CRect* spawnRect,
		COLORREF ballColor = 0,
		int offsetX = 0,
		int offsetY = 0,
		CRect* boundRect = nullptr
	);
	CBall(
		CPoint spawnPoint,
		CSize size,
		COLORREF ballColor = 0,
		int offsetX = 0,
		int offsetY = 0,
		CRect* boundRect = nullptr
	);
	~CBall();

	inline void SetBallColor(COLORREF color);
	inline void SetBallSize(CRect* size);
	void PaintBall(CDC* cdc);
	void SetBall(CRect* size, COLORREF color);
	void SetOffset(int x, int y);
	void SetBoundRect(CRect* boundRect);
	void Move();
	void SizeChanged();

private:
	inline void CreateObjects(COLORREF ballColor);
	inline void DeleteObjects();
	void InitObjects(COLORREF ballColor);

	CPen* m_pBallPen;
	CBrush* m_pBallBrush;
	CRect* m_pBoundRect;
	int m_offsetX;
	int m_offsetY;
	BOOL m_createdBoundRect;
	BOOL m_sizeChanged;
};

