#include"Classic.h"


Classic::Classic(char* s1, char* s2, char* s3, int n, double x) : Cd(s2, s3, n, x)
{
	strcpy(name, s1);
}
Classic::Classic(const char s1[80], const char s2[50], const char s3[20], int n, double x) : Cd(s2, s3, n, x)
{
	strcpy(name, s1);
}
Classic::Classic(const Classic& d)
{
	strcpy(name,d.name);
	Cd::Cd(d);
}
Classic::~Classic() {}
void Classic::Report() const {
	
	std::cout << "Name: " << name << ", ";
	Cd::Report();
}
Classic& Classic::operator=(const Classic& d)
{
	strcpy(name, d.name);
	Cd::operator=(d);

	return *this;
}