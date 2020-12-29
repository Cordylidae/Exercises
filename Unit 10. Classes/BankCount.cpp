#include<iostream>
#include"BankCount.h"

BankCount::BankCount()
{
	name = "no name";
	numberCount = "none";
	balance = 0.0;
}

BankCount::BankCount(const std::string& name_m, const std::string& numb, double bal)
{
	name = name_m;
	numberCount = numb;
	balance = bal;
}


BankCount::~BankCount()
{
	std::cout << "Destroyed cards' count: " << numberCount<<std::endl;
}

void BankCount::showCount() const
{
	using std::cout;

	cout << "Name User: " << name << std::endl;
	cout << "Count of card: " << numberCount << std::endl;

	std::ios_base::fmtflags orig = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = cout.precision(2);

	cout << "Balance: $" << balance << std::endl;

}

void BankCount::addMoney(double sum)
{
	balance += sum;
}

void BankCount::moinsMoney(double sum)
{
	balance -= sum;
}