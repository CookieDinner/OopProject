#include "stdafx.h"
#include "console.h"
#include "conio.h"

void Console::showMainMenu()
{
	system("CLS");

	cout << "Do sterowania programem prosze wpisywac poszczegolne cyfry.\n\n";

	cout << "1. Dodaj do listy obserwowanych,\n";

	cout << "2. Edytuj element z listy,\n";

	cout << "3. Usun z listy obserwowanych,\n";

	cout << "4. Usun z listy obserwowanych,\n";

	cout << "5. Wyjscie z programu.\n";

	cout << "\nWybor: ";
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

		break;

	case 2:

		break;

	case 3:

		break;
	}
}

void Console::deleteRecord(MediaList<Media> &list)
{

}

void Console::start(MediaList<Media> &list)
{
	int c = 0;
	do {
		showMainMenu();	

		while (!(cin >> c) || c > 5 || c < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Podano bledna wartosc.\n";
			_getch();
			showMainMenu();
		}	

		giveControl(list, c);

	} while (c != 5);
}

void Console::giveControl(MediaList<Media> &list,int c)
{
	if (c > 0 && c < 6) {

		switch (c) {
		case 1:
			addRecord(list);
			break;

		case 2:
			
			break;

		case 3:

			break;

		case 4:
			for (int i = 0; i < list.getSize(); i++)
				cout << i + 1 << ". " << list.chooseObject(i)->showInfo() << endl;
			_getch();
			break;

		}
	}
}
