#include<iostream>
#include<array>
#include<string>
#include<cstring>

using namespace std;

/*
//1
int main()
{
	int a, b, sum=0;
	cout << "Enter 2 number and space between numbers: ";
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		sum += i;
	}
	cout << "Sum between number " << a << " and " << b << " is " << sum << endl;
	return 0;
}
*/
/*
//2

const int ArSize = 101;
int main()
{
	array<long double,ArSize> fact;
	fact[0] = fact[1] = 1LL;

	for (int i = 2; i < ArSize; i++)
	{
		fact[i] = i * fact[i - 1];
	}

	for (int i = 2; i < ArSize; i++)
	{
		cout << i << "! = " << fact[i] << endl;
	}

	return 0;
}
*/
/*
//3

int main()
{
	int x,sum=0;
	
	do
	{
		cout << "Enter your new money: ";
		cin >> x;
		sum += x;
		cout << "Your all money: " << sum<<endl;
	} while (x != 0);
	

	return 0;
}
*/
/*
//4
struct Bank
{
	const double procent;
	double balans;
};

int main()
{
	Bank Kleo = { 0.05, 100 }, Dafna = { 0.1, 100 };

	int age = 1, DafnaStart = Dafna.balans;

	for (; Kleo.balans <= Dafna.balans; age++)
	{
		Dafna.balans += Dafna.procent * DafnaStart;
		Kleo.balans += Kleo.procent * Kleo.balans;


		cout << "Current balans on "<<age<<" year. Kleo balans: " << Kleo.balans << ", Dafna balans: " << Dafna.balans << endl;
	}

	cout << "Age: " << age-1 << endl;

	return 0;
}
*/
/*
//5
struct Bank
{
	const double procent;
	double balans;
};

int main()
{
	string months[12];
	int count[12], summry = 0;

	for (int i=0; i <12; i++)
	{
		cout << "Enter month: ";
		cin >> months[i];
		cout << "Enter sum of count books by this month: ";
		cin >> count[i];
		summry += count[i];
	}

	cout << "Count of all books by this year: " << summry << endl;

	return 0;
}
*/
/*
//6

int main()
{
	string months[12];
	int count[3][12], summry[4] = {0};

	for (int j = 0; j < 3; j++) {
		cout << endl;
		cout << "Year" << j + 1 << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << "Enter month: ";
			cin >> months[i];
			cout << "Enter sum of count of sold books by this month: ";
			cin >> count[j][i];
			summry[j] += count[j][i];
		}
		summry[3] += summry[j];
		cout << "Count of sold all books by "<<j+1<<" year: " << summry[j] << endl;
	}

	cout << "Count of sold all books by three years: " << summry[3] << endl;

	return 0;
}
*/
/*
//7

int main()
{
	struct car
	{
		string name;
		int year;
	};

	int count;
	cout << "How do you have cars? Enter: ";
	cin >> count;

	car* collection = new car[count];

	for (int i = 0; i < count; i++)
	{
		cout << "Auto #" << i + 1 << ": \n";
		cout << "Name of car:";
		cin.get();
		getline(cin, collection[i].name);
		
		cout << "Year of car: ";
		cin >> collection[i].year;
	}

	cout << "Your collection: \n";

	for (int i = 0; i < count; i++)
	{
		cout << collection[i].year<<" "<<collection[i].name<<endl;
	}

	return 0;
}
*/
/*
//8

int main()
{
	char word[80];
	int count = 0;

	cout << "Enter words, for finished enter word \"done\" :\n";

	do {
		cin >> word;
		count++;
	} while (strcmp(word,"done"));

	cout << "You entered " << count - 1 << " words";

	return 0;
}*/
/*
//9

int main()
{
	string word;
	int count = 0;

	cout << "Enter words, for finished enter word \"done\" :\n";

	do {
		cin >> word;
		count++;
	} while (word != "done");

	cout << "You entered " << count - 1 << " words";

	return 0;
}
*/
/*
//10

int main()
{
	int n;
	cout << "Enter count of string: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= n - i - 1)
			{
				cout << "*";
			}
			else cout << ".";
		}
		cout << endl;
	}

	return 0;
}

*/

