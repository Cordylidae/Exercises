#include<iostream>
#include"Move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showmove() const
{
	std::cout << "Coordinate x, y: " << x << ", " << y<<std::endl;
}
Move Move::add(const Move& m)
{
	x += m.x;
	y += m.y;

	return *this;
}

void Move::reset(double a, double b)
{
	*this = Move(a, b);
}