#ifndef  CMPV_H_
#define CMPV_H_

#include<string>
#include<iostream>

class Cmpv
{
public : 
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cmpv();
	Cmpv(std::string q,std::string z);
	Cmpv(const Cmpv & cp);
	Cmpv(Cmpv && mv);
	~Cmpv();
	Cmpv & operator=(const Cmpv & cp);
	Cmpv & operator=(Cmpv && mv);
	Cmpv operator+(const Cmpv & obj) const;
	void Display() const;
};

#endif // ! CMPV_H_
