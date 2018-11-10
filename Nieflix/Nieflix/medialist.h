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

	inline void operator +=(T* Object)
	{
		this->list.push_back(Object);
		numberofelements++;
	};

	inline void operator -=(int i)
	{
			if (i <= numberofelements && i > 0) {
				delete this->list[(i - 1)];
				this->list.erase(list.begin() + (i - 1));
				numberofelements--;
			}
			else cout << "Podano bledna wartosc!\n";
	};

	inline T* chooseObject(int i)
	{
		return list.at(i);
	};

	inline int getSize()
	{
		return numberofelements;
	}

};
#endif
