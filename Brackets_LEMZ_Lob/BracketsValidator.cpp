#include "BracketsValidator.h"
#include <stack>
#include <string>

BracketsValidator::BracketsValidator() : brackets_open("({[<"), brackets_close(")}]>") 
{}

BracketsValidator::~BracketsValidator() 
{}

// ����� �������
int BracketsValidator::findIndex (char ch, string brackets)
{
	for (unsigned int i = 0; i < brackets.length(); i++)
	if (brackets[i] == ch)
		return i;
	return -1;
}

// ��������	������
bool BracketsValidator::validateLine (string& line)
{
	stack<int> openBrackets;

	for (unsigned int i = 0; i < line.length(); ++i)
	{
		// �������� ������� �� ������������ ����������� ������
		int index = findIndex(line[i], brackets_open);
		if (index > -1)
		{
			openBrackets.push(index);
			continue;
		}
		// �������� ������� �� ������������ ����������� ������
		index = findIndex(line[i], brackets_close);
		if (index > -1)
		{
			if (openBrackets.empty())
			{
				return false;
			}
			else
			{
				if (openBrackets.top() == index) //������� ������ ������ ������ ���� ���������
					openBrackets.pop();
				else
					return false;
			}
		}
	}
	return true;
}

