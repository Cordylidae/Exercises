#include"DMA.h"

#pragma warning(disable: 4996);

DMA::DMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

DMA::DMA(const DMA & dm)
{
	label = new char[strlen(dm.label) + 1];
	strcpy(label, dm.label);
	rating = dm.rating;
}

DMA& DMA::operator=(const DMA& dm)
{
	if (this == &dm)
		return *this;

	delete[] label;
	label = new char[strlen(dm.label) + 1];
	strcpy(label, dm.label);
	rating = dm.rating;
	
	return *this;
}
void DMA::View() const
{
	std::cout << "Label: " << label << ", rating: " << rating;
}
DMA::~DMA()
{
	delete[] label;
}
baseDMA::baseDMA(const char* l, int r):DMA(l,r)
{
}
baseDMA::baseDMA(const baseDMA& dm):DMA(dm)
{
}
baseDMA& baseDMA::operator=(const baseDMA& dm)
{
	if (this == &dm)
		return *this;

	DMA::operator=(dm);

	return *this;
}
void baseDMA::View() const
{
	DMA::View();
}
baseDMA::~baseDMA()
{
}


lacksDMA::lacksDMA(const char* s, const char* l, int r) :DMA(l, r)
{
	color = new char[strlen(s) + 1];
	strcpy(color, s);
}

lacksDMA::lacksDMA(const char * c, const DMA& dm) : DMA(dm)
{
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}

lacksDMA& lacksDMA::operator=(const lacksDMA& dm)
{
	if (this == &dm)
		return *this;

	DMA::operator=(dm);
	
	delete[] color;
	color = new char[strlen(dm.color) + 1];
	strcpy(color, dm.color);

	return *this;
}

void lacksDMA::View() const
{
	DMA::View();
	std::cout << ", color: " << color;
}

lacksDMA::~lacksDMA()
{
	delete[] color;
}

hasDMA::hasDMA(const char* s, const char* l, int r) :DMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char * s,const DMA& dm) : DMA(dm)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA& hasDMA::operator=(const hasDMA& dm)
{
	if (this == &dm)
		return *this;

	DMA::operator=(dm);

	delete[] style;
	style = new char[strlen(dm.style) + 1];
	strcpy(style, dm.style);

	return *this;
}

void hasDMA::View() const
{
	DMA::View();
	std::cout << ", style: " << style;
}

hasDMA::~hasDMA()
{
	delete[] style;
}