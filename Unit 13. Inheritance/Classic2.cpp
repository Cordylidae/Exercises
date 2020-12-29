#include"Classic2.h"


Classic2::Classic2(char* s1, char* s2, char* s3, int n, double x) : Cd2(s2, s3, n, x)
{
	name = new char[strlen(s1) + 1];
	strcpy(name, s1);
}
Classic2::Classic2(const char s1[80], const char s2[50], const char s3[20], int n, double x) : Cd2(s2, s3, n, x)
{
	name = new char[strlen(s1) + 1];
	strcpy(name, s1);
}
Classic2::Classic2(const Classic2& d)
{
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
	Cd2::Cd2(d);
}
Classic2::Classic2()
{
	name = nullptr;
}
Classic2::~Classic2() 
{
	delete[] name;
}
void Classic2::Report() const {

	std::cout << "Name: " << name << ", ";
	Cd2::Report();
}
Classic2& Classic2::operator=(const Classic2& d)
{
	delete[] name;
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
	Cd2::operator=(d);

	return *this;
}