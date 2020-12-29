#include<iostream>

/*
// 1
#include"Wine.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.get(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;
	Wine holding(lab, yrs);

	holding.GetBottles();
	holding.Show();

	const int YRS = 3;

	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48,60,72 };
	
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye\n";

	return 0;
}
*/
/*
// 2
#include"Wine2.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.get(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;
	Wine2 holding(lab, yrs);

	holding.GetBottles();
	holding.Show();

	const int YRS = 3;

	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48,60,72 };

	Wine2 more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye\n";

	return 0;
}
*/
/*

//3

#include"QueueTp.h"
#include"Worker.h"
#include<cstring>

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	QueueTp<Worker*> lolas(SIZE);
	Worker* wk;

	int ct;

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter, s: singer, "
			<< "t: singing waiter, q: quit \n";
		
		cin >> choice;

		cin.get();

		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter enter a: w, s, t , or q: ";
			cin >> choice;
		}

		if (choice == 'q')break;
		
		switch (choice)
		{
		case 'w': {
			wk = new Waiter;
			wk->Set();
			lolas.enqueue(wk);
		}break;
		case 's': {
			wk = new Singer;
			wk->Set();
			lolas.enqueue(wk);
		}break;
		case 't': {
			wk = new SingingWaiter;
			wk->Set();
			lolas.enqueue(wk);
		}break;
		}

		
	}
	cout << "\nHere is your staff:\n";
	int i;

	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas.dequeue(wk);
		wk->Show();
	}

	cout << "Bye.\n";

	return 0;
}

*/
/*
//4 
#include"Person.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	
	Person* lolas[SIZE];
	

	int ct;

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n"
			<< "g: gunslinger, p: poker player, "
			<< "b: bad dude, q: quit \n";

		cin >> choice;

		cin.get();

		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter enter a: g, p, b, or q: ";
			cin >> choice;
		}



		if (choice == 'q')break;

		std::string name;
		cout << "Enter name: ";
		getline(cin,name);

		std::string lname;
		cout << "Enter lastname: ";
		getline(cin, lname);


		switch (choice)
		{
		case 'g': {

			int n;
			cout << "Enter count of nasechok: ";
			cin>>n;

			lolas[ct] = new Gunslinger(name,lname,n);
		}break;
		case 'p': {
			lolas[ct] = new PokerPlayer(name, lname);
		}break;
		case 'b': {
			int n;
			cout << "Enter count of nasechok: ";
			cin >> n;

			lolas[ct] = new BadDude(name, lname, n);
		}break;
		}


	}
	
	int i;
	
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];
	
	cout << "\nBye.\n";

	return 0;
}
*/

//5

#include"emp.h"
using namespace std;


int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	
	cout << "Press a key for next phrase:\n";

	cin.get();

	highfink hf2;
	hf2.SetAll();

	cout << endl;

	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };

	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();


	return 0;
}