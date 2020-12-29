#include<iostream>
#include<list>
/*
// 1
#include"BankCount.h"

int main()
{
	{
		BankCount Ford("Ford", "9999", 10000.92);

		BankCount *mas = new BankCount[4];
		mas[2] = BankCount("Cock Suckers", "6666", 100.97);

		for (int i = 0; i < 2; i++)
		{
			std::string s1, s2; double x;

			std::cout << "Enter name, count of card and balance: ";
			std::cin >> s1 >> s2 >> x;
			mas[i] = { s1,s2, x};

			std::cout << "If you want change balance enter: (+) or (-), and sum on has changes balance ";
			
			char k;
			std::cin >> k;
			std::cin >> x;

			switch (k)
			{
			case '+': {
				mas[i].addMoney(x);
			}
				break;
			case '-': {
				mas[i].moinsMoney(x);
			}
					break;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			mas[i].showCount();
		}

		Ford.showCount();

		delete [] mas;
	}
	return 0;
}
*/
/*
// 2
#include"Person.h"

int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");

	one.Show();
	one.FormalShow();
	std::cout << std::endl;

	two.Show();
	two.FormalShow();
	std::cout << std::endl;

	three.Show();
	three.FormalShow();
	std::cout << std::endl;


	return 0;
}
*/
/*
//3

#include"golf.h"

int main()
{
	int n = 5;
	Golf mas[5] = {
		{"Alloha Ice", 86},
		{"Cacun Ass", 73},
		{"Big White Hole", 84},
		{"Your Dick", 143},
		{"Kiss Lips", 91}
	};


	mas[1].setgolf();

	//for (; n < 5; n++)
	//{
	//	std::cout << "If you want change Bandicap enter 'b' and count, else enter 'n': ";
	//	char s;
	//	std::cin >> s;
	//	if (s == 'b')
	//	{
	//		int x;
	//		std::cin >> x;
	//		mas[n].handicap(x);
	//	}
	//}

	for (int i = 0; i < n; i++)
	{
		mas[i].showgolf();
	}
	return 0;
}*/
/*
//4 
#include"Sales.h"

int main()
{
	SALES::Sales *sales = new SALES::Sales[2];

	double ar[] = { 2.5, 5.4, 2.5 };

	sales[0] = SALES::Sales(ar,sizeof(ar)/sizeof(double));
	sales[1].setSales();

	for (int i = 0; i < 2; i++)
	{
		sales[i].showSales();
	}

	return 0;
}
*/
/*
//5 

#include"Stack.h"

int main()
{
	Stack stack;
	double sum = 0;
	char ch;

	customer cus;

	std::cout << "Please enter A to add a name and his payment,\n"
		<< "P to prosess Payment and Q to quit!\n ";

	while (std::cin>>ch and toupper(ch) != 'Q')
	{
		while (std::cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			std::cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			std::cout << "Enter a Name: ";
			std::cin.getline(cus.fullname,35);
			std::cout << "Enter a payment: ";
			std::cin >> cus.payment;

			if (stack.isfull())
				std::cout << "stack already full\n";
			else
				stack.push(cus);
			break;

		case 'P':
		case 'p':
			if (stack.isempty())
				std::cout << "stack already empty\n";
			else
			{
				sum += cus.payment;
				stack.pop(cus);
				std::cout << cus.fullname << " processed finish, sum of all Payment $" << sum << std::endl;
			}
			break;
		}
		std::cout << "Please enter A to add a name and his payment,\n"
			<< "P to prosess Payment and Q to quit!\n ";
	}
	std::cout << "Bye!\n";
	return 0;
}
*/
/*
// 6
#include"Move.h"

int main()
{
	Move move1,move2(7,9);

	move1.showmove();
	move2.showmove();
	move2 = move1.add(move2);
	move1.showmove();
	move2.showmove();
	move1.reset(1, 1);
	move1.showmove();
	move1.reset();
	move1.showmove();

	return 0;
}
*/
/*
// 7

#include"Plorg.h"

int main()
{
	{
		Plorg* mas = new Plorg[3];
		mas[0] = Plorg("Holi shot", 76);
		mas[1].swapCI(95);
		mas[2].enterDate();

		for (int i = 0; i < 3; i++)
			mas[i].showPlorg();

		delete [] mas;
	}
	return 0;
}
*/

//8 
#include"List.h"

void (*cShow_)(Item&) = cShow;
void (*cChange_)(Item&) = cChange;

int main()
{
	List list;
	
	for (int i = 0; i < 11; i++)
	{
		Item x;
		std::cin >> x;
		list.push(x);
	}
	list.visit(cChange_);
	list.visit(cShow_);
	

	return 0;
}