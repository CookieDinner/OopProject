#ifndef SERIES_H
#define SERIES_H

#include "media.h"

using namespace std;

class Series: public Media {
private:
	string genre = "Serial";
	int date = 0;
public:
	Series(string, int);
	~Series();
	string showInfo();
	string getLength();

};
#endif
