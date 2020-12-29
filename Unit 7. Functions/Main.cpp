#include<iostream>
#include<array>
#include<string>
using namespace std;

/*
//1
double sergarm(double x,double y)
{
	return 2.0 * x * y / (x + y);
}

int main()
{

	double a, b;
	
	cout << "Enter 2 numbers for Midile Garmonii(dificil by zero): ";
	cin >> a >> b;

	while (a != 0 && b != 0)
	{
		cout << "Midile Garmonii by " << a << " and " << b << " is " << sergarm(a,b) << endl;
		cout << "Enter next 2 numbers for Midile Garmonii(dificil by zero): ";
		cin >> a >> b;
	}


	return 0;
}
*/
/*
//2

int Input(double* massiv);
double Ser(double* massiv, int count);
void Output(double* massiv);

int main()
{
	double * massiv = new double[10];

	Output(massiv);

}

void Output(double* massiv)
{
	int count = Input(massiv);

	if (count == 0) {
		cout << "Nothing result";
	}
	else {
		cout << count<< " results of matches and them ser result: ";
		for (int i = 0; i < count; i++)
		{
			cout << massiv[i] << " ";
		}
		cout << Ser(massiv,count) << endl;
	}
}

double Ser(double *massiv,int count)
{
	double ser = 0;

	for (int i = 0; i < count; i++)
		ser += massiv[i];

	return ser/count;
}

int Input(double* massiv)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter your result or enter number < 0 for quit: ";
		cin >> massiv[i];
		if (massiv[i] > 0)count++;
		else break;
	}
	return count;
}
*/
/*
//3 

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};


void allBox(box Box);
void boxVolume(box* Box);

int main()
{
	box Box{ "LoliBox", 2.0, 1.0, 3.0 };
	allBox(Box);


	return 0;
}

void allBox(box Box)
{
	boxVolume(&Box);

	cout <<"Box maker: "<< Box.maker << endl;
	cout <<"Box height: "<< Box.height << endl;
	cout <<"Box length: "<< Box.length << endl;
	cout <<"Box width: "<< Box.width << endl;
	cout <<"Box volume: "<< Box.volume << endl;
}

void boxVolume(box* Box)
{
	Box->volume = (Box->height) * (Box->width) * (Box->length);
}
*/
/*
//4
long double probablility(unsigned numbers, unsigned picks , unsigned mega);

int main()
{
	double total, choices, megabox;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed from common field and total number of choices on the field meganumbers:\n";
	while ((cin >> total >> choices >> megabox) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probablility(total , choices, megabox);
		cout << " of winning.\n";
		cout << "Next three numbers (q to quit): ";
	}
	cout << "bye!\n";
	return 0;
}
long double probablility(unsigned numbers, unsigned picks, unsigned mega)
{
	long double r = 1.0;
	long double result = 1.0;
	long double n;
	unsigned p;
	
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result*mega; 
}*/
/*
//5
long double fact(long double a);

int main()
{
	long double n;
	cout << "Enter number of what you want factorial: ";
	while (cin >> n)
	{
		cout << "Factorial by "<<n<<"! is "<<fact(n);
		cout << "Next number(q to quit): ";
	}
	return 0;
}
long double fact(long double a)
{
	if (a == 0) return 1;
	else a *= fact(a - 1);

	return a;
}
*/
/*
//6
int Fill_array(double [],int);
void Show_array(double [], int);
void Reverse_array(double [], int);

int main()
{
	double mas[10];int size = 10;

	Show_array(mas,size);

	return 0;
}

void Show_array(double arr[],int size)
{
	cout << "Enter 10 numbers or less: ";
	
	size = Fill_array(arr, size);
	
	Reverse_array(arr, size);

	cout << "Massiv reversed except first and last: \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
}

int Fill_array(double arr[], int size)
{
	int kol = 0;
	for (int i = 0; i<size && cin >> arr[i]; i++) { kol = i; }
	
	return kol+1;
}

void Reverse_array(double arr[], int size)
{
	for (int i = 1; i <= (size - 1 )/ 2; i++)
	{
		double t=arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = t;
	}
}
*/
/*
//7
const int Max = 5;

double * fill_array(double * start, double *finish);
void show_array(const double * start,double *finish);
void revalue(double r, double * start,double *finish);

int main()
{
	double properties[Max];
	double *fin = fill_array(properties, properties + Max-1);
	show_array(properties, fin);
	if (fin - properties > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, fin);
		show_array(properties, fin);
	}
	cout << "Done.\n";
	cin.get();


	return 0;
}
double* fill_array(double * start,double * fin)
{
	double temp;
	int kol = 0;
	double * i  = start;
	for (; i <= fin; i++,kol++)
	{
		cout << "Enter valur #" << (kol + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated. \n";
			break;
		}
		else if (temp < 0)
			break;
		*i = temp;
	}
	return i;
}
void show_array(const double * start, double * fin)
{
	int kol = 0;
	for (const double * i = start; i < fin; i++, kol++)
	{
		cout << "Propety #" << (kol + 1) << ": $";
		cout << *i << endl;
	}
}
void revalue(double r, double * start, double * fin)
{
	for (double * i = start; i < fin; i++)
	{
		*i *= r;
	}
}
*/
/*
//8a
const int Seasons = 4;
const char * Snames[] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double *pa);
void show(const double *pa);

int main()
{
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
	return 0;
}

void fill(double* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}

void show(const double *  da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";

	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
*/
/*
//8b



const int Seasons = 4;
const char* Snames[] =
{ "Spring", "Summer", "Fall", "Winter" };

struct expenses
{
	double* ex = new double[Seasons];
};

void fill(expenses *pa);
void show(expenses pa);

int main()
{

	expenses myExpenses;
	fill(&myExpenses);
	show(myExpenses);
	return 0;
}

void fill(expenses *pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->ex[i];
	}
}

void show(expenses da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";

	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da.ex[i] << endl;
		total += da.ex[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
*/
/*
//9

const int Slen = 30;

struct student
{
	char fullname[Slen];
	char hobby[Slen];
	int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	
	int class_size;
	cin >> class_size;
	
	cin.get();

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);

	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);

	delete[] ptr_stu;
	cout << "Done!\n";

	return 0;
}

int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Enter data for student #" << i + 1 << endl;
		cin.getline(pa[i].fullname, Slen);
		
		char* p = pa[i].fullname;
		bool space = true;
		while (*p!='\0')
		{
			if (*p != ' ') { space = false; break; }
			p++;
		}
		if (space)break;

		cin.getline(pa[i].hobby, Slen);
		cin >> pa[i].ooplevel;
		cin.get();
	}
	return i;
}


void display1(student st)
{
	cout << "Simple Student name: " << st.fullname << ", student hobbies: " << st.hobby << ", student level: " << st.ooplevel<<endl;
}

void display2(const student* ps)
{
	cout << "Pointer Student name: " << ps->fullname << ", student hobbies: " << ps->hobby << ", student level: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	cout << endl;
	const student* i = pa;
	for(int kol=0;kol<n;kol++)
		cout <<"# "<<kol+1<< " student name: " << i[kol].fullname << ", student hobbies: " << i[kol].hobby << ", student level: " << i[kol].ooplevel << endl;
}
*/

