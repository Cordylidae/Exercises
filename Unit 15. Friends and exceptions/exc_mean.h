#ifndef EXC_H_
#define EXC_H_

#include<stdexcept>
#include<string>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(const std::string& what_arg) : logic_error(what_arg) {}// { std::cout << what_arg << std::endl; }
	bad_hmean(const char* what_arg) : logic_error(what_arg) {}
	//const char* what() { return "hmean(): invalid arguments: a = -b\n"; }
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean(const std::string& what_arg) : logic_error(what_arg) {}
	bad_gmean(const char * what_arg) : logic_error(what_arg) {}
	//const char* what() { return "gmean() arguments should be >=0\n"; }
};


//class bad_hmean : public std::logic_error {
//	using std::logic_error::logic_error;
//};
//
//class bad_gmean : public std::logic_error {
//	using std::logic_error::logic_error;
//};


#endif