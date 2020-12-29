#ifndef Golf_H_
#define Golf_H_

class Golf {
private:
	char* fullname = new char[40];
	int handsicap;

public:

	Golf(const char* name, int hc);

	void setgolf();

	void handicap(int hc);

	void showgolf() const;
};


#endif