#ifndef CLASSIC_H_
#define CLASSIC_H_

#include"cd.h"

class Classic : public Cd
{
private:
	char name[80];
public:
	Classic(char* s1, char* s2,char* s3, int n, double x);
	Classic(const char s1[80], const char s2[50],const char s3[20], int n, double x);
	Classic(const Classic& d);
	Classic() {};
	virtual ~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& d);
};

#endif 
