#ifndef  STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
	enum Mode { Stone, Pds, Pound };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	Mode mode;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	void stone_mode();
	void pds_mode();
	void pounds_mode();
	
	
	Stonewt operator+(const Stonewt& b)const;
	Stonewt operator-(const Stonewt& b)const;
	Stonewt operator*(double n)const;

	friend Stonewt operator*(double n, const Stonewt& a);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& v);

	friend bool operator==(const Stonewt& st1, const Stonewt& st2);
	friend bool operator>=(const Stonewt& st1, const Stonewt& st2);
	friend bool operator<=(const Stonewt& st1, const Stonewt& st2);
	friend bool operator>(const Stonewt& st1, const Stonewt& st2);
	friend bool operator<(const Stonewt& st1, const Stonewt& st2);
	friend bool operator!=(const Stonewt& st1, const Stonewt& st2);
};

#endif