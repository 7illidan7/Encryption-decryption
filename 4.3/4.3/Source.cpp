#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <locale>

using namespace std;
string FEncode(string Text, string table1, string table2);
string FDecode(string Text, string table1, string table2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	size_t b1;
	size_t b2;
	string w1, w2;
	string Text;
	string table1;
	string table2;

	cout << "Введите текст, который нужно зашифровать:" << endl;
	getline(cin, Text);
	b1 = Text.find(' ');//Позиции пробелов в строке
	b2 = Text.rfind(' ');
	w1 = Text.substr(0, b1);
	w2 = Text.substr(b2 + 1);
	Text.replace(b2 + 1, Text.length() - b2, w1);
	Text.replace(0, b1, w2);
	ifstream table("Table.txt");
	getline(table, table1);
	getline(table, table2);
	cout << "Зашифрованный текст:" << endl;
	Text = FEncode(Text, table1, table2);
	cout << Text << endl;
	cout << "Расшифрованный текст:" << endl;
	Text = FDecode(Text, table1, table2);
	b1 = Text.find(' ');//Позиции пробелов в строке
	b2 = Text.rfind(' ');
	w1 = Text.substr(0, b1);
	w2 = Text.substr(b2 + 1);
	Text.replace(b2 + 1, Text.length() - b2, w1);
	Text.replace(0, b1, w2);
	cout << Text << endl;

	return 0;
}

string FEncode(string Text, string table1, string table2)
{
	bool flag;
	for (int i = 0; i < Text.length(); i++)
	{
		flag = false;
		for (int k = 0; k < table1.length(); k++)
		{
			if ((Text[i] == table1[k]) && (flag == false))
			{

				Text[i] = table2[k];
				flag = true;
			}
		}
	}
	return Text;
}

string FDecode(string Text, string table1, string table2)
{
	bool flag;
	for (int i = 0; i < Text.length(); i++)
	{
		flag = false;
		for (int k = 0; k < table2.length(); k++)
		{
			if ((Text[i] == table2[k]) && (flag == false))
			{

				Text[i] = table1[k];
				flag = true;
			}
		}
	}
	return Text;
}