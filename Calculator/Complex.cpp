#include "pch.h"
#include "Complex.h"
#include <exception>

#define EPS 1e-5

CComplex::CComplex(double re, double im)
{
	m_dRe = re;
	m_dIm = im;
}

CComplex::CComplex(const CComplex& c)
{
	*this = c;
}

CComplex& CComplex::operator+=(const CComplex& rhs)
{
	this->m_dRe += rhs.m_dRe;
	this->m_dIm += rhs.m_dIm;
	return *this;
}

CComplex& CComplex::operator-=(const CComplex& rhs)
{
	this->m_dRe -= rhs.m_dRe;
	this->m_dIm -= rhs.m_dIm;
	return *this;
}

CComplex& CComplex::operator*=(const CComplex& rhs)
{
	this->m_dRe *= rhs.m_dRe;
	this->m_dIm *= rhs.m_dIm;
	return *this;
}

CComplex& CComplex::operator/=(const CComplex& rhs)
{
	double denominator = (rhs.m_dRe * rhs.m_dRe) + (rhs.m_dIm * rhs.m_dIm);
	if (fabs(denominator) <= EPS)
	{
		AfxMessageBox(L"Division by zero!");
		return *this;
	}

	this->m_dRe = (this->m_dRe * this->m_dRe) + (this->m_dIm * this->m_dIm);
	this->m_dIm = (this->m_dIm * this->m_dRe) + (this->m_dRe * this->m_dIm);

	this->m_dRe = this->m_dRe / denominator;
	this->m_dIm = this->m_dIm / denominator;

	return *this;
}

CComplex& CComplex::operator- ()
{
	this->m_dRe -= this->m_dRe;
	this->m_dIm -= this->m_dIm;
	return *this;
}

CComplex& CComplex::operator=(const CComplex& rhs)
{
	if (&rhs != this)
	{
		this->m_dRe = rhs.m_dRe;
		this->m_dIm = rhs.m_dIm;
	}

	return *this;
}

double CComplex::Module()
{
	return sqrt(this->m_dRe * this->m_dRe + this->m_dIm * this->m_dIm);
}

CComplex CComplex::Coupled()
{
	return CComplex(this->m_dRe, -this->m_dIm);
}

const CComplex operator- (const CComplex& c1, const CComplex& c2)
{
	CComplex left(c1);
	return left -= c2;
}

const CComplex operator+ (const CComplex& c1, const CComplex& c2)
{
	CComplex left(c1);
	return left += c2;
}

const CComplex operator* (const CComplex& c1, const CComplex& c2)
{
	CComplex left(c1);
	return left *= c2;
}

const CComplex operator/ (const CComplex& c1, const CComplex& c2)
{
	if (fabs(c2.m_dRe * c2.m_dRe + c2.m_dIm * c2.m_dIm) <= EPS)
	{
		AfxMessageBox(L"Division by zero!");
		return CComplex(0, 0);
	}

	CComplex left(c1);
	return left /= c2;
}

std::ostream& operator<< (std::ostream& o, const CComplex& c)
{
	o << "( " << c.m_dRe << ", " << c.m_dIm << " )";
	return o;
}

std::istream& operator>> (std::istream& i, CComplex& c)
{
	i >> c.m_dRe >> c.m_dIm;
	return i;
}

bool operator== (const CComplex c1, const CComplex c2)
{
	return c1.m_dRe == c2.m_dRe && c1.m_dIm == c2.m_dIm;
}

bool operator!= (const CComplex c1, const CComplex c2)
{
	return !(c1 == c2);
}




