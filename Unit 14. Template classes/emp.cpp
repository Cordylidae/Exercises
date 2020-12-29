#include"emp.h"

/// abstr_emp classes methods

abstr_emp::abstr_emp():fname("none"), lname("none"), job("lox") {}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j):fname(fn),lname(ln),job(j){}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const 
{
	std::cout<< "first name: " << fname << ", last name: " << lname << "\njob: " << job << std::endl;
}
void abstr_emp::SetAll() 
{
	std::cout << "Please enter first name: ";
	std::cin >> fname;
	
	std::cout << "Please enter last name: ";
	std::cin >> lname;

	std::cout << "Please enter job: ";
	std::cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e) 
{
	os << e.lname << ", " << e.fname <<std::endl;
	return os;
}

/// employee classes methods

employee::employee():abstr_emp() {}
employee::employee(const std::string& fn, const std::string& ln, const std::string& j):abstr_emp(fn,ln,j) {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

/// manager classes methods


manager::manager():abstr_emp(),inchargeof(0) {}
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico):abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp& e, int ico):abstr_emp(e), inchargeof(ico){}
manager::manager(const manager& m):abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const 
{
	abstr_emp::ShowAll();
	std::cout << "inchargeof: " << inchargeof << "\n";
}
void manager::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter inchargeof: ";
	std::cin >> inchargeof;
	std::cout << "\n";

}

/// fink classes methods


fink::fink():abstr_emp(),reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	:abstr_emp(fn,ln,j),reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e),reportsto(rpo){}


fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "reportsto: " << reportsto << "\n";
}
void fink::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter reportsto: ";
	std::cin >> reportsto;
	std::cout << "\n";
}

/// highfink classes methods


highfink::highfink()
	:abstr_emp(),fink(),manager() {}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) 
	: abstr_emp(fn,ln,j),fink(fn,ln,j,rpo),manager(fn,ln,j,ico){}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) 
	: abstr_emp(e), fink(e, rpo), manager(e, ico) {}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), fink(m, rpo), manager(m) {}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), fink(f), manager(f,ico) {}

highfink::highfink(const highfink& h)
	: abstr_emp(h), fink(h), manager(h) {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "reportsto: " << fink::ReportsTo() << "\ninchargeof: " << manager::InChargeOf() << "\n";
	std::cout << "\n";
}
void highfink::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter reportsto: ";
	std::cin >> fink::ReportsTo();

	std::cout << "Please enter inchargeof: ";
	std::cin >> manager::InChargeOf();
}
