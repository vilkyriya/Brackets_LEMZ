#ifndef BRACKETSVALIDATOR_H
#define BRACKETSVALIDATOR_H

#include <string>

using namespace std;

class BracketsValidator
{
public:
	BracketsValidator();
	~BracketsValidator();
	bool validateLine (string&);
private:
	string brackets_open; // все возможные открывающие скобки
	string brackets_close; // все возможные закрывающие скобки
	int findIndex (char, string);
};

#endif BRACKETSVALIDATOR_H
