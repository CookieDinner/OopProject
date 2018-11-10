#include "stdafx.h"
#include "series.h"
#include "sstream"

Series::Series(){}

Series::Series(string n_name, int n_length, int n_airs, float n_score)
{
	this->name = n_name;
	this->length = n_length;
	this->airs = n_airs;
	this->score = n_score;
}

Series::~Series(){}

string Series::showInfo()
{
	string s;
	s = genre;
	s += " - ";
	s += this->name;
	s += " - ";
	s += getLength();
	s += " - ";
	s += week[airs];
	s += " - ";
	ostringstream ss;
	ss << noshowpoint << score;
	s += ss.str();
	s += '*';
	return s;
}
string Series::toFile() {
	string s;
	s = genre;
	s += "-";
	s += this->name;
	s += "-";
	s += to_string(this->length);
	s += "-";
	s += to_string(airs);
	s += "-";
	ostringstream ss;
	ss << noshowpoint << score;
	s += ss.str();
	return s;
}

string Series::getLength()
{
	string s = to_string(length);
	s += "min/odc";
	return s;
}

int Series::Length()
{
	return this->length;
}

void Series::setAiringTime(int n_airs)
{
	this->airs = n_airs;
}

string Series::getAiringTime()
{
	return week[airs];
}

void Series::edit(bool mode)
{
	int c = 0, newint = 0;
	float newscore = 0;
	string newname;
	if (mode) {
		do{
			system("CLS");
			cout << showInfo() << endl;
			cout << "Ktore pole chcesz edytowac? \n(1. Nazwa serialu, 2. Czas trwania odc, 3. Dzien premiery, 4. Ocena, 5. Wszystkie, 6. Powrot)\nWybor: ";

		
			while (!(cin >> c) || c > 6 || c < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Podano bledna wartosc.\n";
				_getch();
				system("CLS");
				cout << showInfo() << endl;
				cout << "Ktore pole chcesz edytowac? \n(1. Nazwa serialu, 2. Czas trwania odc, 3. Dzien premiery, 4. Ocena, 5. Wszystkie, 6. Powrot)\nWybor: ";
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
				cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nInput: ";
				while (!(cin >> newint) || newint < 1 || newint > 7)
					cout << "Bledna wartosc\n";
				setAiringTime(newint);
				break;
			case 4:
				cout << "\nInput: ";
				cin >> newscore;
				setScore(newscore);
				break;
			case 5:
				cout << "\nNazwa: ";
				cin.clear(); cin.ignore();
				getline(cin, newname);
				setName(newname);
				cout << "\nCzas trwania: ";
				while (!(cin >> newint) || newint < 1)
					cout << "Bledna wartosc\n";
				setLength(newint);
				cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nDzien premiery: ";
				while (!(cin >> newint) || newint < 1 || newint > 7)
					cout << "Bledna wartosc\n";
				setAiringTime(newint);
				cout << "\nOcena: ";
				cin >> newscore;
				setScore(newscore);
				break;
			}
		} while (c != 6);
	}
	else {
		cout << "\nNazwa: ";
		cin.clear(); cin.ignore();
		getline(cin, newname);
		setName(newname);
		cout << "\nCzas trwania: ";
		while (!(cin >> newint) || newint < 1)
			cout << "Bledna wartosc\n";
		setLength(newint);
		cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nDzien premiery: ";
		while (!(cin >> newint) || newint < 1 || newint > 7)
			cout << "Bledna wartosc\n";
		setAiringTime(newint);
		cout << "\nOcena: ";
		cin >> newscore;
		setScore(newscore);
	}
}

string Series::getGenre()
{
	return genre;
}

int Series::getDay()
{
	return airs;
}
