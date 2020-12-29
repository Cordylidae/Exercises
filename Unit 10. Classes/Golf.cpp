#include<iostream>
#include"Golf.h"
using namespace std;

Golf::Golf(const char* name, int hc)
{
	fullname = (char*)name;
	handsicap = hc;
}

void Golf::setgolf()
{
	char *ch = new char[40]; int hand;
	cout << "Enter name of golfist: ";
	cin>>ch;
	cout <<"Enter his handicap: ";
	cin >> hand;
	
	*this = Golf(ch, hand);
}

void Golf::handicap(int hc)
{
	handsicap += hc;
}

void Golf::showgolf() const
{
	cout << "Name: " << fullname << " handicap: " << this->handsicap << endl;
}