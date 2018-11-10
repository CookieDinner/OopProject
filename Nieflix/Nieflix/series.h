#ifndef SERIES_H
#define SERIES_H

#include "media.h"

using namespace std;

class Series: public Media {
private:
	string genre = "Serial";
	int airs = 0;
	string week[8] = { "Nie ustawiono","Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
public:
	Series();
	Series(string, int, int, float);
	~Series();
	string showInfo();
	string getLength();
	int Length();
	void setAiringTime(int);
	string getAiringTime();
	void edit(bool);
	string getGenre();
	int getDay();
	string toFile();
};
#endif
