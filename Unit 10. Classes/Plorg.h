#ifndef PROOF_H_
#define PROOF_H_

class Plorg
{
private: 
	static const int Max = 19;
	char *name = new char[Max];
	int CI;
public:
	Plorg(const char* name_ = "Plorga", int ci = 50);
	~Plorg();
	void enterDate();
	void swapCI(int ci);
	void showPlorg() const;
};

#endif 
