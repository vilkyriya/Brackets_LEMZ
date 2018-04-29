#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus"); // ��� ����������� ����������� ������� �������� � �������

	string str = "";	// ������, ������� ���������� ���������
	const int brackets_app = 4; // ���������� �������������� ������
	char brackets_open[brackets_app + 1] = "({[<"; // ��� �������� ����������� ������
	char brackets_close[brackets_app + 1] = ")}]>"; // ��� �������� ����������� ������

	bool check_result = false; // ���������� ���������� ��������

	while (true)
	{
		cout << "������� �����:\n";
		getline(cin, str);

		stack<int> temp_brackets; // ���� � �������� ������������ ��������

		for (int i = 0; i < str.length(); i++)
		{
			// ��������
			int br_ind = 0; // ������ ������� ������
		
			for (int j = 0; j <= brackets_app; j++) // �������� � ������������ ��������
			{
				if (str[i] == brackets_open[j]) // ����� ���������� � ������������ ��������
				{
						temp_brackets.push(j); // �������� � ����
				}
				else if (str[i] == brackets_close[j]) // �� ����� ���������� � ������������ ��������, ���� � ������������
				{
					if (!temp_brackets.empty())
					{
							br_ind = j;
							int last_bracket = temp_brackets.top(); // ������� ������ ��������� ����������� ������

							if (last_bracket == br_ind) temp_brackets.pop();
							else temp_brackets.push(-1); // ����������� ������ �� ������������� ��������� ��������
							
					}
					else temp_brackets.push(-1);// ���� ����, �� ���� ������
				}
			}
		}

		if (!temp_brackets.empty()) check_result = false;
		else check_result = true;

		// ����� ���������� ��������
		if (!check_result) cout << "������ ����������� �����������\n";
		else cout << "������ ����������� ���������\n";
	}
    return 0;
}
