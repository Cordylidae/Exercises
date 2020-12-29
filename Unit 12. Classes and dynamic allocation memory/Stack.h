#ifndef Stack_H_
#define Stack_H_

#include<iostream>

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item* pitems;
	int size;
	int top;
public:
	Stack(int n = 10);
	Stack(const Stack & st);
	~Stack();

	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);

	Stack& operator=(const Stack& st);
};


#endif