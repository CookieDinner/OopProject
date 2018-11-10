#include "stdafx.h"
#include "media.h"

Media::Media(){}

Media::Media(string n_name, int n_length)
{
	this->name = n_name;
	this->length = n_length;
}

Media::~Media(){}

string Media::showInfo()
{
	string s;
	s = this->name;
	s += " - ";
	s += to_string(length);
	s += "\n";
	return s;
}

void Media::setName(string n_name)
{
	this->name = n_name;
}

string Media::getName()
{
	return this->name;
}

void Media::setLength(int n_length)
{
	this->length = n_length;
}

string Media::getLength()
{
	string s = to_string(length);
	return s;
}

int Media::Length()
{
	return 0;
}

int Media::getDay()
{
	return 0;
}

void Media::setScore(float n_score)
{
	this->score = n_score;
}

float Media::getScore()
{
	return this->score;
}

void Media::edit(bool mode)
{
	cout << "Nic tu nie ma\n";
	_getch();
}

string Media::getGenre()
{
	return " ";
}

string Media::toFile()
{
	return string();
}
