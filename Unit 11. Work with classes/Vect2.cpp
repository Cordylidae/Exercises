#include"Vect2.h"

namespace VECTOR2 {

	const double Rag_to_deg = 45.0 / atan(1.0);

	void Vector::set_x(double n1, double n2) { x = n1 * std::cos(n2 / Rag_to_deg); }
	void Vector::set_y(double n1, double n2) { y = n1 * std::sin(n2 / Rag_to_deg); }

	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else
		{
			std::cout << "Incorrect 3rd argument to Vector() -- ";
			std::cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else
		{
			std::cout << "Incorrect 3rd argument to Vector() -- ";
			std::cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector() {}

	void Vector::polar_mode() { mode = POL; }
	void Vector::rect_mode() { mode = RECT; }


	Vector Vector::operator+(const Vector& b)const { return Vector(x + b.x, y + b.y); }
	Vector Vector::operator-(const Vector& b)const { return Vector(x - b.x, y - b.y); }
	Vector Vector::operator-()const { return Vector(-x, -y); }
	Vector Vector::operator~()const { return Vector(x, -y); }
	Vector Vector::operator*(double n)const { return Vector(n * x, n * y); }

	Vector operator*(double n, const Vector& a) { return a * n; }
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << " (x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			
			os << " (m,a) = (" << v.magval() <<  ", " << v.angval() * Rag_to_deg << ")";
		}
		else os << "Vector object mode is invalid";
		return os;
	}
	std::ofstream& operator<<(std::ofstream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << " (x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << " (m,a) = (" << v.magval() << ", " << v.angval() * Rag_to_deg << ")";
		}
		else os << "Vector object mode is invalid";
		return os;
	}
}