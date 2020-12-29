#include<iostream>

/*
//1

#include"cow.h"

int main()
{
	
	Cow cow1;
	Cow cow2("Luccie", "playing", 23);
	Cow cow3 = cow2;
	cow1 = cow2;
	Cow *cow4 = new Cow;
	*cow4 = cow2;

	cow1.showCow();
	cow2.showCow();
	cow3.showCow();
	cow4->showCow();

	return 0;
}
*/
/*
//2

#include"string2.h"

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;

	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncontains " << s2.letterInString('A')
		<< " 'A' charakters in it. \n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)break;
		else cout << "Try again!\n";
	}
	cout << "Bye!\n";
	return 0;
}
*/
/*
//3 

#include"Stock.h"
const int STKS = 4;

int main()
{
	Stock stocks[STKS] =
	{
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130 , 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holding: \n";
	int st;
	
	for (st = 0; st < STKS; st++)
		std::cout<<stocks[st];

	const Stock* top = &stocks[0];
	
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	std::cout << "\nMost valuable holding:\n";
	
	std::cout << *top << std::endl;

	return 0;
}
*/
/*
#include"Stack.h"

// 4
int main()
{
	Stack stack1(5);
	Stack stack2 = stack1;
	Stack stack3 = Stack(0);
	
	std::cout << "Enter (q to quit)(p to push in back of stack)(d to pop in back of stack)"<< std::endl;

	char ch;
	Item item;

	while (std::cin>>ch && (ch != 'q' && ch != 'Q'))
	{
		while (std::cin.get() != '\n')
			continue;

		switch (ch)
		{
		case 'p':
		case 'P':
		{
			std::cout << "Enter number to push ";
			while (!(std::cin >> item))
			{
				std::cout << "Error!!, please enter number" << std::endl;
			}
			if (stack2.isfull())std::cout << "Stack is full\n";
			else stack2.push(item);
		}
		break;
		case 'd':
		case 'D':
		{
			if (stack2.isempty())std::cout << "Stack is empty\n";
			else stack2.pop(item);
		}
		break;
		}

		std::cout << "Enter (q to quit)(p to push in back of stack)(d to pop in back of stack)" << std::endl;
	}


	stack3 = stack2;

	std::cout << "Stack 3, after = Stack2 have: ";

	while (!stack3.isempty())
	{
		Item a;
		stack3.pop(a);
		std::cout << a << " ";
	}
	
	stack2.pop(item);

	std::cout << "\nStack 2, after pop back, have: ";

	while (!stack2.isempty())
	{
		Item a;
		stack2.pop(a);
		std::cout << a << " ";
	}

	std::cout << "\nStack 1 have: ";

	while (!stack1.isempty())
	{
		Item a;
		stack1.pop(a);
		std::cout << a << " ";
	}

	return 0;
}
*/

//5,6

#include<cstdlib>
#include<ctime>
#include"Bank.h"

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
	int qs, qs2;
	cin >> qs >> qs2;
	BankQueue line(qs),line2(qs2);
	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	long cyclelimit = min_Per_Hr * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;

	double min_per_cust;
	min_per_cust = min_Per_Hr / perhour;

	Item temp,temp2;
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
			if (line.isfull() && line2.isfull())
			{
				turnaways++;
			}
			else if(line.queuecount()<line2.queuecount())
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
			else
			{
				customers++;
				temp2.set(cycle);
				line2.enqueue(temp2);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;

		if (wait_time2 <= 0 && !line2.isempty())
		{
			line2.dequeue(temp2);
			wait_time2 = temp2.ptime();
			line_wait += cycle - temp2.when();
			served++;
		}
		if (wait_time2 > 0)
			wait_time2--;

		sum_line += line.queuecount();
		sum_line += line2.queuecount();
	}


	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << " turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line/cyclelimit << endl;
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