#ifndef CONSOLE_H
#define CONSOLE_H

#include "iostream"
#include "string"
#include "medialist.h"
#include "media.h"

using namespace std;

class Console 
{
public:
	void showMainMenu();
	void showAddMenu();
	void addRecord(MediaList<Media>&);
	void deleteRecord(MediaList<Media>&);
	void start(MediaList<Media>&);
	void giveControl(MediaList<Media>&, int);
};

#endif