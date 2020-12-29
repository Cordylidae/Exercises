#include"Complex.h"

complex::complex()
{
	real = 0;
	imaginary = 0;
}

complex::complex(double r, double i)
{
	real = r;
	imaginary = i;
}

complex::~complex()
{
}

complex complex::operator+(complex& a) const
{
	return complex(real + a.real, imaginary + a.imaginary);
}
complex complex::operator-(complex& a) const
{
	return complex(real - a.real, imaginary - a.imaginary);
}
complex complex::operator*(complex& a) const
{
	return complex(real * a.real - imaginary * a.imaginary, imaginary * a.real + real * a.imaginary);
}
complex complex::operator*(double n) const 
{ 
	return complex(real * n, imaginary * n); 
}

complex operator*(double n, const complex& b) 
{
	return b * n;
}

complex complex::operator~() const
{
	return complex(real, -imaginary);
}

std::istream& operator>>(std::istream& is,complex& a)
{
	std::cout << "real: ";
	is >> a.real;
	std::cout << "imaginary: ";
	is >> a.imaginary;
	return is;
}

std::ostream& operator<<(std::ostream& os,const complex& a)
{
	os <<"("<< a.real<<"," << a.imaginary<<"i)";
	return os;
}