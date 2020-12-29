#include<iostream>
#include<vector>
#include<typeinfo>
#include<initializer_list>
#include"Cmpv.h"
using namespace std;

/*
//1 // initializer_list<> fr template

template<class T>
const char* avarage_list(initializer_list<T> a)
{
	return typeid(T).name();
}

int main()
{
	auto q = avarage_list({ 15.4,10.7,9.0 });
	cout << q << endl;

	cout << avarage_list({ 20,30,19,17,45,38 }) << endl;

	auto ad = avarage_list<double>({ 'A', 70, 65.33 });

	cout << ad << endl;

	return 0;
}

*/
/*
// 2 // test &&href constructor and operate=

int main()
{
	cout << "Object cp1 ";
	Cmpv cp1("P", "D");
	cout << "Object cp2 ";
	Cmpv cp2;
	cout << "Object cp2 ";
	cp2 = cp1;
	cout << "Object cp3 ";
	Cmpv cp3(cp1 + cp2);
	cout << "Object cp4 ";
	Cmpv cp4;
	cout << "Object cp4 ";
	cp4 = cp3 + cp2;
	cout << "Object cp5 ";
	Cmpv cp5 = cp4;

	cp5.Display();

}
*/
/*
// 3 // recyles function with many arguments with many types

template <typename T>
long double sum_values(const T& t)
{
	long double sum = 0;
	sum += t;
	
	return sum;
}

template <typename T,typename... Asg>
long double sum_values(const T& t,const Asg&... asg)
{
	long double sum;
	
	sum=sum_values(asg...);
	
	return sum+t;
}

int main()
{
	long double s = sum_values(34.3, 12, 42, 11.7, 'A');
	cout <<"Sum by 34.3, 12, 42, 11.7, 'A': " << s << endl;

	long double s2 = sum_values(12.3, 2, 14, 10.7);
	cout << "Sum by 12.3, 2, 14, 10.7: " << s2 << endl;

	return 0;
}
*/

// 4 // lambda expressions anonim and named

#include<list>
#include<iterator>
#include<algorithm>

int main()
{
	auto outint = [](int n) {std::cout << n << " "; };

	list<int> yadayada{ 50, 100, 90 ,180, 60 ,210 ,415, 88 ,188, 201 };
	list<int> etcetera = { 50, 100, 90 ,180, 60 ,210 ,415, 88 ,188, 201 };

	cout<<"Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	int count = 100;
	yadayada.remove_if([&count](int n) {return n > count; });

	etcetera.remove_if([](int n) {return n > 200; });

	
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	return 0;
}