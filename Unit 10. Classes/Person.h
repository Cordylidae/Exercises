#ifndef  Person_H_
#define Person_H_

#include<string>

class Person
{
private:
	static const int LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const std::string& ln, const char* fn = "Heyyou");

	void Show() const; // fname lname 
	void FormalShow() const; // lname, fname
};

#endif // ! Person_H_


