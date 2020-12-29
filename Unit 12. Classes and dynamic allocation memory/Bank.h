#ifndef BANK_H_
#define BANK_H_

#include<iostream>

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;


class BankQueue
{
private:
	struct Node { Item item; Node* next; };
	enum { Q_SIZE = 10 };

	Node* front;
	Node* rear;

	int items;
	const int qsize;

	BankQueue(const BankQueue& q) :qsize(0){}
	BankQueue& operator=(const BankQueue& q) { return *this; }

public:
	BankQueue(int qs = Q_SIZE);
	~BankQueue();

	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);

};


#endif