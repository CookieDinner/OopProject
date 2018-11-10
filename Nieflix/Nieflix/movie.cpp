#include "stdafx.h"
#include "movie.h"
#include "sstream"

Movie::Movie(){}

Movie::Movie(string n_name, int n_length, float n_score)
{
	this->name = n_name;
	this->length = n_length;
	this->score = n_score;
}

Movie::~Movie() {}

string Movie::showInfo()
{
	string s;
	s = genre;
	s += " - ";
	s += this->name;
	s += " - ";
	s += getLength();
	s += " - ";
	ostringstream ss;
	ss << noshowpoint << score;
	s += ss.str();
	s += '*';
	return s;
}

string Movie::getLength()
{
	int temp = 0;
	temp = length / 60;

	string s = to_string(temp);
	s += ":";
	if ((length % 60) > 9)
		s += to_string(length % 60);
	else {
		s += "0";
		s += to_string(length % 60);
	}
	s += "h";
	return s;
}

int Movie::Length()
{
	return this->length;
}

void Movie::edit(bool mode)
{
	int c = 0, newint = 0;
	float newscore = 0;
	string newname;
	if (mode) {
		do{
			system("CLS");
			cout << showInfo() << endl;
			cout << "Ktore pole chcesz edytowac? \n(1. Nazwa filmu, 2. Czas trwania, 3. Ocena, 4. Wszystkie, 5. Powrot)\nWybor: ";

			while (!(cin >> c) || c > 5 || c < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Podano bledna wartosc.\n";
				_getch();
				system("CLS");
				cout << showInfo() << endl;
				cout << "Ktore pole chcesz edytowac? \n(1. Nazwa filmu, 2. Czas trwania, 3. Ocena, 4. Wszystkie, 5. Powrot)\nWybor: ";
			}

			switch (c) {
			case 1:
				cout << "\nInput: ";
				cin.clear(); cin.ignore();
				getline(cin, newname);
				setName(newname);
				break;
			case 2:
				cout << "\nInput: ";
				while (!(cin >> newint) || newint < 1)
					cout << "Bledna wartosc\n";
				setLength(newint);
				break;
			case 3:
				cout << "\nInput: ";
				cin >> newscore;
				setScore(newscore);
				break;
			case 4:
				cout << "\nNazwa: ";
				cin.clear(); cin.ignore();
				getline(cin, newname);
				setName(newname);
				cout << "\nCzas trwania: ";
				while (!(cin >> newint) || newint < 1)
					cout << "Bledna wartosc\n";
				setLength(newint);
				cout << "\nOcena: ";
				cin >> newscore;
				setScore(newscore);
				break;
			}
		} while (c != 5);
	}
	else{
		cout << "\nNazwa: ";
		cin.clear(); cin.ignore();
		getline(cin, newname);
		setName(newname);
		cout << "\nCzas trwania: ";
		while (!(cin >> newint) || newint < 1)
			cout << "Bledna wartosc\n";
		setLength(newint);
		cout << "\nOcena: ";
		cin >> newscore;
		setScore(newscore);
	}
}

string Movie::getGenre()
{
	return genre;
}

string Movie::toFile()
{
	string s;
	s = genre;
	s += "-";
	s += this->name;
	s += "-";
	s += to_string(this->length);
	s += "-";
	ostringstream ss;
	ss << noshowpoint << score;
	s += ss.str();
	return s;
}


