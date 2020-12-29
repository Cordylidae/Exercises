#include"Bank.h"
#include<cstdlib>

BankQueue::BankQueue(int qs) :qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
BankQueue::~BankQueue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool BankQueue::isempty() const { return items == 0; }
bool BankQueue::isfull() const { return items == qsize; }
int BankQueue::queuecount() const { return items; }

bool BankQueue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	
	Node* add = new Node;

	add->item = item;
	add->next = NULL;

	items++;

	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool BankQueue::dequeue(Item& item)
{
	if (front == NULL)
		return false;

	item = front->item;
	items--;

	Node* temp = front;

	front = front->next;
	delete temp;

	if (items == 0)
		rear = NULL;
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}