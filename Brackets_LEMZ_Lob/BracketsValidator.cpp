#include "BracketsValidator.h"
#include <stack>
#include <string>

BracketsValidator::BracketsValidator() : brackets_open("({[<"), brackets_close(")}]>") 
{}

BracketsValidator::~BracketsValidator() 
{}

// Поиск индекса
int BracketsValidator::findIndex (char ch, string brackets)
{
	for (unsigned int i = 0; i < brackets.length(); i++)
	if (brackets[i] == ch)
		return i;
	return -1;
}

// Проверка	строки
bool BracketsValidator::validateLine (string& line)
{
	stack<int> openBrackets;

	for (unsigned int i = 0; i < line.length(); ++i)
	{
		// Проверка символа на соответствие открывающей скобке
		int index = findIndex(line[i], brackets_open);
		if (index > -1)
		{
			openBrackets.push(index);
			continue;
		}
		// Проверка символа на соответствие закрывающей скобке
		index = findIndex(line[i], brackets_close);
		if (index > -1)
		{
			if (openBrackets.empty())
			{
				return false;
			}
			else
			{
				if (openBrackets.top() == index) //индексы парных скобок должны быть одинаковы
					openBrackets.pop();
				else
					return false;
			}
		}
	}
	return true;
}

