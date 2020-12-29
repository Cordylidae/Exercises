#include<iostream>

/*
//1
#include"tv.h"

int main()
{
	using std::cout;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";

	s42.settings();
	Remote grey;
	cout << "\n Remote settings:\n";
	grey.settings();
	s42.onoff();
	s42.norints(grey);
	grey.settings();
	s42.onoff();
	s42.norints(grey);
	grey.settings();

	
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";

	s42.settings();
	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();

	return 0;
}
*/
/*
//2


#include<cmath>
#include"exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	cout << "Enter two numbers: ";

	while (cin >> x >> y)
	{
		try 
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";

		}
		catch (std::logic_error & eo)
		{
			cout << eo.what();
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("hmean(): invalid arguments: a = -b\n");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("gmean() arguments should be >=0\n");
	return std::sqrt(a * b);
}
*/
/*
//3


#include<cmath>
#include"exc_mean2.h"

double hmean(double a, double b);
double gmean(double a, double b);


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	cout << "Enter two numbers: ";

	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";

		}
		catch (base_mean& eo)
		{
			eo.M();
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("hmean(): invalid arguments: a = -b",a,b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("gmean() arguments should be >=0",a,b);
	return std::sqrt(a * b);
}
*/

//4
#include<typeinfo>
#include"sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220,1100,1122,2212,1232,2334,
		2884,2393,3302,2922,3002,3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	
	cout << "First try block:\n";

	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; i++)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (Sales::bad_index & bad)
	{
		Sales::bad_index* pg = &bad;
		LabeledSales::nbad_index* ps;
		
		cout << bad.what();
		if (ps = dynamic_cast<LabeledSales::nbad_index*>(pg))
		{
			cout << "bad index: " << ps->label_val() << endl;
		}
		cout << "bad index: " << bad.bi_val() << endl;
	}

	cout << "\nNext try block:\n";

	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
	}
	catch (Sales::bad_index& bad)
	{
		
		Sales::bad_index* pg = &bad;
		LabeledSales::nbad_index* ps;

		cout << bad.what();
		if (ps = dynamic_cast<LabeledSales::nbad_index*>(pg))
		{
			cout << "bad index: " << ps->label_val() << endl;
		}
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "done\n";
	return 0;
}