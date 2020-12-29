#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
//Input and Output streams

using namespace std;

/*
//1 // input stream

const int MAX = 80;

int main(int arg,char arh[])
{

	char str[MAX];
	cin.get(str, MAX, '$');

	cout << cin.gcount() << endl;


	return 0;
}
*/
/*
//2 output to file, from console with parametr by file

int main(int arg, char *arh[])
{
	ofstream fout;
	fout.open(arh[1], ios_base::out);

	char ch;

	while (cin.get(ch))
	{
		fout << ch;
		if (ch == '\n')break;
	}

	fout.close();

	return 0;
}
*/
/*
//3 // coping information from first file to second file, in consoles

int main(int arg, char* arh[])
{
	ifstream fin;
	fin.open(arh[1], ios_base::in);
	if (!fin.is_open())
	{
		cerr << "Not correct name of file by read\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout;
	fout.open(arh[2], ios_base::out);


	if (!fout.is_open())
	{
		cerr << "Can't open "<<arh[2]<<" file for output.\n";
		exit(EXIT_FAILURE);
	}
	char ch;


	while ((fin.get(ch)) && !fin.eof())
	{
		fout << ch;
	}

	fin.close();
	fout.close();


	return 0;
}
*/
/*
//4 // union file 1 and file 2 in file 3 by line

int main(int arg, char* arh[])
{
	ifstream fin1, fin2;
	fin1.open(arh[1], ios_base::in);
	if (!fin1.is_open())
	{
		cerr << "File " << arh[1] << " is not opened, uncorected name of file.\n";
		exit(EXIT_FAILURE);
	}
	fin2.open(arh[2], ios_base::in);
	if (!fin2.is_open())
	{
		cerr << "File " << arh[2] << " is not opened, uncorected name of file.\n";
		exit(EXIT_FAILURE);
	}
	
	ofstream fout;
	fout.open(arh[3], ios_base::out);
	if (!fout.is_open())
	{
		cerr << "File " << arh[3] << " is not opened.\n";
		exit(EXIT_FAILURE);
	}

	char str[200];

	while (!fin1.eof() || !fin2.eof())
	{
		if (!fin1.eof())
		{
			fin1.getline(str, 200);
			fout << str << " ";
		}
		if (!fin2.eof())
		{
			fin2.getline(str, 200);
			fout << str;
		}
		fout << endl;
	}

	fout.close();
	fin1.close();
	fin2.close();

	return 0;
}
*/
/*
// 5 // 8 task from 16 unit with using fstream

int main()
{

	ifstream fin1("Mat.dat", ios_base::in), fin2("Pat.dat", ios_base::in);
	ofstream fout("matnpat.dat", ios_base::out);

	if (!fin1.is_open()) 
	{
		cerr << "Can't open Mat.dat\n";
		exit(EXIT_FAILURE);
	}
	if (!fin2.is_open())
	{
		cerr << "Can't open Pat.dat\n";
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open())
	{
		cerr << "Can't open matnpat.dat\n";
		exit(EXIT_FAILURE);
	}

	multiset<string> MattListF, PatListF, GeneralListF;
	string name;

	ostream_iterator<string, char> out(fout, "\n");

	while (getline(fin1, name) && !fin1.eof())
	{
		MattListF.insert(name);
	}
	
	while (getline(fin2, name) && !fin2.eof())
	{
		PatListF.insert(name);
	}
	
	set_union(MattListF.begin(), MattListF.end(), PatListF.begin(), PatListF.end(),
		insert_iterator<multiset<string>>(GeneralListF, GeneralListF.begin()));

	copy(GeneralListF.begin(), GeneralListF.end(), out);

	return 0;
}
*/
/*
//6 // 5 task from 14 unit with using fstream(out & in) for making database and can chang this 

#include"emp.h"

const int Max = 3;
enum classkind { Employee, Manager, Fink, HightFink };
int classtype;

int main(void)
{
	employee* pc[Max];

	fstream finout;
	finout.open("Base.dat", ios::in | ios::out);

	if (!finout.is_open())
	{
		cerr << "Please create a file Base.dat\n";
		exit(EXIT_FAILURE);
	}

	/// First start 

	finout.peek();
	if (finout.rdstate() == ios::eofbit)
	{
		finout.clear();

		cout << "Types : Employee - 0, Manager - 1, Fink - 2, HightFink - 3\n";

		for (int i = 0; i < Max; i++)
		{
			cout << "#" << i + 1 << "\n";
			cout << setw(2) << "Enter number of type: ";
			cin >> classtype;

			switch (classtype)
			{
			case Employee:
			{
				pc[i] = new employee;
				pc[i]->SetAll();
			}break;
			case Manager:
			{
				pc[i] = new manager;
				pc[i]->SetAll();
			}break;
			case Fink:
			{
				pc[i] = new fink;
				pc[i]->SetAll();
			}break;
			case HightFink:
			{
				pc[i] = new highfink;
				pc[i]->SetAll();
			}break;
			}
		}

		cout << endl;
		cout.width(17);
		cout << "Name";
		cout.width(15);
		cout << "Last Name";
		cout.width(15);
		cout << "Job";
		cout.width(15);
		cout << "Reports to";
		cout.width(15);
		cout << "In changer of";
		cout << endl;
		

		for (int i = 0; i < Max; i++)
		{ 
			cout << i+1<<":";
			pc[i]->ShowAll();
			cout << endl;
		}
		for (int i = 0; i < Max; i++)
		{
			pc[i]->WriteAll(finout);
			finout << endl;
		}

		finout << flush;
		exit(EXIT_SUCCESS);
	}

	/// After first start
	
	for (int i = 0; i < Max; i++)
	{
		finout >> classtype;
		switch (classtype)
		{
		case Employee:
		{
			string s1, s2, s3;
			finout >> s1>>s2>>s3;
			pc[i] = new employee(s1, s2, s3);
		}break;
		case Manager:
		{
			string s1, s2, s3; int a;
			finout >> s1 >> s2 >> s3 >> a;
			pc[i] = new manager(s1, s2, s3, a);

		}break;
		case Fink:
		{
			string s1, s2, s3, s4;
			finout >> s1 >> s2 >> s3 >> s4;
			pc[i] = new fink(s1,s2,s3,s4);
		}break;
		case HightFink:
		{
			string s1, s2, s3, s4; int a;
			finout >> s1 >> s2 >> s3 >> s4 >> a;
			pc[i] = new highfink(s1,s2,s3,s4,a);
		}break;
		}
	}

	cout << endl;
	cout.width(17);
	cout << "Name";
	cout.width(15);
	cout << "Last Name";
	cout.width(15);
	cout << "Job";
	cout.width(15);
	cout << "Reports to";
	cout.width(15);
	cout << "In changer of";
	cout << endl;

	for (int i = 0; i < Max; i++)
	{
		cout << i + 1 << ":";
		pc[i]->ShowAll();
		cout << endl;
	}
	
	cout << "Enter the record number you wish to changer: (q to quit) ";
	int num;
	while (cin >> num)
	{
		if (num > Max || num <= 0)cout << "Enter corect number: ";
		else {
			cout << "Your selection: \n";
			pc[num - 1]->ShowAll();

			cout << endl;

			cout << "Types : Employee - 0, Manager - 1, Fink - 2, HightFink - 3\n";
			cout << "Number number of type: ";

			cin >> classtype;
			switch (classtype)
			{
			case Employee:
			{
				pc[num - 1] = new employee;
				pc[num - 1]->SetAll();
			}break;
			case Manager:
			{
				pc[num - 1] = new manager;
				pc[num - 1]->SetAll(); 

			}break;
			case Fink:
			{
				pc[num - 1] = new fink;
				pc[num - 1]->SetAll();
			}break;
			case HightFink:
			{
				pc[num - 1] = new highfink;
				pc[num - 1]->SetAll();
			}break;
			}

		}
		cout << "Enter the record number you wish to changer: (q to quit) ";
	}


	for (int i = 0; i < Max; i++)
	{
		cout << i + 1 << ":";
		pc[i]->ShowAll();
		cout << endl;
	}
	
	finout.close();
	finout.open("Base.dat", ios::in | ios::out | ios::trunc);

	if (finout.eof())finout.clear();
	for (int i = 0; i < Max; i++)
	{
		pc[i]->WriteAll(finout);
		finout << endl;
	}

	finout.close();
	return 0;
}
*/

// 7 

void ShowStr(const string&);

struct Store
{
	string str;
	ofstream os;

	Store(ofstream& fout)
	{
		os.open("strings.dat",fout.rdstate());
	}
	
	void operator()(const string& str) 
	{
		int len = str.length();
		os.write(str.data(), len);
	}
	
};

void GetStr(ifstream & os, vector<string>& vec);

int main()
{
	vector<string> vostr;
	string temp;

	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);

	cout << "Here is your input. \n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios::out | ios::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStr(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";

	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const string& str)
{
	cout << str << "\n";
}

void GetStr(ifstream& is, vector<string>& vec)
{
	char ch;
	string s = "";
	while (is.get(ch) && !is.eof())
	{
		s += ch;
		if (ch == ' ')
		{
			vec.push_back(s);
			s = "";
		}
	}

}
