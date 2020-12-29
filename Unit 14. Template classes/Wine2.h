#ifndef WINE2_H_
#define WINE2_H_

#include<iostream>
#include<string>
#include<valarray>


template <class T1, class T2>
class Pair2
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair2<std::valarray<int>, std::valarray<int>> operator=(Pair2<std::valarray<int>, std::valarray<int>>);
	Pair2(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair2() {}
};

template <class T1, class T2>
T1& Pair2<T1, T2>::first()
{
	return a;
}

template <class T1, class T2>
T2& Pair2<T1, T2>::second()
{
	return b;
}

template <class T1, class T2>
Pair2<std::valarray<int>, std::valarray<int>> Pair2 <T1, T2>::operator=(Pair2 <std::valarray<int>, std::valarray<int>> pr)
{
	int size = pr.first().size();

	first().resize(size);
	second().resize(size);

	for (int i = 0; i < size; i++)
	{
		first() = pr.first();
		second() = pr.second();
	}
	return *this;
}


class Wine2 : private Pair2<std::valarray<int>, std::valarray<int>>
{
private:
	std::string label;
	int year;
public:
	Wine2();
	Wine2(const char* l, int y, const int yr[], const int bot[]);
	Wine2(const char* l, int y);
	~Wine2();

	void GetBottles();
	int sum();
	std::string& Label() { return label; };
	explicit operator const std::string& ();
	void Show();

};


#endif 
