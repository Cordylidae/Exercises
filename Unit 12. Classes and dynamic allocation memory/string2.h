#ifndef STRING2_H_
#define STRING2_H_
#include<iostream>
#include<cctype>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

using std::strcpy;
using std::strcat;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& s);
	~String();
	int lenght() const { return len; }
	void stringup();
	void stringlow();
	int letterInString(char ch);

	String& operator=(const String& c);
	String& operator=(const char *);
	String& operator+(const String& c);
	String& operator+(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	
	friend String& operator+(const char* s, const String& st);
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st1);
	friend istream& operator>>(istream& is, String& st1);



	static int HowMany();
};

#endif