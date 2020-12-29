#include<iostream>
#include"Test.h"


void A::Draw() const
{
	std::cout << " Simple Day ";
}

void B::Draw() const
{
	A::Draw();
	std::cout << " & Amazing Night ";
}