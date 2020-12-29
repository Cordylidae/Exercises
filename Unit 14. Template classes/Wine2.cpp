#include"Wine2.h"

Wine2::Wine2(const char* l, int y, const int yr[], const int bot[])
{
	label = l;
	year = y;

	

	first().resize(year);
	second().resize(year);

	for (int i = 0; i < year; i++)
	{
		first()[i] = yr[i];
		second()[i] = bot[i];
	}

}
Wine2::Wine2(const char* l, int y)
{
	label = l;
	year = y;

	first().resize(y);
	second().resize(y);
}

Wine2::Wine2()
{
	label = "none";
	year = 0;

	first().resize(0);
	second().resize(0);

}

Wine2::~Wine2()
{

}

int Wine2::sum()
{
	int s = 0;
	s = second().sum();
	return s;
}

void Wine2::GetBottles()
{
	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> second()[i];
	}
}

Wine2::operator const std::string& ()
{
	return label;
}

void Wine2::Show()
{
	std::cout << "Wine: " << (const std::string &)(*this) << "\n";
	std::cout << "\tYear\tBottels\n";

	for (int i = 0; i < year; i++)
	{
		std::cout << "\t" << first()[i] << "\t" << second()[i] << "\n";
	}
}

