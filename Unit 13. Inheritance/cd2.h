#ifndef CD2_H_
#define CD2_H_

#include<iostream>
#pragma warning(disable : 4996);

class Cd2
{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd2(char* s1, char* s2, int n, double x);
	Cd2(const char s1[50], const char s2[20], int n, double x);
	Cd2(const Cd2& d);
	Cd2();
	virtual ~Cd2();
	virtual void Report() const;
	Cd2& operator=(const Cd2& d);
};

#endif 
