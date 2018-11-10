#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "string"
#include "iostream"

using namespace std;

class Exception {
private:
	string info = "";
public:
	void whatIsWrong();
};
#endif
