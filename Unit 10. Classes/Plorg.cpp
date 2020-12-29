#include"Plorg.h"
#include<iostream>


Plorg::Plorg(const char* name_, int ci)
{
	name = (char*)name_;
	CI = ci;
}
Plorg::~Plorg()
{
	//std::cout << "Delete name: " << name <<  std::endl;
}
void Plorg::swapCI(int ci)
{
	CI = ci;
}
void Plorg::showPlorg() const
{
	std::cout << "Name: " << name << ", CI: " << CI << std::endl;
}
void Plorg::enterDate()
{
	char* name_m = new char[Max]; int cik;
	std::cout << "Enter name: "; std::cin >> name_m;
	std::cout << "Enter CI: "; std::cin >> cik;
	*this = Plorg(name_m, cik);
}