#include"Person.h"
#include<iostream>
#include<cstring>

#pragma warning(disable: 4996);

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const
{
	if (lname != "")std::cout << fname << " " << lname << std::endl;
	else std::cout << "Noname\n";
} // fname lname 

void Person::FormalShow() const{
	if (lname != "")std::cout << lname << ", " << fname << std::endl;
	else std::cout << "Noname\n";
} // lname, fname
