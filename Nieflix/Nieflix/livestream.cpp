#include "stdafx.h"
#include "livestream.h"

Livestream::Livestream(){}

Livestream::Livestream(string n_name, int n_weekday, string n_time)
{
	this->name = n_name;
	this->weekday = n_weekday;
	this->time = n_time;
}

Livestream::~Livestream() {}

string Livestream::showInfo()
{
	string s;
	s += this->name;
	s += " - ";
	s += week[weekday];
	s += " - ";
	s += time;
	return s;
}

void Livestream::setTime(string n_time)
{
	this->time = n_time;
}

void Livestream::setWeekday(int n_weekday)
{
	this->weekday = n_weekday;
}

string Livestream::getWeekday()
{
	return week[this->weekday];
}

string Livestream::getTime()
{
	return this->time;
}

bool Livestream::timeCheck(string test)
{
	if (test[1] == ':') {
		if (test[0] >= '0' && test[0] <= '9')
			if (test[2] >= '0' && test[2] <= '5')
				if (test[3] >= '0' && test[3] <= '9')
					return true;
				else return false;
			else return false;
		else return false;
	}
	else if (test[2] == ':') {
		if (test[0] >= '0' && test[0] <= '2') {
			switch (test[0]) {
			case '0':
				if (test[1] >= '0' && test[1] <= '9') {}
				else return false;
				break;
			case '1':
				if (test[1] >= '0' && test[1] <= '9') {}
				else return false;
				break;
			case '2':
				if (test[1] >= '0' && test[1] <= '3') {}
				else return false;
				break;
			}
			if (test[3] >= '0' && test[3] <= '5')
				if (test[4] >= '0' && test[4] <= '9')
					return true;
				else return false;
			else return false;
		}
		else return false;
	}
	else return false;
}

void Livestream::edit(bool mode)
{
	int c = 0, newint = 0;
	string newname, temp;
	if (mode) {
		do{
			system("CLS");
			cout << showInfo() << endl;
			cout << "Ktore pole chcesz edytowac? \n(1. Nazwa livestream'u, 2. Dzien wydarzenia, 3. Czas rozpoczecia, 4. Wszystkie, 5. Powrot)\nWybor: ";
		
			while (!(cin >> c) || c > 5 || c < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Podano bledna wartosc.\n";
				_getch();
				system("CLS");
				cout << showInfo() << endl;
				cout << "Ktore pole chcesz edytowac? \n(1. Nazwa livestream'u, 2. Dzien wydarzenia, 3. Czas rozpoczecia, 4. Wszystkie, 5. Powrot)\nWybor: ";
			}

			switch (c) {
			case 1:
				cout << "\nNazwa: ";
				cin.clear(); cin.ignore();
				getline(cin, newname);
				setName(newname);
				break;
			case 2:
				cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nDzien: ";
				while (!(cin >> newint) || newint < 1 || newint > 7)
					cout << "Bledna wartosc\n";
				setWeekday(newint);
				break;
			case 3:
				temp = "0";
				cout << "\nGodzina (Format - __:__): ";
				while (!(cin >> newname) || !timeCheck(newname)) {
					cout << "Bledny input!\n";
					cout << "\nGodzina (Format - __:__ ): ";
				}
				if (newname[1] == ':')
					temp += newname;
				else
					temp = newname;
				this->time = temp;
				break;
			case 4:
				cout << "\nNazwa: ";
				cin.clear(); cin.ignore();
				getline(cin, newname);
				setName(newname);
				cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nDzien: ";
				while (!(cin >> newint) || newint < 1 || newint > 7)
					cout << "Bledna wartosc\n";
				setWeekday(newint);
				temp = "0";
				cout << "\nGodzina (Format - __:__): ";
				while (!(cin >> newname) || !timeCheck(newname)) {
					cout << "Bledny input!\n";
					cout << "\nGodzina (Format - __:__ ): ";
				}
				if (newname[1] == ':')
					temp += newname;
				else
					temp = newname;
				this->time = temp;
				break;
			}
		} while (c != 5);
	}
	else {
		cout << "\nNazwa: ";
		cin.clear(); cin.ignore();
		getline(cin, newname);
		setName(newname);
		cout << "\n(1. Poniedzialek, 2. Wtorek, 3. Sroda, 4. Czwartek, 5. Piatek, 6. Sobota, 7. Niedziela)\nDzien: ";
		while (!(cin >> newint) || newint < 1 || newint > 7)
			cout << "Bledna wartosc\n";
		setWeekday(newint);
		temp = "0";
		cout << "\nGodzina (Format - __:__): ";
		while (!(cin >> newname) || !timeCheck(newname)) {
			cout << "Bledny input!\n";
			cout << "\nGodzina (Format - __:__ ): ";
		}
		if (newname[1] == ':')
			temp += newname;
		else
			temp = newname;
		this->time = temp;
	}
}

string Livestream::getGenre()
{
	return genre;
}

int Livestream::getDay()
{
	return weekday;
}

string Livestream::toFile()
{
	string s;
	s += this->name;
	s += "-";
	s += to_string(weekday);
	s += "-";
	s += time;
	return s;
}
