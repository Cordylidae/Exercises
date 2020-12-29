#include"Wine.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	label = l;
	year = y;

	PairArray.first().resize(year);
	PairArray.second().resize(year);

	for (int i = 0; i < year; i++)
	{
		PairArray.first()[i] = yr[i];
		PairArray.second()[i] = bot[i];
	}

}
Wine::Wine(const char* l, int y)
{
	label = l;
	year = y;

	PairArray.first().resize(y);
	PairArray.second().resize(y);
}

Wine::Wine()
{
	label = "none";
	year = 0;

	PairArray.first().resize(0);
	PairArray.second().resize(0);

}

Wine::~Wine()
{

}

int Wine::sum()
{
	int s = 0;
	s = PairArray.second().sum();
	return s;
}

void Wine::GetBottles()
{
	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year: "; 
		std::cin >> PairArray.first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> PairArray.second()[i];
	}
}

void Wine::Show()
{
	std::cout << "Wine: " << label << "\n";
	std::cout << "\tYear\tBottels\n";

	for (int i = 0; i < year; i++)
	{
		std::cout << "\t"<< PairArray.first()[i]<<"\t"<< PairArray.second()[i]<<"\n";
	}
}