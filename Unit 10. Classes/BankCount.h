#ifndef Bank_H_
#define Bank_H_

#include<string>

class BankCount
{
private:
	std::string name;
	std::string numberCount;
	double balance;
	
public:
	BankCount();
	BankCount(const std::string& name_m, const std::string& numb, double bal = 0.0);
	~BankCount();

	void showCount() const;
	void addMoney(double sum);
	void moinsMoney(double sum);
};

#endif // !Bank_H_
