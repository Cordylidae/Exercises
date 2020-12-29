#include<iostream>


/*
// 1
#include<ctime>
#include<cstdlib>
#include"Vect.h"

int main()
{
	
	using namespace std;
	using VECTOR::Vector;
	
	ofstream OutFile;
	

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
	{

		cout << "Enter step length: ";
		if (!(cin >> dstep))break;

		OutFile.open("Output.txt");
		OutFile << "Target Distance: " << target << " , Step Size: " << dstep<<endl;
		while (result.magval() < target)
		{
			OutFile << steps << ":" << result<<endl;
			direction = rand()%360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		OutFile << "After "<<steps<<" steps, the subject "
			"has the following location:\n";
		OutFile << result << endl;
		result.polar_mode();
		OutFile << "or\n" << result << endl;
		OutFile << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);

		OutFile.close();
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
	
	return 0;
}
*/
/*
// 2
#include<ctime>
#include<cstdlib>
#include"Vect2.h"

int main()
{

	using namespace std;
	using VECTOR2::Vector;

	ofstream OutFile;


	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
	{

		cout << "Enter step length: ";
		if (!(cin >> dstep))break;

		OutFile.open("Output.txt");
		OutFile << "Target Distance: " << target << " , Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			OutFile << steps << ":" << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		OutFile << "After " << steps << " steps, the subject "
			"has the following location:\n";
		OutFile << result << endl;
		result.polar_mode();
		OutFile << "or\n" << result << endl;
		OutFile << "Average outward distance per step = " << result.magval() / steps << endl;
		
		steps = 0;
		result.reset(0.0, 0.0);

		
		OutFile.close();
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;

	return 0;
}
*/
/*
// 3
#include<ctime>
#include<cstdlib>
#include"Vect.h"

int main()
{

	using namespace std;
	using VECTOR::Vector;

	ofstream OutFile;


	srand(time(0));
	
	int n;

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep,maxstep,minstep,averstep=0;

	cout << "Enter count for tryes\n";
	cin >> n;

	for (int i=0;i<n;i++)
	{
		cout << "Enter target distance and step length: ";
		cin >> target >> dstep;
		
		OutFile.open("Output.txt");
		OutFile << "Target Distance: " << target << " , Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			OutFile << steps << ":" << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		if (i == 0) { maxstep = steps; minstep = steps;}
		if (maxstep < steps)maxstep = steps;
		if (minstep > steps)minstep = steps;
		averstep += steps;

		OutFile << "After " << steps << " steps, the subject "
			"has the following location:\n";
		OutFile << result << endl;
		result.polar_mode();
		OutFile << "or\n" << result << endl;
		OutFile << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);

		OutFile.close();
	}
	cout <<"Max Steps: "<<maxstep<<", min steps: "<<minstep<<", average steps: "<<averstep<< " Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;

	return 0;
}
*/
/*
//4
#include"Time.h"
int main()
{
	using std::cout;
	using std::endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and tosca:\n";
	cout << aida <<"; "<< tosca<<endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: "<< temp<<endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10 * tosca << endl;

	return 0;
}
*/
/*
//5

#include"Stonewt.h"

int main()
{
	using namespace std;

	Stonewt Kos(1,14);
	Stonewt Pos(4);
	Stonewt temp;

	cout << "Kos and Pos:\n";
	cout << Kos << Pos << endl;

	cout << "Kos + Pos:\n";
	temp = Kos + Pos;
	cout << temp << endl;
	
	cout << "Kos - Pos:\n";
	temp = Kos - Pos;
	cout << temp << endl;

	Kos.pounds_mode();
	cout << "Kos * 1.7 only pounds:\n";
	cout << Kos * 1.7 << endl;

	Pos.stone_mode();
	cout << "2.8 * Pos only stones:\n";
	cout << 2.8 * Pos << endl;


	return 0;
}
*/
/*
//6
#include"Stonewt.h"
int main()
{
	Stonewt mas[6] = {
		Stonewt(11,7),
		Stonewt(11,7),
		Stonewt(6,9)
	};

	for (int i = 3; i < 6; i++)
	{
		int stone; double pound;

		std::cout << "Enter Stones and pounds: \n";
		std::cin >> stone >> pound;
		mas[i] = Stonewt(stone, pound);
	}

	Stonewt smin=mas[0], smax=mas[0];
	int kol = 0;

	for (int i = 0; i < 6; i++)
	{
		if (mas[i]>=Stonewt(11,0.0))kol++;
		if (mas[i] < smin)smin = mas[i];
		if (mas[i] > smax)smax = mas[i];
	}

	std::cout << "Minimal Stonewt: " << smin << ", Maximal Stonewt: " << smax << ", Count of Stonewt>=11.0 stones: " << kol << std::endl;

	return 0;
}
*/

//7
#include"Complex.h"
using namespace std;

int main()
{
	complex a(3.0, 4.0);
	complex c;

	cout << "Enter a complex number (q to quit):\n";

	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';	
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "a * 3 is " << a * 3 << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}
