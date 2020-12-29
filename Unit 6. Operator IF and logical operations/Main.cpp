#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;
/*
//1
int main()
{
	char ch;
	cin.get(ch);
	while (ch!='@')
	{
		if (isgraph(ch) && !isdigit(ch))
		{
			if (islower(ch))ch = toupper(ch);
			else if (isupper(ch))ch = tolower(ch);

			cout << ch;
		}
		cin >> ch;
	}
	return 0;
}*/
/*
//2
const int Max = 10;

int main()
{
	int call = 0,hiet = 0;
	double massiv[Max],ser=0;

	
	for (;call<Max && cin>>massiv[call];call++)
	{
		ser += massiv[call];
	}
	ser /= call;
	for (int i=0; i<call; i++)
	{
		if (massiv[i] > ser)hiet++;
	}

	cout << "Ser = " << ser << ",massiv element > ser count is " << hiet << endl;

	return 0;
}*/
/*
//3

int main()
{
	cout << "Pleas enter one of the following choise: \n";
	cout << "c) carnivore p) pianist\n"<<"t) tree g) game\n";
	
	char ch;

	cin >> ch;

	while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g') {
		cout << "Please enter a c, p, t or g: ";
		cin >> ch;
	}
	cout << "A maple is a ";

	switch (ch)
	{
	case 'c': cout << "carnivore";
		break;
	case 'p': cout << "pianist";
		break;
	case 't': cout << "tree";
		break;
	case 'g': cout << "game";
		break;
	}
	return 0;
}
*/
/*
//4
const int strsize = 60;
const int Max=4;

struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference; // 0 - name,  1 - title, 2- bop
};

int main()
{
	bop* massiv = new bop[Max]{
		{"Nicky","Pissy","Bop0",1},
		{"Sally","Kissy","Bop1",0},
		{"Denny","Sissy","Bop2",0},
		{"Penny","Mouth","Bop3",2},
	};

	cout << "Benevolent Order of Programmers Report: \n";
	cout << "a) display by name \tb) display by title\n" << "c) display by bopname \td) display by prefernce\nq) quit\n";
	cout << "Enter your choise: ";

	int z = 0;

	char ch;

	cin >> ch;

	while (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch != 'q') {

		for (int i = 0; i < Max; i++)
		{
			if (ch == 'a' || (massiv[i].preference == 0 && ch=='d'))cout << massiv[i].fullname << endl;
			else if (ch == 'b' || (massiv[i].preference == 1 && ch == 'd'))cout << massiv[i].title << endl;
			else if (ch == 'c' || (massiv[i].preference == 2 && ch == 'd'))cout << massiv[i].bopname << endl;
		};

		cout << "Next choice: ";
		cin >> ch;
	}
	cout << "Bye!";

	
	return 0;
}*/
/*
//5

int main()
{
	int trap = 0,nal=0,grab=0;//5000 - 0% , +10000 - 10%, +20000 - 15%, >35000 - 20%

	while (cin >> trap && trap >= 0)
	{
		nal += trap;
		if (nal <= 5000)grab = 0;
		else if (nal <= 15000)grab = 10000 * 0.1;
		else if (nal <= 35000)grab = 10000 * 0.1 + 20000 * 0.15;
		else grab = (nal - 35000)*0.2 + 10000 * 0.1 + 20000 * 0.15;
	}

	cout << "Nalog is : " << grab<< endl;

	return 0;
}
*/
/*
//6

struct SocietyOfProtectionInfluentialPersons
{
	char name[80];
	double donation;
};

typedef SocietyOfProtectionInfluentialPersons SOPIP;

int main()
{
	int CountPersons;
	bool none = true;

	cout << "Enter count of michination persons: ";
	cin >> CountPersons;

	SOPIP* persons = new SOPIP[CountPersons];

	for (int i=0;i<CountPersons;i++)
	{
		cin.get();
		cout << "Enter name of michination: ";
		cin.getline(persons[i].name,80);
		cout << "Enter his donation: ";
		cin >> persons[i].donation;
		
		if (persons > 0)none = false;
	}

	if(!none)cout << "\n\n Grand Patrons\n\n";

	for (int i = 0; i < CountPersons; i++)
	{
		if(persons[i].donation>=10000)cout << persons[i].name << " " << persons[i].donation<<"$\n";
	}

	if(!none)cout << "\n Patrons\n\n";

	for (int i = 0; i < CountPersons; i++)
	{
		if (persons[i].donation < 10000 && persons[i].donation != 0)cout << persons[i].name << " " << persons[i].donation<<"$\n";
	}

	if (none) cout << "none\n";

	return 0;
}
*/
/*
//7

int main()
{
	cout << "Enter words (q to quit): \n";
	int vowels = 0, consonants = 0, other = 0;
	string word;

	while (cin>>word) {
		if (word == "q")break;
		if (isalpha(word[0])) {
			
			switch (word[0])
			{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'y':
			case 'Y':
			case 'u':
			case 'U':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'j':
			case 'J':
				vowels++;
				break;
			default : consonants++;
			}
		}
		else other++;
	}

	cout << vowels << " words beginning with vowels\n";
	cout << consonants << " words beginning with consonants\n";
	cout << other << " other words\n";

	return 0;
}
*/
/*
// 8

int main()
{
	ifstream fromFile;
	fromFile.open("texte.txt");

	int count = 0;
	char ch;
	
	while (fromFile.get(ch))
	{
		count++;
	}

	cout << "Count of chars in file \" texte.txt \" is " << count<<endl;

	return 0;
}
*/
/*
//9

struct SocietyOfProtectionInfluentialPersons
{
	char name[80];
	double donation;
};

typedef SocietyOfProtectionInfluentialPersons SOPIP;

int main()
{
	ifstream fromFile;
	fromFile.open("Minstr.txt");

	int CountPersons;
	bool none = true;

	cout << "Enter count of michination persons: ";
	fromFile >> CountPersons;

	SOPIP* persons = new SOPIP[CountPersons];

	for (int i=0;i<CountPersons;i++)
	{
		fromFile.get();
		fromFile.getline(persons[i].name,80);
		fromFile >> persons[i].donation;

		if (persons > 0)none = false;
	}

	if(!none)cout << "\n\n Grand Patrons\n\n";

	for (int i = 0; i < CountPersons; i++)
	{
		if(persons[i].donation>=10000)cout << persons[i].name << " " << persons[i].donation<<"$\n";
	}

	if(!none)cout << "\n Patrons\n\n";

	for (int i = 0; i < CountPersons; i++)
	{
		if (persons[i].donation < 10000 && persons[i].donation != 0)cout << persons[i].name << " " << persons[i].donation<<"$\n";
	}

	if (none) cout << "none\n";

	return 0;
}
*/
