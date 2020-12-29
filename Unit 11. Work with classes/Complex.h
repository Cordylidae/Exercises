#ifndef  MYCOMPLEX_H_
#define  MYCOMPLEX_H_

#include<iostream>

class complex
{
private:
	double real;
	double imaginary;
public:
	complex();
	complex(double, double);
	~complex();

	complex operator+(complex& a) const;
	complex operator-(complex& a) const;
	complex operator*(complex& a) const;
	complex operator*(double n) const;
	complex operator~()const;

	friend complex operator*(double n, const complex& b);
	friend std::istream& operator>>(std::istream& is,complex& a);
	friend std::ostream& operator<<(std::ostream& os,const complex& a);
};

#endif // ! MYCOMPLEX_H_
