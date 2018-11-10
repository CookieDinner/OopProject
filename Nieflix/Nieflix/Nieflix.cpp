#include "stdafx.h"
#include "iostream"
#include "medialist.h"
#include "series.h"
#include "movie.h"
#include "livestream.h"
#include "console.h"

using namespace std;

int main()
{
	Console console;
	MediaList <Media> list;
	/*Media *ser1, *ser2, *mov1, *liv1;*/

	/*ser1 = new Series("Osmiu wspanialych", 24, 2, 5.76f);
	ser2 = new Series("Jeden costam", 24, 3, 9.81f);
	mov1 = new Movie("Ciekawy film", 74, 7.54f);
	liv1 = new Livestream("Mile wydarzenie", 4, "21:29");*/
	
	/*list += ser1;
	list += ser2;
	list += mov1;
	list += liv1;*/
	
	console.start(list);

	//delete[] ser1;
	//delete[] ser2;
	//delete[] mov1;
//	delete[] liv1;
    return 0;
}
