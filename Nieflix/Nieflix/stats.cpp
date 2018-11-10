#include "stdafx.h"
#include "stats.h"
#include "conio.h"
#include "string"
#include "iostream"

Stats::Stats(){}
Stats::~Stats(){}

void Stats::countItems(MediaList<Media> &list)
{
	numberof[0] = 0; numberof[1] = 0; numberof[2] = 0;
	for (int i = 0; i < list.getSize(); i++) {
		if (list.chooseObject(i)->getGenre() == "Serial")
			numberof[0]++;
		else if (list.chooseObject(i)->getGenre() == "Film")
			numberof[1]++;
		else if (list.chooseObject(i)->getGenre() == "Livestream")
			numberof[2]++;
	}
}

void Stats::averages(MediaList<Media> &list)
{
	int counter = 0;
	this->averagescore = 0;
	this->averagelength = 0;
	for (int i = 0; i < list.getSize(); i++)
		if (list.chooseObject(i)->getGenre() != "Livestream") {
			averagescore += list.chooseObject(i)->getScore();
			averagelength += list.chooseObject(i)->Length();
			counter++;
		}
	averagescore = averagescore / counter;
	averagelength = averagelength / counter;
}
void Stats::mostCommonDay(MediaList<Media> &list)
{
	mostcommon = 0;
	int max = 0;
	int tab[8] = { 0,0,0,0,0,0,0,0 };
	for (int i = 0; i < list.getSize(); i++)
		if (list.chooseObject(i)->getGenre() != "Film") {
			tab[list.chooseObject(i)->getDay()]++;
		}
	for (int i = 1; i <= 7; i++)
		if (tab[i] >= max) {
			mostcommon = i;
			max = tab[i];
		}
}
void Stats::showStats(MediaList<Media> &list)
{
	if (list.getSize() > 0) {
		countItems(list);
		averages(list);
		mostCommonDay(list);
		cout << "\nLiczba serialow: " << numberof[0] << "\nLiczba filmow: " << numberof[1] << "\nLiczba livestream'ow: " << numberof[2] << endl;
		cout << "Srednia ocena: " << this->averagescore << "*" << endl;
		cout << "Srednia dlugosc: " << this->averagelength << "min" << endl;
		cout << "Najlepszy dzien na ogladanie: " << week[this->mostcommon] << endl;
	}
	else
		cout << "Lista jest pusta\n";
}

