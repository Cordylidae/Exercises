#include<iostream>
#include<string>
#include"golf.h"
using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
	g.fullname = (char* )name;
	g.handicap = hc;
}

int setgolf(golf& g)
{
	cout << "Enter name of golfist: ";
	cin.getline(g.fullname,40);
	cout << "Enter his handicap: ";
	cin >> g.handicap;
	cin.get();

	char* fin = g.fullname;
	while (*fin) 
	{
		if (*fin != ' ' && *fin != '\n')return 1;
		fin++;
	}
	return 0;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	cout << "Name: " << g.fullname << " handicap: " << g.handicap << endl;
}