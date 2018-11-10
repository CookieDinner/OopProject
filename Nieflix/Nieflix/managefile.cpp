#include "stdafx.h"
#include "managefile.h"

Mfile::Mfile()
{
}

Mfile::~Mfile()
{
	ofile.close();
	ifile.close();
}

void Mfile::readFile(MediaList<Media> &list)
{

	Media* poi;
	int c = 0;
	string s[4];
	ifile.open("database.txt", fstream::in);
	ifile >> c;
	cout << "NUMER: " << c;
	getline(ifile, s[0], '\n');
	for (int i = 0; i < c; i++) {

		getline(ifile, s[0], '-');

		if (s[0] == "Serial") {
			for (int j = 0; j < 3; j++)
				getline(ifile, s[j], '-');
			getline(ifile, s[3], '\n');
			poi = new Series(s[0], stoi(s[1]), stoi(s[2]), stof(s[3]));
			cout << poi->showInfo() << endl;
			list += poi;
		}
		else if (s[0] == "Film") {
			for (int j = 0; j < 2; j++)
				getline(ifile, s[j], '-');
			getline(ifile, s[2], '\n');
			poi = new Movie(s[0], stoi(s[1]), stof(s[2]));
			cout << poi->showInfo() << endl;
			list += poi;
		}
		else {
			for (int j = 0; j < 2; j++)
				getline(ifile, s[j], '-');
			getline(ifile, s[2], '\n');
			poi = new Livestream(s[0], stoi(s[1]), s[2]);
			cout << poi->showInfo() << endl;
			list += poi;
		}
	}
	ifile.close();
}

void Mfile::saveFile(MediaList<Media> &list)
{
	ofile.open("database.txt", fstream::out, fstream::trunc);
	ofile << list.getSize();
	for (int i = 0; i < list.getSize(); i++) {
		if (list.chooseObject(i)->getGenre() != "Livestream")
			ofile << endl << list.chooseObject(i)->toFile();
		else
			ofile << endl << "Livestream-" << list.chooseObject(i)->toFile();
	}
	ofile.close();
}

