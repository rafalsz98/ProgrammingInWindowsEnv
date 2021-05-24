#include "pch.h"
#include "CanonComplex.h"

CCanonComplex::CCanonComplex(const CComplex& complex) 
	: CComplex(complex)
{
}

std::ostream& operator<< (std::ostream& o, const CComplex& c)
{
	o << c.m_dRe << ", " << c.m_dIm;
	return o;
}

std::istream& operator>> (std::istream& i, CComplex& c)
{
	i >> c.m_dRe >> c.m_dIm;
	return i;
}