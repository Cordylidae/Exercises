#include<iostream>
#include"Stonewt.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = lbs;
	mode = Pds;
}
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn + int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = stn * Lbs_per_stn + pds_left;


	mode = Pds;
}
Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode =  Mode::Stone;
	mode = Pds;
}
Stonewt::~Stonewt()
{
}


void Stonewt::stone_mode()
{
	mode = Stone;
}
void Stonewt::pds_mode()
{
	mode = Pds;
}
void Stonewt::pounds_mode()
{
	mode = Pound;
}


Stonewt Stonewt::operator+(const Stonewt& b)const { return Stonewt(stone + b.stone, pds_left + b.pds_left); }
Stonewt Stonewt::operator-(const Stonewt& b)const { return Stonewt((stone - b.stone)*(Lbs_per_stn)+ pds_left - b.pds_left); }
Stonewt Stonewt::operator*(double n)const { return Stonewt(n * stone, n * pds_left); }

Stonewt operator*(double n, const Stonewt& a) { return a * n; }

std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
	if (st.mode == Stonewt::Stone)
	{
		os << st.stone << " stone\n";
	}
	else if(st.mode == Stonewt::Pound)
	{
		os << st.pounds << " pounds\n";
	}
	else
	{
		os << st.stone << " stone, " << st.pds_left << " pounds\n";
	}
	return os;
}

bool operator==(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone == st2.stone && st1.pds_left == st2.pds_left)return true;
	return false;
}
bool operator>=(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone > st2.stone)return true;
	if (st1.stone == st2.stone && st1.pds_left >= st2.pds_left)return true;
	return false;
}
bool operator<=(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone < st2.stone)return true;
	if (st1.stone == st2.stone && st1.pds_left <= st2.pds_left)return true;
	return false;
}
bool operator>(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone > st2.stone)return true;
	if (st1.stone == st2.stone && st1.pds_left > st2.pds_left)return true;
	return false;
}
bool operator<(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone < st2.stone)return true;
	if (st1.stone == st2.stone && st1.pds_left < st2.pds_left)return true;
	return false;
}
bool operator!=(const Stonewt& st1, const Stonewt& st2)
{
	if (st1.stone != st2.stone || st1.pds_left != st2.pds_left)return true;
	return false;
}