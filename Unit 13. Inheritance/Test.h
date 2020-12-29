#ifndef TEST_H_
#define TEST_H_

class A
{
public:
	A() {};
	virtual void Draw() const; // if hasnt key-word 'virtual', pointers use only this method
	virtual ~A() {};
};

class B: public A
{
public:
	B():A() {};
	virtual void Draw() const;
	virtual ~B() {};
};

#endif 
