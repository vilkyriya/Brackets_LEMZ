#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus"); // для корректного отображения русских символов в консоли

	string str = "";	// строка, которую необходимо проверить
	const int brackets_app = 4; // количество разновидностей скобок
	char brackets_open[brackets_app + 1] = "({[<"; // все возможны открывающие скобки
	char brackets_close[brackets_app + 1] = ")}]>"; // все возможны закрывающие скобки

	bool check_result = false; // переменная результата проверки

	while (true)
	{
		cout << "Введите текст:\n";
		getline(cin, str);

		stack<int> temp_brackets; // стек с текущими проверяемыми скобками

		for (int i = 0; i < str.length(); i++)
		{
			// проверка
			int br_ind = 0; // индекс текущей скобки
		
			for (int j = 0; j <= brackets_app; j++) // сравнили с открывающими скобками
			{
				if (str[i] == brackets_open[j]) // нашли совпадение с открывающими скобками
				{
						temp_brackets.push(j); // положили в стек
				}
				else if (str[i] == brackets_close[j]) // не нашли совпадение с открывающими скобками, ищем с закрывающими
				{
					if (!temp_brackets.empty())
					{
							br_ind = j;
							int last_bracket = temp_brackets.top(); // смотрим индекс последней открывающей скобки

							if (last_bracket == br_ind) temp_brackets.pop();
							else temp_brackets.push(-1); // закрывающая скобка не соответствует последней открытой
							
					}
					else temp_brackets.push(-1);// стек пуст, но есть скобка
				}
			}
		}

		if (!temp_brackets.empty()) check_result = false;
		else check_result = true;

		// Вывод результата проверки
		if (!check_result) cout << "Скобки расставлены некорректно\n";
		else cout << "Скобки расставлены корректно\n";
	}
    return 0;
}
