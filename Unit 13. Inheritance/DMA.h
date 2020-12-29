#ifndef  DMA_H_
#define  DMA_H_

#include<iostream>

class DMA
{
private:
	char *label;
	int rating;
public:
	DMA(const char * l ="null",int r=0);
	DMA(const DMA& dm);
	DMA & operator=(const DMA& dm);
	virtual ~DMA();
	virtual void View() const = 0;
};

class baseDMA : public DMA
{
private:
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& dm);
	baseDMA& operator=(const baseDMA& dm);
	virtual ~baseDMA();
	virtual void View() const;
};


class lacksDMA : public DMA
{
private:
	char* color;
public:
	lacksDMA(const char * c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char * c, const DMA& dm);
	lacksDMA& operator=(const lacksDMA& dm);
	virtual ~lacksDMA();
	virtual void View() const;
};

class hasDMA: public DMA
{
private:
	char* style;
public:
	hasDMA(const char * s ="none",const char *l = "null",int r=0);
	hasDMA(const char * s, const DMA & dm);
	hasDMA& operator=(const hasDMA& dm);
	virtual ~hasDMA();
	virtual void View() const;
};




#endif 

