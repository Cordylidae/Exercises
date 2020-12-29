#include<iostream>
#include"cow.h"

#pragma warning(disable : 4996);

using std::strcpy;
using std::cout;
using std::endl;

Cow::Cow()
{
	strcpy(name, "noname");
	hobby = nullptr;
	weight = 0;
}

Cow::Cow(const char* m, const char* ho, double wt)
{
	strcpy(name, m);
	hobby = new char[strlen(ho)+1];
	strcpy(hobby, ho);
	weight = wt;
}


Cow::Cow(const Cow& c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}


Cow::~Cow()
{
	delete[] hobby;
}


Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;

	strcpy(name, c.name);

	delete[]hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);

	weight = c.weight;

	return *this;
}


void Cow::showCow() const
{
	cout << "Name of Cow: " << name<<endl;
	cout << "Hobbies of Cow: " << hobby << endl;
	cout << "Weight of Cow: " << weight << endl;
}
