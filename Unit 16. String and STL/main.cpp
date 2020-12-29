#include<iostream>
#include<string>
#include<cctype>
#include<ctime>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<queue>
#include<set>
#include<list>
#include<memory>
#include"Customer.h"
///////STL/////////

using namespace std;

/*

//1,2 // practice with string, string is Palindrom without punctuation? 

bool Palindrom(string & s);
void ToColaps(string& s);

int main()
{
	string s;
	cout << "Enter string: ";
	cin >> s;

	ToColaps(s);

	cout << "Your stirng is Palindrom, ";
	if (Palindrom(s))cout << "YES!!!\n";
	else cout << "NO.\n";

	cout << s << endl;

	return 0;
}

void ToColaps(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (ispunct(s[i])) { s.erase(s.begin() + i, s.begin() + i + 1); }
		if (isspace(s[i])) { s.erase(s.begin() + i, s.begin() + i + 1); }
		s[i] = tolower(s[i]);
	}
}

bool Palindrom(string& s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i-1])return false;
	}
	return true;
}

*/
/*
//3 //hangman

void Upload(vector<string>*);


int main()
{
	srand(time(0));
	
	vector<string> vec;
	Upload(&vec);

	char play;

	cout << "Will you play a word game? <y/n> ";
	cin >> play;

	play = tolower(play);

	while (play == 'y')
	{
		string target = vec[rand() % vec.size()];
		string attemp(target.size(), '-');
		string badchars;
		int guesses = 6;

		cout << "Guesse my secret word. It has " << attemp.size()
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesse. \n";

		cout << "Your word: " << attemp << endl;
		
		while (guesses > 0 && attemp != target)
		{
			char letter;
			cout << "Guess a latter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attemp.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}

			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attemp[loc] = letter;

				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attemp[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attemp << endl;
			if (attemp != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}

		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n>";
		cin >> play;

		play = tolower(play);

	}
	cout << "Bye\n";
	return 0;
}

void Upload(vector<string>* vec)
{
	ifstream Fin("Words.txt");
	
	string s;
	
	while (Fin >> s)
		vec->push_back(s);

}
*/
/*
//4,5 using STL fuction for massive with any object who use operator<

template<class T>
int Sort_Uniqeu(T ar[], int n);

int main()
{	
	long mas[10] = { 5,3,1,2,3,5,6,2,2,4 };
	int count = Sort_Uniqeu(mas,10);

	cout << "Like a set(nearly): ";
	for (int i = 0; i < count; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	cout << "But: ";
	for (int i = 0; i < 10; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl<<endl;


	string s[4] = { "unicorn","popcorn","unic","unicorn"};

	count = Sort_Uniqeu(s, 4);

	cout << "Like a set(nearly): ";
	for (int i = 0; i < count; i++)
	{
		cout << s[i]<<" ";
	}
	cout << endl;

	cout << "But: ";
	for (int i = 0; i < 4; i++)
	{
		cout << s[i]<<" ";
	}
	cout << endl;

	return 0;
}

template<class T>
int Sort_Uniqeu(T ar[], int n)
{
	sort(ar, ar + n);
	
	return unique(ar, ar + n) - ar;
}
*/
/*
// 6 using STL queue for task 5,6 from Unit 12 C++ 

const int min_Per_Hr = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of first queue and second queue: ";
	int MaxQs, MaxQs2;
	cin >> MaxQs >> MaxQs2;
	queue<Item> line, line2;
	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	long cyclelimit = min_Per_Hr * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;

	double min_per_cust;
	min_per_cust = min_Per_Hr / perhour;

	Item temp, temp2;
	long turnaways = 0;
	long customers = 0;
	long served = 0;

	long sum_line = 0;

	int wait_time = 0;
	int wait_time2 = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.size()==MaxQs && line2.size()==MaxQs2)
			{
				turnaways++;
			}
			else if (line.size() < line2.size() && line.size()<MaxQs)
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
			else if(line2.size()<MaxQs2)
			{
				customers++;
				temp2.set(cycle);
				line2.push(temp2);
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;

		if (wait_time2 <= 0 && !line2.empty())
		{
			line2.pop();
			wait_time2 = temp2.ptime();
			line_wait += cycle - temp2.when();
			served++;
		}
		if (wait_time2 > 0)
			wait_time2--;

		sum_line += line.size();
		sum_line += line2.size();
	}


	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << " turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " avarage wait time: " << (double)line_wait / served << " minutes\n";
	}
	else cout << "No customers!\n";

	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
*/
/*
// 7 // simulation loto with STL vector

vector<int> Lotto(int, int);

int main()
{
	srand(time(0));

	int n, k;
	
	cout << "Enter count of Numbers on Lotto: ";
	cin >> n;
	cout << "Enter count of Winners number: ";
	cin >> k;


	vector<int> winners;
	winners = Lotto(n, k);

	cout << "\nWinners number by range 1 - " << n << ":\n ";

	for (int i = 0; i < winners.size(); i++)
		cout << winners[i] << " ";
	cout << endl;

	return 0;
}

vector<int> Lotto(int n, int k)
{
	vector<int> vec;

	for (int i = 1; i <= n; i++)
		vec.push_back(i);

	random_shuffle(vec.begin(), vec.end());
	
	vec.resize(k);

	return vec;
}
*/
/*
//8 // STL multiset for friends party sorted list 

int main()
{
	multiset<string> MattListF,PatListF,GeneralListF;
	cout << "Matt friend's (all for finished):\n";//(firstName lastName)
	string name;

	ostream_iterator<string, char> out(cout, "\n");

	while (getline(cin,name) && name!="all")
	{
		MattListF.insert(name);
	}
	cout << endl;

	copy(MattListF.begin(), MattListF.end(), out);

	cout << "\nPat friend's (all for finished):\n";//(firstName lastName)

	while (getline(cin, name) && name != "all")
	{
		PatListF.insert(name);
	}
	cout << endl;


	copy(PatListF.begin(), PatListF.end(), out);

	cout << "\nGeneral List of friends Matt and Pat: \n";
	
	set_union(MattListF.begin(), MattListF.end(), PatListF.begin(), PatListF.end(),
		insert_iterator<multiset<string>>(GeneralListF, GeneralListF.begin()));
	
	copy(GeneralListF.begin(), GeneralListF.end(), out);


	return 0;
}
*/
/*
//9  // speedes sorting

inline double Times(clock_t start, clock_t end)
{
	return (double)(end - start) / CLOCKS_PER_SEC;
}

void Rand(int n);

int main()
{
	srand(time(0));

	vector<int> vi0(10e6), vi;
	list<int> li;

	for_each(vi0.begin(), vi0.end(), Rand);

	vi.insert(vi.begin(), vi0.begin(), vi0.end());
	li.insert(li.begin(), vi0.begin(), vi0.end());

	//vector sort//

	clock_t start = clock();

	sort(vi.begin(), vi.end());

	clock_t end = clock();
	cout << "Need time for only sorted big vector: "<<Times(start,end)<<endl;

	//list sort//

	start = clock();

	li.sort();

	end = clock();
	cout << "Need time for only sorted big list: " << Times(start, end)<<endl;

	//combine sort list->vector , sort vector, vector->list
	
	copy(vi0.begin(), vi0.end(), li.begin());

	start = clock();

	copy(li.begin(), li.end(), vi.begin());
	

	sort(vi.begin(), vi.end());

	copy(vi.begin(), vi.end(), li.begin());

	end = clock();
	cout << "Need time for mixed sorting list big vector: " << Times(start, end)<<endl;


	return 0;
}

void Rand(int n) { n=rand(); }
*/
/*
// 10 // shared_ptr

struct Review
{
	string title;
	int rating;
	int price;
};

bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool worseThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool richerThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool FillReview(shared_ptr<Review> rr);
void ShowReview(const shared_ptr<Review> rr);


int main()
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp (new Review);

	while (FillReview(temp))
	{
		shared_ptr<Review> z(new Review);
		z->price = temp->price;
		z->rating = temp->rating;
		z->title = temp->title;

		books.push_back(z);
	}
	

	if (books.size() > 0)
	{
		cout << "\nThanks. You entered the following "
			<< books.size() << " ratings: \n"
			<< "Rating\tPrice\tBook\n";

		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;

		sort(books.begin(), books.end());
		cout << "Sorted by title:\nRating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;

		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;

		sort(books.begin(), books.end(),richerThan);
		cout << "Sorted by price increase :\nRating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;

		cout << "Sorted by price decrease :\nRating\tPrice\tBook\n";
		for_each(books.rbegin(), books.rend(), ShowReview);
		cout << endl;

	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	return 0;
}

bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
		return true;
	else
		return false;
}
bool worseThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}
bool richerThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}
bool FillReview(shared_ptr<Review> rr)
{
	cout << "Enter book title (quit to quit): ";
	getline(cin, rr->title);
	if (rr->title == "quit")
		return false;

	cout << "Enter book rating: ";
	cin >> rr->rating;
	if (!cin)
		return false;

	cout << "Enter book price: ";
	cin >> rr->price;
	if (!cin)
		return false;

	while (cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const shared_ptr<Review> rr)
{
	cout << rr->rating << "\t" << rr->price <<"\t"<< rr->title<< endl;
}
*/