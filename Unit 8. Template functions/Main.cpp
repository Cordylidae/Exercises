#include<iostream>
#include<string>
#include<cctype>
using namespace std;

/*
//1
static int kol = 0;
void DrawS(const string & s, int i = 0);

int main()
{
	string draw;
	cout << "Enter string of text: ";
	cin >> draw;
	
	DrawS(draw, 2);
	DrawS(draw);
	DrawS("Jopa", 1);
	DrawS(draw, 0);
	DrawS(draw, 4);

	return 0;
}

void DrawS(const string & s, int i)
{
	if (i)
	{
		for (int j = 0; j < kol; j++)
			cout << s << endl;
	}
	else cout<< s << endl;
	cout << endl;
	kol++;
}*/
/*
//2

struct CandyBar
{
	const char * name;
	double weight;
	int kkal;
}LionBar;

void Bar(CandyBar&,const char* str = "Millennium Munch", double weght = 2.85, int kkal = 350);
void ShowBar(const CandyBar&);


int main()
{
	char kl[] = "Sneaks";

	char* s = new char;
	cin.getline(s,80);

	Bar(LionBar, kl, 2.3);
	ShowBar(LionBar);

	cout << endl;

	Bar(LionBar, s, 2.5);
	ShowBar(LionBar);

	cout << endl;

	Bar(LionBar);
	ShowBar(LionBar);

	return 0;
}

void Bar(CandyBar& bar,const char* str, double weght, int kkal)
{
	LionBar.name = str;
	LionBar.weight = weght;
	LionBar.kkal = kkal;
}

void ShowBar(const CandyBar& bar)
{
	cout << "Name of bar: " << bar.name<<endl;
	cout << "Weight of bar: " << bar.weight << endl;
	cout << "Kkal of bar: " << bar.kkal << endl;
}

*/
/*
//3 

void Upper(string &);
bool onlyQ(string&);

int main()
{
	string str;
	cout << "Enter a string (q to quit): ";
	while (getline(cin,str))
	{
		if (onlyQ(str))break;
		Upper(str);
		cout << "Next string (q to quit): ";
	}

	cout << "Bye";

	return 0;
}

void Upper(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))str[i]=toupper(str[i]);
	}
	cout << str << endl;
}

bool onlyQ(string& str)
{
	int kol = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == 'q')kol++;
	}
	if (kol == 1)return true;
	else return false;
}
*/
/*
//4

#include<iostream>
using namespace std;
#include<cstring>

struct stringy {
	char* str;
	int ct;
};

void set(stringy &,char *);
void show(const stringy &, int i = 1);
void show(const char *, int i = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	cout << beany.ct << endl;

	return 0;
}

void set(stringy& strin, char* str)
{
	strin.str = str;
	strin.ct = 0;
	while (*str)
	{
		strin.ct++;
		str++;
	}
}
void show(const stringy& strin, int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << strin.str<<endl;
	}
}
void show(const char* str, int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << str<<endl;
	}
}
*/
/*
//5

template<typename T>
T max5(T mas[]);

int main()
{
	double masD[5];
	cout << "Enter 5 double numbers: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> masD[i];
	}
	int masI[5];
	cout << "Enter 5 integer numbers: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> masI[i];
	}

	cout << "\nMaximum from 5 double numbers is " << max5(masD) << endl;
	cout << "\nMaximum from 5 integer numbers is " << max5(masI) << endl;

	return 0;
}

template<typename T>
T max5(T mas[])
{
	T max = mas[0];

	for (int i = 1; i < 5; i++)
		if (max < mas[i])max = mas[i];

	return max;
}
*/
/*
//6

int sizeC(char*);

template<typename T>
T maxn(T[], int);

template<>char* maxn(char* [],int);

int main()
{
	int n;
	
	cout << "Enter count of integer numbers: ";
	cin >> n;
	cout << "Enter integer numbers: ";
	int * masI = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> masI[i];
	}

	cout << "Max from massiv integers is: " << maxn(masI, n) << endl;

	cout << "Enter count of double numbers: ";
	cin >> n;
	cout << "Enter double numbers: ";
	double* masD = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> masD[i];
	}

	cout << "Max from massiv doubles is: " << maxn(masD, n) << endl;


	char* str[] =
	{
		(char*)"Hope",
		(char*)"Less",
		(char*)"Fucks",
		(char*)"This",
		(char*)"World"
	};
	cout << "Max from massiv strings is: " << maxn(str, 5)<<endl;

}

int sizeC(char* str)
{
	int i = 0;
	for (; str[i]; i++){}
	return i;
}

template<typename T>
T maxn(T mas[], int n)
{
	T max = mas[0];
	for (int i = 1; i < n; i++)
	{
		if (max < mas[i])max = mas[i];
	}
	return max;
}

template<> char* maxn(char* mas[], int n)
{
	char* max = mas[0];
	int maxS = sizeC(mas[0]);

	for (int i = 1; i < n; i++)
	{
		int sM = sizeC(mas[i]);

		if (maxS < sM) {
			maxS = sM;
			max = mas[i];
		}

	}

	return max;
}
*/
/*
// 7

template<typename T>
T SumArray(T arr[], int n);  //shabon A

template<typename T>
T SumArray(T * arr[], int n); // shablon B

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	int things[6] = { 13,12,42,21,12,44 };
	debts mr_E[3] =
	{
		{"Ima Wolfe",2400.0},
		{"Ura Exra",1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3]; 

	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}
	cout << "Lisitng Mr. E's sum of all things is:\n";
	cout<< SumArray(things,6)<<endl;

	cout << "Lisitng Mr. E's sum of all debts is :\n";
	cout<<SumArray(pd, 3) << endl;

	return 0;
}

template<typename T>
T SumArray(T arr[], int n) 
{
	T sum = 0;
	//cout << "template A\n";
	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

template<typename T>
T SumArray(T* arr[], int n) 
{
	T sum = 0;
	//cout << "template B\n";
	for (int i = 0; i < n; i++)
		sum+= *arr[i];

	return sum;
}

*/
