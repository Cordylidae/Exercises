#include "Time.h"
	
Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& t, const Time& t2)
{
	Time sum;
	sum.minutes = t2.minutes + t.minutes;
	sum.hours = t2.hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time& t, const Time& t2)
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = t2.minutes + 60 * t2.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time operator*(double mult, const Time& t)
{
	Time result;
	long totalmintus = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalmintus / 60;
	result.minutes = totalmintus % 60;
	return	result;
}
std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
