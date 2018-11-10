#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

using namespace std;

class Movie : public Media {
private:
	string genre = "Film";
public:
	Movie();
	Movie(string, int, float);
	~Movie();
	string showInfo();
	string getLength();
	int Length();
	void edit(bool);
	string getGenre();
	string toFile();
};
#endif
