#ifndef MEDIA_H
#define MEDIA_H

#include "string"

using namespace std;

class Media {

protected:
	string name;
	int length;
	int airs_on;
	float score;

public:
	Media();
	Media(string,int);
	~Media();

	virtual string showInfo();
	void setName(string);
	virtual string getName();
	
	void setLength(int);
	virtual string getLength();
	
	void setScore(float);
	float getScore();
	
};
#endif