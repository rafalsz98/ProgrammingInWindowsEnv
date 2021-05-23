#pragma once

#include <iostream>


class CComplex
{
	double m_dRe;
	double m_dIm;

public:
	CComplex(double re, double im = 0);
	CComplex(const CComplex& c);

	CComplex& operator+=(const CComplex& rhs);
	CComplex& operator-=(const CComplex& rhs);
	CComplex& operator*=(const CComplex& rhs);
	CComplex& operator/=(const CComplex& rhs);
	CComplex& operator- ();
	CComplex& operator=(const CComplex& rhs);

	inline void setRe(double re) { m_dRe = re; }
	inline void setIm(double im) { m_dIm = im; }
	inline void setComplex(double re, double im) { setRe(re); setIm(im); }
	inline double getRe() { return m_dRe; }
	inline double getIm() { return m_dIm; }

	double Module();
	CComplex Coupled();

	friend const CComplex operator- (const CComplex& c1, const CComplex& c2);
	friend const CComplex operator+ (const CComplex& c1, const CComplex& c2);
	friend const CComplex operator* (const CComplex& c1, const CComplex& c2);
	friend const CComplex operator/ (const CComplex& c1, const CComplex& c2);
	friend std::ostream& operator<< (std::ostream& o, const CComplex& c);
	friend std::istream& operator>> (std::istream& i, CComplex& c);
	friend bool operator== (const CComplex c1, const CComplex c2);
	friend bool operator!= (const CComplex c1, const CComplex c2);
};

