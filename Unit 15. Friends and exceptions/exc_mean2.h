#ifndef EXC2_H_
#define EXC2_H_

#include<iostream>
#include<stdexcept>
#include<string>

class base_mean : public std::logic_error
{
private:
	double a;
	double b;

public:
	base_mean(const std::string& what_arg, double a_, double b_) : logic_error(what_arg),a(a_),b(b_) {}
	base_mean(const char* what_arg, double a_, double b_) : logic_error(what_arg), a(a_), b(b_) {}

	void M() { std::cout << what() << ". Yours arguments is " << a << " " << b << std::endl; }
};

class bad_hmean : public base_mean
{
public:
	bad_hmean(const std::string& what_arg,double a, double b) : base_mean(what_arg,a,b) {}
	bad_hmean(const char* what_arg, double a, double b) : base_mean(what_arg, a, b) {}
};

class bad_gmean : public base_mean
{
public:
	bad_gmean(const std::string& what_arg, double a, double b) : base_mean(what_arg,a,b) {}
	bad_gmean(const char* what_arg, double a, double b) : base_mean(what_arg,a,b) {}
	
};




#endif