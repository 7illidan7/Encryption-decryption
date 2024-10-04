#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
string FEncode(string Text, int count);
string FDecode(string Text, int count);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	int count = 0;
	string Text;

	cout << "������� �����, ������� ����� �����������:" << endl;
	getline(cin, Text);
	count = Text.size();
	cout << "������������� �����:" << endl;
	Text = FEncode(Text, count);
	cout << Text << endl;
	cout << "�������������� �����:" << endl;
	Text = FDecode(Text, count);
	cout << Text;

	return 0;
}

string FEncode(string Text, int count)
{
	char per;
	for (int i = 4; i < count; i++)
	{
		per = Text[i];
		Text[i] = Text[i - 1];
		Text[i - 1] = Text[i - 2];
		Text[i - 2] = Text[i - 4];
		Text[i - 4] = per;
		i = i + 4;
	}
	return Text;
}

string FDecode(string Text, int count)
{
	char per;
	for (int i = 4; i < count; i++)
	{
		per = Text[i - 2];
		Text[i - 2] = Text[i - 1];
		Text[i - 1] = Text[i];
		Text[i] = Text[i - 4];
		Text[i - 4] = per;
		i = i + 4;
	}
	return Text;
}