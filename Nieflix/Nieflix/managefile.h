#ifndef MFILE_H
#define MFILE_H

#include "iostream"
#include "string"
#include "medialist.h"
#include "media.h"
#include "series.h"
#include "movie.h"
#include "livestream.h"
#include "stats.h"
#include "fstream"

using namespace std;

class Mfile
{
private:
	ofstream ofile;
	ifstream ifile;
public:
	Mfile();
	~Mfile();
	void readFile(MediaList<Media>&);
	void saveFile(MediaList<Media>&);
};

#endif
