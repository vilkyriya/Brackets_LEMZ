#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus"); // ��� ����������� ����������� ������� �������� � �������

	string str = "";	// ������, ������� ���������� ���������
	const int brackets_app = 4; // ���������� �������������� ������
	char brackets_open[brackets_app + 1] = "({[<"; // ��� �������� ����������� ������
	char brackets_close[brackets_app + 1] = ")}]>"; // ��� �������� ����������� ������
	
	cout << "������� �����:\n";
	getline(cin, str);

	bool check_result = false; // ���������� ���������� ��������

	for (int i = 0; i < str.length(); i++)
	{
		// ��������
	}

	// ����� ���������� ��������
	if (!check_result) cout << "������ ����������� �����������\n";
	else cout << "������ ����������� ���������\n";

	system("pause");
    return 0;
}
