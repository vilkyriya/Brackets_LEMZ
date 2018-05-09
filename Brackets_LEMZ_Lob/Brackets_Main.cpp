#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

class LineForCheck // Класс для проверки передаваемой строки на корректную расстановку скобок типов (), {}, [], <>
{
	private:

		// Поиск индекса
		int findIndex (char ch, string brackets)
		{
			for (unsigned int i = 0; i < brackets.length(); i++)
			if (brackets[i] == ch)
				return i;
			return -1;
		}

	public:
		// Проверка	строки
		bool validateLine (string line)
		{
			stack<int> openBrackets;
			char brackets_open[] = "({[<"; // все возможны открывающие скобки
			char brackets_close[] = ")}]>"; // все возможны закрывающие скобки

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
};

int main()
{	
	setlocale(LC_ALL, "rus"); // для корректного отображения русских символов в консоли
	string str = "";	// строка, которую необходимо проверить
	bool isCorrect = false; // переменная результата проверки

	cout << "Введите текст:\n";
	getline(cin, str);

	LineForCheck lineForCheck;

	isCorrect = lineForCheck.validateLine(str);

	if (isCorrect) cout << "Скобки расставлены корректно\n";
	else cout << "Скобки расставлены некорректно\n";

    return 0;
}
