#ifndef CONSOLE_H
#define CONSOLE_H

#include "iostream"
#include "string"
#include "medialist.h"
#include "media.h"
#include "series.h"
#include "movie.h"
#include "livestream.h"
#include "stats.h"
#include "managefile.h"

using namespace std;

class Console 
{
private:
	Mfile file;
public:
	Console();
	~Console();
	void showMedia(MediaList<Media>&,bool);
	void showMainMenu();
	void showAddMenu();
	void addRecord(MediaList<Media>&);
	void editRecord(MediaList<Media>&);
	void deleteRecord(MediaList<Media>&);
	void start(MediaList<Media>&);
	void giveControl(MediaList<Media>&, int);
	void livestreamsSoon(MediaList<Media>&);
};

#endif