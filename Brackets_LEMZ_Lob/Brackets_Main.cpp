#include <iostream>
#include <string>
#include <stack>
#include "BracketsValidator.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus"); // для корректного отображения русских символов в консоли
	string str = "";	// строка, которую необходимо проверить
	bool isCorrect = false; // переменная результата проверки

	cout << "Введите текст:\n";
	getline(cin, str);

	BracketsValidator bracketsValidator;

	isCorrect = bracketsValidator.validateLine(str);

	if (isCorrect) cout << "Скобки расставлены корректно\n";
	else cout << "Скобки расставлены некорректно\n";

    return 0;
}
