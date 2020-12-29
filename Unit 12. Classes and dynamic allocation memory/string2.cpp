#include<cstring>
#include"string2.h"

#pragma warning(disable : 4996);

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}

//
String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	num_strings++;
}
String::~String()
{
	--num_strings;
	delete[]str;
}

//
void String::stringup()
{
	for (int i = 0; i < len + 1; i++) {
		str[i] = toupper(str[i]);
	}
}
void String::stringlow()
{
	for (int i = 0; i < len + 1; i++) {
		str[i] = tolower(str[i]);
	}
}

int String::letterInString(char ch)
{
	int kol = 0;
	for (int i = 0; i < len + 1; i++) {
		if (ch == str[i])kol++;
	}
	return kol;
}

String& String::operator=(const String& c)
{
	if (this == &c)
		return *this;

	delete[] str;
	len = c.len;
	str = new char[len + 1];
	strcpy(str, c.str);
	return *this;
}
String& String::operator=(const char* s) 
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

//

String& String::operator+(const String& c)
{
	String* s = new String;
	s->len = len + 2 + c.len;
	s->str = new char[s->len];
	strcpy(s->str, str);
	strcat(s->str, c.str);

	return *s;
}
String& String::operator+(const char* c)
{
	String* s = new String;
	s->len = len + 2 + strlen(c);
	s->str = new char[s->len];
	strcpy(s->str, str);
	strcat(s->str, c);

	return *s;
}
String& operator+(const char* c, const String& st)
{
	String* s = new String;
	s->len = st.len + 2 + strlen(c);
	s->str = new char[s->len];
	strcpy(s->str, c);
	strcat(s->str, st.str);

	return *s;
}
char& String::operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str)<0);
}
bool operator>(const String& st1, const String& st2) 
{
	return st2.str<st1.str;
}
bool operator==(const String& st1, const String& st2) 
{
	return (strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st1) 
{
	os << st1.str;
	return os;
}
istream&  operator>>(istream& is, String& st1)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st1 = temp;
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}

