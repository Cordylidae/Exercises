#ifndef WINE_H_
#define WINE_H_

#include<iostream>
#include<string>
#include<valarray>


template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {}
};

template <class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}

template <class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}


class Wine
{
private:
	std::string label;
	Pair<std::valarray<int>, std::valarray<int>> PairArray;
	int year;
public:
	Wine();
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l,int y);
	~Wine();

	void GetBottles();
	int sum();
	std::string& Label() { return label; };
	void Show();
};


#endif 
