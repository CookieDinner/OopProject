#include "stdafx.h"
#include "movie.h"

Movie::Movie(string n_name, int n_length)
{
	this->name = n_name;
	this->length = n_length;
}

Movie::~Movie() {}

string Movie::showInfo()
{
	string s;
	s = genre;
	s += " - ";
	s += this->name;
	s += " - ";
	s += getLength();
	s += " - ";
	s += to_string(date);
	return s;
}

string Movie::getLength()
{
	int temp = 0;
	temp = length / 60;
	string s = to_string(temp);
	s += ":";
	s += to_string(length % 60);
	s += "h";
	return s;
}
