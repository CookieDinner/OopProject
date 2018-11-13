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
	console.start(list);
    return 0;
	//nowa linia
}
