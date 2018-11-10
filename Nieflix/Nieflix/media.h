#ifndef MEDIA_H
#define MEDIA_H

#include "string"
#include "iostream"
#include "conio.h"
#include "string"

using namespace std;

class Media {

protected:
	string name;
	int length;
	string airs;
	float score = 0;

public:
	Media();
	Media(string,int);
	~Media();

	virtual string showInfo();

	void setName(string);
	virtual string getName();
	
	void setLength(int);
	virtual string getLength();
	virtual int Length();

	virtual int getDay();

	void setScore(float);
	float getScore();

	virtual void edit(bool);

	virtual string getGenre();

	virtual string toFile();

};
#endif