#ifndef LIVESTREAM_H
#define LIVESTREAM_H

#include "media.h"

using namespace std;

class Livestream : public Media {
private:
	string genre = "Livestream", time;
	int weekday = 0;
	string week[8] = { "Nie ustawiono","Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
public:
	Livestream();
	Livestream(string, int, string);
	~Livestream();
	string showInfo();
	void setTime(string);
	void setWeekday(int);
	string getWeekday();
	string getTime();
	bool timeCheck(string);
	void edit(bool);
	string getGenre();
	int getDay();
	string toFile();
};
#endif
