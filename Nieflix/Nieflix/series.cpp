#include "stdafx.h"
#include "series.h"

Series::Series(string n_name, int n_length)
{
	this->name = n_name;
	this->length = n_length;
}

Series::~Series(){}

string Series::showInfo()
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

string Series::getLength()
{
	string s = to_string(length);
	s += "min/odc";
	return s;
}