//10

double calculate(double, double, double (*func)(double c, double d));

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);



int main()
{
	double (*funcs[4])(double, double) = { add, subtract, multiply, divide };

	while (true)
	{
		
		char c;
		double a, b;
		cout << "Enter two numbers and action\n"
			"a - to add\n"
			"s - to subtract\n"
			"m - to multiply\n"
			"d - to divide\n"
			"q - to quit\n";

		if(!(cin >> a >> b >> c))break;

		switch (c)
		{
			case 'a':
				cout << "Result is " << calculate(a, b, funcs[0]) << endl << endl;
				break;
			case 's':
				cout << "Result is " << calculate(a, b, funcs[1]) << endl << endl;
				break;
			case 'm':
				cout << "Result is " << calculate(a, b, funcs[2]) << endl << endl;
				break;
			case 'd':
				cout << "Result is " << calculate(a, b, funcs[3]) << endl << endl;
				break;
			default: {
				cout << " Done! ";
				return 0;
			}
		}
	}
	return 0;
}


double calculate(double a, double b, double (*func)(double c, double d))
{
	return func(a, b);
}
double add(double a, double b)
{
	return a + b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double divide(double a, double b)
{
	return a / b;
}

/*
// proverochka
int replace(char* str, char c1, char c2);

int main()
{
	char mas[] = "Geed Pepa";
	cout<<replace(mas, 'e','o')<<endl;
	return 0;
}

int replace(char* str, char c1, char c2)
{
	int kol = 0, i = 0;
	while (str[i])
	{
		if (str[i] == c1) { str[i] = c2; kol++; }
		i++;
	}
	cout << str << endl;
	return kol;
}*/