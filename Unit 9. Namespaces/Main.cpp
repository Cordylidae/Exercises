#include<iostream>
#include<string>
#include<cstring>
using namespace std;



/*
///Test
namespace {
	int y = 5;
}
int main()
{
	cout << y << endl;
	int y = 9;
	{
		int y = 6;
		cout << y << endl;
	}
	cout << y << endl;
	return 0;

}
*/

/*
//1

#include"golf.h"

int main()
{
	int n=0;
	golf mas[5];

	setgolf(mas[0],"Alloha Ice", 86);
	setgolf(mas[1], "Cacun Ice", 76);

	for (; n < 5; n++)
	{
		if(n>=2)if (!setgolf(mas[n]))break;
	}

	handicap(mas[0],85);
	if(n>=2)handicap(mas[2], 87);

	for (int i=0; i < n; i++)
	{
		showgolf(mas[i]);
	}
	return 0;
}
*/
/*
// 2 
void strcount(string* str);


int main() 
{
	string input;
	char next;
	
	cout << "Enter a line: \n";
	getline(cin, input);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(&input);
		cout << "Enter next line (empty line to quit): \n";
		getline(cin, input);
		if (input == "")break;
	}
	cout << "Bye!\n";

	return 0;
}

void strcount(string* str)
{
	static int total = 0;
	int count = 0;
	cout << "\"" << *str << "\" contains ";

	for (; count < str->size(); count++);
		
	total += count;
	cout << count << " characters\n";
	cout << total << " total characters\n";
}
*/
/*
//3 
#pragma warning(disable: 4996)

struct chuff
{
	char dross[200];
	int slag;
};

char buffer1[5000];
void* buffer2 = new chuff[2];

void initChuff(chuff&, char[], int&);
void showChuff(chuff&);

int main()
{
	chuff *mas = new (buffer1) chuff[2];
	chuff* mas2 = new (buffer2) chuff[2];

	for (int i = 0; i < 2; i++)
	{
		int sl;
		char str[200];

		cout << "Enter dross: ";
		cin.getline(str,200);
		cout << "Enter slag: ";
		cin >> sl;
		cin.get();

		initChuff(mas[i], str,sl);
		initChuff(mas2[i], str, sl);
	}

	for (int i = 0; i < 2; i++)
	{
		showChuff(mas[i]);
		showChuff(mas2[i]);
	}

	cout << sizeof(buffer1) << endl;
	cout << sizeof(buffer2) << endl;
}

void initChuff(chuff &chuf, char drossy[], int &slag)
{
	chuf.slag = slag;
	strcpy(chuf.dross,drossy);

}

void showChuff(chuff& chuf)
{

	static int count = 1;
	
	cout <<'#'<<count<<" Chuff dross: "<< chuf.dross<< ", chuff slag: "<< chuf.slag <<", bytes : "<< sizeof(chuf) <<endl;
	
	count++;
}
*/
/*
//4
#include"Sales.h"

int main()
{
	SALES::Sales sales[2];

	double ar[] = { 2.5, 5.4, 2.5 };

	SALES::setSales(sales[0]);
	SALES::setSales(sales[1], ar, sizeof(ar)/sizeof(double));

	for (int i = 0; i < 2; i++)
	{
		SALES::showSales(sales[i]);
	}

	return 0;
}
*/