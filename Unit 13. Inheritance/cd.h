#ifndef CD_H_
#define CD_H_

#include<iostream>
#pragma warning(disable : 4996);

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char*  s1, char* s2, int n, double x);
	Cd(const char s1[50],const char s2[20], int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

#endif 
