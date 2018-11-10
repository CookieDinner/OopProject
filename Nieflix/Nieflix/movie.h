#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

using namespace std;

class Movie : public Media {
private:
	string genre = "Film";
	int date = 0;
public:
	Movie(string, int);
	~Movie();
	string showInfo();
	string getLength();

};
#endif
