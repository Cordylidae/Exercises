#ifndef  COW_H_
#define  COW_H_


class Cow
{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* m, const char* ho,double wt);
	Cow(const Cow& c);
	~Cow();
	Cow & operator=(const Cow& c);
	void showCow() const;
};

#endif