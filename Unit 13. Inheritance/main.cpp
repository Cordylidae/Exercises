#include<iostream>

/*
//Test
#include"Test.h"

int main()
{
	A* humans[10];

	for (int i = 0; i < 10; i++)
	{
		int kind;
		std::cout << "Enter kind of human 1 or 2, 1 - plancton, 2 - somebody: ";
		std::cin >> kind;

		if (kind == 1)humans[i] = new A();
		else humans[i] = new B();
	}
	std::cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		humans[i]->Draw();
		std::cout << "\n";
	}

	for (int i = 0; i < 10; i++) {
		delete humans[i];
	}
	return 0;
}
*/
/*
// 1 
using namespace std;
#include"Classic.h"

void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantastic C","Alfred Brendel","Philips", 2,57.17);

	Cd* pcd = &c1;

	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to object: \n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}

*/
/*
// 2 
using namespace std;
#include"Classic2.h"

void Bravo(const Cd2& disk);

int main()
{
	Cd2 c1("Beatles", "Capitol", 14, 35.5);
	Classic2 c2 = Classic2("Piano Sonata in B flat, Fantastic C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd2* pcd = &c1;

	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to object: \n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic2 copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd2& disk)
{
	disk.Report();
}
*/
/*
//3 
#include<string>
#include"DMA.h"

const int Counts = 6;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	DMA* something[Counts];
	
	char label[40],color[40],style[40];
	
	int rating;
	char ch;

	for (int i = 0; i < Counts; i++)
	{
		cout << "Enter label: ";
		cin.getline(label, 40);
		cout << "Enter rating: ";
		cin >> rating;
		cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA: ";
		

		while (cin >> ch && (ch != '1' && ch != '2' && ch != '3'))
			cout << "Enter 1, 2 or 3: ";

		cin.get();

		switch (ch)
		{
		case '1':
		{
			something[i] = new baseDMA(label, rating);
		}
		break;
		case '2':
		{
			cout << "Enter color: ";
			cin.getline(color, 40);
			something[i] = new lacksDMA(color, label, rating);
		}
		break;
		case '3':
		{
			cout << "Enter style: ";
			cin.getline(style, 40);
			something[i] = new hasDMA(style, label, rating);
		}
		break;
		}
	}


	for (int i = 0; i < Counts; i++)
	{
		something[i]->View();
		cout << endl;
	}

	for (int i = 0; i < Counts; i++)
	{
		delete something[i];
	}

	cout << "Done!!\n";
	
	return 0;
}
*/

// 4

#include"Port.h"

using namespace std;

int main()
{
	Port port1,port2;
	port1 = Port("Gallo", "Twany", 6);
	port2 = port1;

	for (int i = 0; i < 3; i++)
	{
		int a;
		cout << "Enter number(>0) for take bottles, or number(<0) for give bottles: ";
		cin >> a;
		if (a > 0)port2 += a;
		else port2 -= abs(a);
	}

	cout << endl;

	VintagePort vport1("Pors",5,"Bully",1943),vport2;

	vport2 = vport1;

	for (int i = 0; i < 3; i++)
	{
		int a;
		cout << "Enter number(>0) for take bottles, or number(<0) for give bottles: ";
		cin >> a;
		if (a > 0)vport2 += a;
		else vport2 -= abs(a);
	}

	port1.Show();
	cout << endl;
	cout << port2 << endl << endl;



	vport1.Show();
	cout << endl;
	cout << vport2 << endl << endl;

	
	return 0;
}