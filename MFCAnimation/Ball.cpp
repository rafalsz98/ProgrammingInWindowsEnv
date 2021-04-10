#include "pch.h"
#include "Ball.h"

CBall::CBall(int left, int top, int right, int bottom, COLORREF ballColor, int offsetX, int offsetY, CRect* boundRect)
	:	m_offsetX(offsetX),
		m_offsetY(offsetY),
		m_createdBoundRect(FALSE),
		m_sizeChanged(FALSE)
{
	InitObjects(ballColor);
	SetRect(left, top, right, bottom);
	SetBoundRect(boundRect);
}

CBall::CBall(CRect* spawnRect, COLORREF ballColor, int offsetX, int offsetY, CRect* boundRect)
	: CBall(
		spawnRect->left,
		spawnRect->top,
		spawnRect->right,
		spawnRect->bottom,
		ballColor,
		offsetX,
		offsetY,
		boundRect
	)
{}

CBall::CBall(CPoint spawnPoint, CSize size, COLORREF ballColor, int offsetX, int offsetY, CRect* boundRect)
	: CBall(
		spawnPoint.x,
		spawnPoint.y,
		spawnPoint.x + size.cx,
		spawnPoint.y + size.cy,
		ballColor,
		offsetX,
		offsetY,
		boundRect
	)
{}

CBall::~CBall()
{
	DeleteObjects();
	delete m_pBallPen;
	delete m_pBallBrush;
	if (m_createdBoundRect)
		delete m_pBoundRect;
}

inline void CBall::SetBallColor(COLORREF color)
{
	DeleteObjects();
	CreateObjects(color);
}

inline void CBall::SetBallSize(CRect* size)
{
	SetRect(size->TopLeft(), size->BottomRight());
}

void CBall::PaintBall(CDC* cdc)
{
	CPen* oldPen = cdc->SelectObject(m_pBallPen);
	CBrush* oldBrush = cdc->SelectObject(m_pBallBrush);

	cdc->Ellipse(this);

	cdc->SelectObject(oldPen);
	cdc->SelectObject(oldBrush);
}

void CBall::SetBall(CRect* size, COLORREF color)
{
	SetBallSize(size);
	SetBallColor(color);
}

void CBall::SetOffset(int x, int y)
{
	m_offsetX = x;
	m_offsetY = y;
}

void CBall::SetBoundRect(CRect* boundRect)
{
	if (m_createdBoundRect)
		delete m_pBoundRect;

	if (boundRect != nullptr)
	{
		m_pBoundRect = boundRect;
		m_createdBoundRect = FALSE;
	}
	else
	{
		m_pBoundRect = new CRect(0, 0, 0, 0);
		m_createdBoundRect = TRUE;
	}
}

void CBall::Move()
{
	if (m_sizeChanged)
	{
		if (this->right > m_pBoundRect->right)
			this->MoveToX(m_pBoundRect->right - this->Width() - 1);
		if (this->bottom > m_pBoundRect->bottom)
			this->MoveToY(m_pBoundRect->bottom - this->Height() - 1);
		m_sizeChanged = FALSE;
	}

	if (this->right > m_pBoundRect->right || this->left < m_pBoundRect->left)
		m_offsetX = -m_offsetX;
	if (this->top < m_pBoundRect->top || this->bottom > m_pBoundRect->bottom)
		m_offsetY = -m_offsetY;
	OffsetRect(m_offsetX, m_offsetY);
}

void CBall::SizeChanged()
{
	m_sizeChanged = TRUE;
}

inline void CBall::CreateObjects(COLORREF ballColor)
{
	m_pBallPen->CreatePen(PS_SOLID, 1, ballColor);
	m_pBallBrush->CreateSolidBrush(ballColor);
}

inline void CBall::DeleteObjects()
{
	m_pBallPen->DeleteObject();
	m_pBallBrush->DeleteObject();
}

void CBall::InitObjects(COLORREF ballColor)
{
	m_pBallPen = new CPen(PS_SOLID, 1, ballColor);
	m_pBallBrush = new CBrush(ballColor);
}
