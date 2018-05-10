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
	string brackets_open; // ��� ��������� ����������� ������
	string brackets_close; // ��� ��������� ����������� ������
	int findIndex (char, string);
};

#endif BRACKETSVALIDATOR_H
