#include"Cmpv.h"

Cmpv::Cmpv()
{
	std::cout << "declaretion of object:\n";

	pi = nullptr;
}
Cmpv::Cmpv(std::string q, std::string z)
{
	std::cout << "create object:\n";

	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}
Cmpv::Cmpv(const Cmpv& cp)
{
	std::cout << "copy constructor called:\n";

	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}
Cmpv::Cmpv(Cmpv&& mv)
{
	std::cout << "move constructor called:\n";

	pi = mv.pi;
	mv.pi = nullptr;
}
Cmpv::~Cmpv()
{
	std::cout << "deleted object:\n";
	delete pi;
}
Cmpv& Cmpv::operator=(const Cmpv& cp)
{
	std::cout << "copy assignment operator called:\n";

	if (this == &cp)
		return *this;

	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	
	return *this;
}

Cmpv& Cmpv::operator=(Cmpv&& mv)
{
	std::cout << "move assignment operator called:\n";

	if (this == &mv)
		return *this;

	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;

	return *this;
}
Cmpv Cmpv::operator+(const Cmpv& obj) const
{
	std::cout << "operator+ called:\n";

	Cmpv temp = Cmpv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
	return temp;
}
void Cmpv::Display() const
{
	std::cout << "Qcode: " << pi->qcode << " ";
	std::cout << ", Zcode: " << pi->zcode << "\n";
}