#ifndef  PERSON_H_
#define PERSON_H_

#include<iostream>
#include<string>

class Person
{
private:
	std::string name;
	std::string lastname;
public:

	Person(const std::string& n1="none",const std::string& n2 = "none") :name(n1), lastname(n2) {}
	virtual ~Person() {}
	
	virtual void Show();
};


class Gunslinger : virtual public Person
{
private:
	int count;
public:
	Gunslinger() : Person(), count(0) {}
	Gunslinger(const std::string& n1,const std::string& n2, int c=0) :Person(n1, n2),count(c) {}
	Gunslinger(const Person& p, int c=0) :Person(p),count(c) {}
	virtual ~Gunslinger() {}

	virtual void Show();
	double Draw();
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer() :Person() {}
	PokerPlayer(const std::string& n1,const std::string& n2) :Person(n1, n2) {}
	PokerPlayer(const Person & p) :Person(p) {}
	virtual ~PokerPlayer() {}

	int Draw();
};

class BadDude :public PokerPlayer,public Gunslinger
{
public:
	BadDude() :Person(), PokerPlayer(), Gunslinger() {}
	BadDude(const std::string& n1,const std::string& n2, int c = 0):Person(n1,n2), PokerPlayer(n1,n2), Gunslinger(n1,n2,c) {}
	BadDude(const Person& p, int c = 0) :Person(p), PokerPlayer(p), Gunslinger(p,c){}
	BadDude(const PokerPlayer& p, int c = 0) :Person(p), PokerPlayer(p), Gunslinger(p, c) {}
	BadDude(const Gunslinger& p) :Person(p), PokerPlayer(p), Gunslinger(p) {}
	virtual ~BadDude() {}
	
	double Gdraw();
	int Cdraw();
	
	virtual void Show();
};

#endif