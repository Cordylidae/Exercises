#ifndef Move_H_
#define Move_H_


class Move
{
private:
	double x;
	double y;

public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move& m);

	void reset(double a = 0, double b = 0);
};

#endif // !Move_H_

