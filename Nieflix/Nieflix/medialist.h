#ifndef MEDIALIST_H
#define MEDIALIST_H

#include "string"
#include "vector"

using namespace std;

template <class T> class MediaList{
protected:
	int numberofelements;
	vector <T*> list;

public:
	MediaList() 
	{
		numberofelements = 0;
	};

	~MediaList() {};

	void operator +=(T* Object)
	{
		this->list.push_back(Object);
		numberofelements++;
	};

	void operator -=(int i)
	{
		if (numberofelements > 0 && i <= numberofelements && i > 0) {
			this->list.erase(list.begin() + (i - 1));
			numberofelements--;
		}
		else cout << "Wrong number!\n";
	};

	T* chooseObject(int i)
	{
		return list.at(i);
	};

	int getSize()
	{
		return numberofelements;
	}

	

};
#endif
