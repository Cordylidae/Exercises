#include"Stock.h"

#pragma warning(disable : 4996);

Stock::Stock() 
{
	company = nullptr;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char* co, long n, double pr)
{
	company = new char[strlen(co)+1];
	strcpy(company, co);
	
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
		shares = 0;
	}
	else shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock() 
{
	delete[] company;
}

void Stock::buy(long num, double price) 
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative; " << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares sold can't be negative; " << "Transaction is aborted.\n";
	}
	else if(num > shares)
	{
		std::cout << "You can't sell more than you have! " << "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price) 
{
	share_val = price;
	set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& st)
{
	using std::ios_base;

	ios_base::fmtflags orig = std::cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);

	os << "Company: "<<st.company<<" Shares: "<< st.shares<<"\n";
	os << "Shares Price: $" << st.share_val;
	
	std::cout.precision(2);
	os << " Total Worth: $" << st.total_val;

	std::cout.setf(orig,ios_base::floatfield);
	std::cout.precision(prec);
	return os;
}

const Stock& Stock::topval(const Stock& s) const 
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
