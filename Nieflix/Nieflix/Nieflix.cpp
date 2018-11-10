#include "stdafx.h"
#include "iostream"
#include "medialist.h"
#include "series.h"
#include "movie.h"
#include "console.h"

using namespace std;

int main()
{
	Console console;
	MediaList <Media> list;
	Series* ser1;
	Series* ser2;
	Series* ser3;
	Movie* mov1;
	ser1 = new Series("Osmiu wspanialych", 24);
	ser2 = new Series("Jeden costam", 24);
	ser3 = new Series("Drugi piernik", 24);
	mov1 = new Movie("Ciekawy film", 74);
	
	list += ser1;
	list += ser2;
	list += ser3;
	list += mov1;
	
	console.start(list);


    return 0;
}
