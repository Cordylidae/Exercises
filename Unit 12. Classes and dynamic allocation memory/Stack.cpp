#include"Stack.h"

Stack::Stack(int n)
{
	pitems = new Item[n];

	size = n;
	top = n;

	for (int i = 0; i < n; i++)
	{
		pitems[i]=i;
	}

}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item& item)
{
	
	if (top < MAX)
	{
		Stack temp = (*this);

		size++;
		top++;

		delete [] pitems;
		pitems = new Item[size];

		for (int i = 0; i < size - 1; i++)
		{
			pitems[i] = temp.pitems[i];
		}
		pitems[top - 1] = item;

		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		Stack temp = (*this);

		size--;
		top--;

		item = pitems[top];

		delete[] pitems;
		if (size != 0)pitems = new Item[size];
		else pitems = nullptr;

		for (int i = 0; i < size; i++)
		{
			pitems[i] = temp.pitems[i];
		}
		
		return true;
	}
	else
		return false;
}

Stack::Stack(const Stack& st)
{

	size = st.size;

	pitems = new Item[size];

	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}

	top = st.top;

}

Stack& Stack::operator=(const Stack& st)
{
	size = st.size;

	delete[] pitems;
	pitems = new Item[size];

	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}

	top = st.top;

	return *this;
}
