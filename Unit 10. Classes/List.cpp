#include"List.h"
#include<iostream>

List::List()
{
	top = 0;
}
bool List::isempty() const
{
	return top == 0;
}
bool List::isfull() const
{
	return top == Max;
}
bool List::push(const Item& item)
{
	if (top < Max)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
void List::visit(void (*pf)(Item&))
{
	for(int i=0;i<top;i++)
		pf(items[i]);

	std::cout << std::endl;
}

void cShow(Item& item)
{
	std::cout << item << " ";
}

void cChange(Item& item)
{
	Item num;
	std::cout << "Enter number: ";
	std::cin >> num;
	item += num;
}