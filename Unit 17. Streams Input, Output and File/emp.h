#ifndef EMP_H_
#define EMP_H_

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>



class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
	virtual ~abstr_emp() = 0;
	virtual void ShowAll() const;
	virtual void WriteAll(std::fstream&) const;
	virtual void SetAll();

	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
	
};

class employee :virtual public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void WriteAll(std::fstream&) const;
	virtual void SetAll();
};

class manager : virtual public employee
{
private:
	int inchargeof; // count of employee 
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);

	virtual void ShowAll() const;
	virtual void WriteAll(std::fstream&) const;
	virtual void SetAll();

};

class fink : virtual public employee
{
private:
	std::string reportsto; // to whom
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);

	virtual void ShowAll() const;
	virtual void WriteAll(std::fstream&) const;
	virtual void SetAll();

};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const fink& f, int ico);
	highfink(const highfink& h);

	virtual void ShowAll() const;
	virtual void WriteAll(std::fstream&) const;
	virtual void SetAll();

};


#endif 