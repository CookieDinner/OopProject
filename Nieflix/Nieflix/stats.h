#ifndef STATS_H
#define STATS_H

#include "medialist.h"
#include "media.h"
#include "string"
#include "iostream"
#include "conio.h"

using namespace std;

class Stats {
private:
	int mostcommon, numberof[3] = { 0,0,0 };
	float averagescore = 0, averagelength = 0;
	string week[8] = { "Nie ustawiono","Poniedzialek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela" };
public:
	Stats();
	~Stats();
	void countItems(MediaList<Media>&);
	void averages(MediaList<Media>&);
	void mostCommonDay(MediaList<Media>&);
	void showStats(MediaList<Media>&);

};
#endif
