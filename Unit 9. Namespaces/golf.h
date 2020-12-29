#include<string>
using namespace std;

struct golf
{
	char *fullname = new char[40];
	int handicap;
};

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(const golf & g);