#ifndef CLASSIC2_H_
#define CLASSIC2_H_

#include"cd2.h"

class Classic2 : public Cd2
{
private:
	char *name;
public:
	Classic2(char* s1, char* s2, char* s3, int n, double x);
	Classic2(const char s1[80], const char s2[50], const char s3[20], int n, double x);
	Classic2(const Classic2& d);
	Classic2();
	virtual ~Classic2();
	virtual void Report() const;
	Classic2& operator=(const Classic2& d);
};

#endif 
