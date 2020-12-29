#ifndef TV_H_
#define TV_H_

class Remote;

class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int mode;
	int channel;
	int input;
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {};
	void onoff() { state = (state == On) ? Off : On; }
	void norints(Remote& r);
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;

};

class Remote
{
private:
	int mode;
	enum modeRemote{ Interect, Normal } state;
public:
	friend class Tv;
	Remote(int m = Tv::TV,modeRemote s=modeRemote::Normal) :mode(m),state(s) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.volup(); }
	void onoff(Tv& t) { return t.onoff(); }
	void chanup(Tv& t) { return t.chanup(); }
	void chandown(Tv& t) { return t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	void norints() { state = (state == Normal) ? Interect : Normal; }
	void settings() const;
};

inline void Tv::norints(Remote& r)
{
	if (input == TV && state == On) r.norints();
}
#endif