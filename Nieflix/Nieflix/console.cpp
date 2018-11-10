#include "stdafx.h"
#include "console.h"
#include "conio.h"

Console::Console()
{
}

Console::~Console()
{
}

void Console::showMedia(MediaList<Media> &list, bool mode)
{
	for (int i = 0; i < list.getSize(); i++)
		if (list.chooseObject(i)->getGenre() != "Livestream" || mode)
			cout << i + 1 << ". " << list.chooseObject(i)->showInfo() << endl;
}

void Console::showMainMenu()
{
	system("CLS");

	cout << "Do sterowania programem prosze wpisywac poszczegolne cyfry.\n\n";

	cout << "1. Dodaj do listy obserwowanych,\n";

	cout << "2. Edytuj element z listy,\n";

	cout << "3. Usun z listy obserwowanych,\n";

	cout << "4. Wyswietl obserwowane media,\n";

	cout << "5. Wyswietl statystyki,\n";

	cout << "6. Wyjscie z programu.\n";

}
void Console::showAddMenu()
{
	system("CLS");

	cout << "Co ma zostac dodane?\n";

	cout << "1. Serial?\n";

	cout << "2. Film?\n";

	cout << "3. Wydarzenie na zywo?\n";

	cout << "4. Powrot\n";

	cout << "\nWybor: ";
}
void Console::addRecord(MediaList<Media> &list)
{
	Media *poi;
	int c = 0;	

	showAddMenu();

	while (!(cin >> c) || c < 1 || c > 4) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Podano bledna wartosc.\n";
		_getch();
		showAddMenu();
	}

	switch (c) {
	case 1:
		cout << "Prosze podac dane serialu.\n";
		poi = new Series();
		poi->edit(0);
		list += poi;
		break;

	case 2:
		cout << "Prosze podac dane filmu.\n";
		poi = new Movie();
		poi->edit(0);
		list += poi;
		break;

	case 3:
		cout << "Prosze podac dane wydarzenia.\n";
		poi = new Livestream();
		poi->edit(0);
		list += poi;
		break;
	}
}

void Console::editRecord(MediaList<Media> &list)
{
	int c = 0;
	system("CLS");
	showMedia(list,true);

	cout << "Ktory rekord ma zostac poddany edycji? (0. Powrot)\nWybor: ";

	while (!(cin >> c) || c > list.getSize() || c < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Podano bledna wartosc.\n";
		_getch();
		system("CLS");
		showMedia(list,true);
		cout << "Ktory rekord ma zostac poddany edycji? (0. Powrot)\nWybor: ";
	}
	if (c != 0)
		list.chooseObject(c-1)->edit(1);
}
void Console::deleteRecord(MediaList<Media> &list)
{
	int c = 0;
	system("CLS");
	showMedia(list,true);

	cout << "Ktory rekord ma zostac usuniety? (0. Powrot)\nWybor: ";

	while (!(cin >> c) || c > list.getSize() || c < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Podano bledna wartosc.\n";
		_getch();
		system("CLS");
		showMedia(list,true);
		cout << "Ktory rekord ma zostac usuniety?(0. Powrot)\nWybor: ";
	}
	if (c != 0)
		list -= c;
}

void Console::start(MediaList<Media> &list)
{
	file.readFile(list);
	int c = 0;
	do {
		
		showMainMenu();	
		livestreamsSoon(list);

		while (!(cin >> c) || c > 6 || c < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Podano bledna wartosc.\n";
			_getch();
			
			showMainMenu();
			livestreamsSoon(list);
		}	

		if (c != 6)
			giveControl(list, c);

	} while (c != 6);
	file.saveFile(list);
	for (int i = list.getSize(); i > 0; i--) {
		list -= i;
	}
	cout << "Do zobaczenia kolejnym razem :)\n";
	_getch();
}

void Console::giveControl(MediaList<Media> &list,int c)
{
	Stats stats;
	switch (c) {
	case 1:
		addRecord(list);
		break;

	case 2:
		if (list.getSize() > 0)
			editRecord(list);
		else {
			cout << "Brak obserwowanych mediow.\n";
			_getch();
		}
		break;

	case 3:
		if (list.getSize() > 0)
			deleteRecord(list);
		else {
			cout << "Nie ma czego usuwac.\n";
			_getch();
		}
		break;

	case 4:
		if (list.getSize() > 0) {
			showMedia(list,false);
			_getch();
		}
		else {
			cout << "Nie ma niczego na liscie obserwowanych\n";
			_getch();
		}
		
		break;
	case 5:
		stats.showStats(list);
		_getch();
		break;
	}
}

void Console::livestreamsSoon(MediaList<Media> &list)
{
	int counter = 0;
	cout << "\nNadchodzace wydarzenia na zywo: \n";
	for (int i = 0; i < list.getSize(); i++)
		if (list.chooseObject(i)->getGenre() == "Livestream") {
			cout << list.chooseObject(i)->showInfo() << endl;
			counter++;
		}
	if (!counter)
		cout << "Brak";

	cout << "\nWybor: ";
}
