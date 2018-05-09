#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

char brackets_open[] = "({[<"; // ��� �������� ����������� ������
char brackets_close[] = ")}]>"; // ��� �������� ����������� ������

class LineForCheck 
{
	private:
		// ����� �������
		int findIndex (char ch, string brackets)
		{
			for (unsigned int i = 0; i < brackets.length(); i++)
			if (brackets[i] == ch)
				return i;
			return -1;
		}

	public:
		// ��������	������
		bool validateLine (string line)
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
};

int main()
{	
	setlocale(LC_ALL, "rus"); // ��� ����������� ����������� ������� �������� � �������
	string str = "";	// ������, ������� ���������� ���������
	bool isCorrect = false; // ���������� ���������� ��������

	cout << "������� �����:\n";
	getline(cin, str);

	LineForCheck lineForCheck;

	isCorrect = lineForCheck.validateLine(str);

	if (isCorrect) cout << "������ ����������� ���������\n";
	else cout << "������ ����������� �����������\n";

    return 0;
}
