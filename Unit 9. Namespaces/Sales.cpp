#include<iostream>
#include"Sales.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		double sum = 0, max, min;


		for (int i = 0; i < n; i++)
		{
			sum += ar[i];
		}

		max = ar[0];
		min = ar[0];

		for (int i = 0; i < n; i++)
		{
			if (max <= ar[i]) {
				max = ar[i];
			}
			if (min >= ar[i]) {
				min = ar[i];
			}
		}

		s.average = sum / n;
		s.max = max;
		s.min = min;
		s.sales[0] = min;

		for (int i = 1; i < SALES::QUARTERS; i++)
			s.sales[i] = 0;

	}

	void setSales(Sales& s)
	{
		double sum = 0, max, min;

		std::cout << "Enter sale by 4 quartet: ";
		for (int i = 0; i < SALES::QUARTERS; i++)
		{
			std::cin >> s.sales[i];
			sum += s.sales[i];
		}

		max = s.sales[0];
		min = s.sales[0];

		for (int i = 0; i < SALES::QUARTERS; i++)
		{
			if (max <= s.sales[i])s.max = s.sales[i];
			if (min >= s.sales[i])s.min = s.sales[i];
		}

		s.average = sum / SALES::QUARTERS;
	}

	void showSales(const Sales& s)
	{
		static int count = 1;

		std::cout << '#' << count << " Sales: ";
		for (int i = 0; i < SALES::QUARTERS; i++)
			std::cout << s.sales[i] << " ";
		std::cout << std::endl << "Average by this sales: " << s.average << std::endl;
		std::cout << "Minimal by this sales: " << s.min << std::endl;
		std::cout << "Maximal by this sales: " << s.max << std::endl;

		count++;
	}
}
