#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus"); // для корректного отображения русских символов в консоли

	string str = "";	// строка, которую необходимо проверить
	const int brackets_app = 4; // количество разновидностей скобок
	char brackets_open[brackets_app + 1] = "({[<"; // все возможны открывающие скобки
	char brackets_close[brackets_app + 1] = ")}]>"; // все возможны закрывающие скобки
	
	cout << "Введите текст:\n";
	getline(cin, str);

	bool check_result = false; // переменная результата проверки

	for (int i = 0; i < str.length(); i++)
	{
		// проверка
	}

	// Вывод результата проверки
	if (!check_result) cout << "Скобки расставлены некорректно\n";
	else cout << "Скобки расставлены корректно\n";

	system("pause");
    return 0;
}
