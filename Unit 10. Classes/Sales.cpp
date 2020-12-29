#include<iostream>
#include"Sales.h"

namespace SALES
{

	Sales::Sales(const double ar[], int n)
	{
		double sum = 0;


		for (int i = 0; i < n; i++)
		{
			sum += ar[i];
			sales[i] = ar[i];
		}

		max = ar[0];
		min = ar[0];

		double g = sales[0];

		for (int i = 0; i < n; i++)
		{
			if (max <= ar[i]) {
				max = ar[i];
			}
			if (min >= ar[i]) {
				min = ar[i];
				sales[0] = min;
				sales[i] = g;
				g = sales[0];
			}
		}

		average = sum / n;
		sales[0] = min;

		for (int i = 1; i < Sales::QUARTERS; i++)
		{
			if (sales[i] == min)sales[i] = ar[i];
			else sales[i] = 0;
		}
	}

	Sales::Sales()
	{
		max = INT32_MIN;
		min = INT32_MAX;
		average = 0;


		//for (int i = 0; i < Sales::QUARTERS; i++)
		//{
		//	sales[i] = 0;
		//}

	}

	void Sales::setSales()
	{
		double *ar = new double[4];
		std::cout << "Enter 4 or less doubel numbers by space button (Enter) to continue: ";// like this 43 21 34
		
		int i;
		for (i = 0; i < 4; i++)
		{
			if(!(std::cin >> ar[i]))break;
			if (std::cin.get() == '\n')break;
		}
		*this = Sales(ar, i+1);
	}

	void Sales::showSales() const
	{
		static int count = 1;

		std::cout << '#' << count << " Sales: ";
		for (int i = 0; i < Sales::QUARTERS; i++)
			std::cout << sales[i] << " ";
		std::cout << std::endl << "Average by this sales: " << average << std::endl;
		std::cout << "Minimal by this sales: " << min << std::endl;
		std::cout << "Maximal by this sales: " << max << std::endl;

		count++;
	}
}
