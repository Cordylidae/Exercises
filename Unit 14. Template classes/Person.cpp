#include"Person.h"


void Person::Show()
{
	std::cout << "Name: " << name<<", lastname: "<<lastname<<"\n";

}

void Gunslinger::Show()
{
	Person::Show();
	std::cout << "Count of nasechek: " << count << ", preparetion time: " << Draw()<<"\n";
}

double Gunslinger::Draw()
{
	if (count == 0)return 10 / 1;
	return 10 / count;
}

int PokerPlayer::Draw()
{
	srand(0);

	return rand()%52;
}

void BadDude::Show()
{
	Gunslinger::Show();
	std::cout << "Draw card: " << Cdraw();
}

int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}