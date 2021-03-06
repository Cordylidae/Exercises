#include"emp.h"

/// abstr_emp classes methods

abstr_emp::abstr_emp() :fname("none"), lname("none"), job("nope") {}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
	std::cout << std::setw(14) << fname << "|"<< std::setw(14) << lname << "|" 
		<< std::setw(14) << job << "|"<<std::setw(15) <<  "|"
		<< std::setw(15) << "|";
}

void abstr_emp::WriteAll(std::fstream & finout) const
{
	finout << fname << " " << lname << " " << job << " ";
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
	os << e.lname << ", " << e.fname << std::endl;
	return os;
}


/// employee classes methods

employee::employee() :abstr_emp() {}
employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee::WriteAll(std::fstream& finout) const
{
	finout << 0 << " ";
	abstr_emp::WriteAll(finout);
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

/// manager classes methods


manager::manager() :abstr_emp(), inchargeof(0) {}
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	 
	std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << std::setw(14) << inchargeof << "|";
}
void manager::WriteAll(std::fstream& finout) const
{
	finout << 1 << " ";
	abstr_emp::WriteAll(finout);
	finout << inchargeof;
}
void manager::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter in charge of: ";
	std::cin >> inchargeof;
}

/// fink classes methods


fink::fink() :abstr_emp(), reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}


fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout <<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
		<< std::setw(14) << reportsto << "|" << std::setw(15) << "|";
}
void fink::WriteAll(std::fstream& finout) const
{
	finout << 2 << " ";
	abstr_emp::WriteAll(finout);
	finout << reportsto;
}
void fink::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter reports to: ";
	std::cin >> reportsto;
}

/// highfink classes methods


highfink::highfink()
	:abstr_emp(), fink(), manager() {}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), fink(e, rpo), manager(e, ico) {}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), fink(m, rpo), manager(m) {}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), fink(f), manager(f, ico) {}

highfink::highfink(const highfink& h)
	: abstr_emp(h), fink(h), manager(h) {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" 
		<< std::setw(14) << fink::ReportsTo() << "|" << std::setw(14) << manager::InChargeOf() << "|";
}
void highfink::WriteAll(std::fstream& finout) const
{
	finout << 3 <<" ";
	abstr_emp::WriteAll(finout);
	finout << fink::ReportsTo()<< " " <<manager::InChargeOf();
}
void highfink::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Please enter reports to: ";
	std::cin >> fink::ReportsTo();

	std::cout << "Please enter in charge of: ";
	std::cin >> manager::InChargeOf();
}
