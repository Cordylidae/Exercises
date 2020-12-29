#include"cd2.h"

Cd2::Cd2()
{
	performers = nullptr;
	label = nullptr;
}
Cd2::Cd2(char* s1, char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd2::Cd2(const char s1[50], const char s2[20], int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd2::Cd2(const Cd2& d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd2::~Cd2()
{
	delete[] performers;
	delete[] label;
}
void Cd2::Report() const
{
	std::cout << "performers: " << performers << ", label: " << label << ", selections: " << selections << ", playtime: " << playtime << std::endl;
}
Cd2& Cd2::operator=(const Cd2& d)
{
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}