#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <locale>

using namespace std;
const int n = 200;
int FEncode(string Text, char Encode[n], string table1, string table2);
int FDecode(char Decode[n], int count, char Encode[n], string table1, string table2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	int count = 0;
	string Text;
	char Encode[n];
	char Decode[n];
	string table1;
	string table2;

	cout << "Введите текст, который нужно зашифровать:" << endl;
	getline(cin, Text);
	ifstream table("Table.txt");
	getline(table, table1);
	getline(table, table2);
	cout << "Зашифрованный текст:" << endl;
	count = FEncode(Text, Encode, table1, table2);
	for (int i = 0; i < count; i++)
	{
		cout << Encode[i];
	}
	cout << endl;
	cout << "Расшифрованный текст:" << endl;
	count = FDecode(Decode, count, Encode, table1, table2);
	for (int i = 0; i < count; i++)
	{
		cout << Decode[i];
	}

	return 0;
}

int FEncode(string Text, char Encode[n], string table1, string table2)
{
	int number;
	int t = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		for (int k = 0; k < 33; k++)
		{
			if (Text[i] == table1[k])
			{
				if ((int(table2[k]) > 0) && (int(table2[k]) < 127))
				{
					number = (((k + 1) * 2) + int(table2[k]));
				}
				else
				{
					number = (((k + 1) * 2) + int(table2[k]) + 256);
				}

				if (number % 10 == 0)	Encode[t + 2] = char(48);
				if (number % 10 == 1)	Encode[t + 2] = char(49);
				if (number % 10 == 2)	Encode[t + 2] = char(50);
				if (number % 10 == 3)	Encode[t + 2] = char(51);
				if (number % 10 == 4)	Encode[t + 2] = char(52);
				if (number % 10 == 5)	Encode[t + 2] = char(53);
				if (number % 10 == 6)	Encode[t + 2] = char(54);
				if (number % 10 == 7)	Encode[t + 2] = char(55);
				if (number % 10 == 8)	Encode[t + 2] = char(56);
				if (number % 10 == 9)	Encode[t + 2] = char(57);

				if ((number / 10) % 10 == 0)	Encode[t + 1] = char(48);
				if ((number / 10) % 10 == 1)	Encode[t + 1] = char(49);
				if ((number / 10) % 10 == 2)	Encode[t + 1] = char(50);
				if ((number / 10) % 10 == 3)	Encode[t + 1] = char(51);
				if ((number / 10) % 10 == 4)	Encode[t + 1] = char(52);
				if ((number / 10) % 10 == 5)	Encode[t + 1] = char(53);
				if ((number / 10) % 10 == 6)	Encode[t + 1] = char(54);
				if ((number / 10) % 10 == 7)	Encode[t + 1] = char(55);
				if ((number / 10) % 10 == 8)	Encode[t + 1] = char(56);
				if ((number / 10) % 10 == 9)	Encode[t + 1] = char(57);

				if (number / 100 == 0)	Encode[t] = char(48);
				if (number / 100 == 1)	Encode[t] = char(49);
				if (number / 100 == 2)	Encode[t] = char(50);
				t = t + 3;
			}
		}
		
	}
	return t;
}

int FDecode(char Decode[n], int count, char Encode[n], string table1, string table2)
{
	int number = 0;
	int number0 = 0;
	int t = 0;
	for (int i = 0; i < count; i++)
	{
		if (int(Encode[i]) == 48)	number = 100 * 0;
		if (int(Encode[i]) == 49)	number = 100 * 1;
		if (int(Encode[i]) == 50)	number = 100 * 2;

		if (int(Encode[i + 1]) == 48)	number = number + (10 * 0);
		if (int(Encode[i + 1]) == 49)	number = number + (10 * 1);
		if (int(Encode[i + 1]) == 50)	number = number + (10 * 2);
		if (int(Encode[i + 1]) == 51)	number = number + (10 * 3);
		if (int(Encode[i + 1]) == 52)	number = number + (10 * 4);
		if (int(Encode[i + 1]) == 53)	number = number + (10 * 5);
		if (int(Encode[i + 1]) == 54)	number = number + (10 * 6);
		if (int(Encode[i + 1]) == 55)	number = number + (10 * 7);
		if (int(Encode[i + 1]) == 56)	number = number + (10 * 8);
		if (int(Encode[i + 1]) == 57)	number = number + (10 * 9);

		if (int(Encode[i + 2]) == 48)	number = number + 0;
		if (int(Encode[i + 2]) == 49)	number = number + 1;
		if (int(Encode[i + 2]) == 50)	number = number + 2;
		if (int(Encode[i + 2]) == 51)	number = number + 3;
		if (int(Encode[i + 2]) == 52)	number = number + 4;
		if (int(Encode[i + 2]) == 53)	number = number + 5;
		if (int(Encode[i + 2]) == 54)	number = number + 6;
		if (int(Encode[i + 2]) == 55)	number = number + 7;
		if (int(Encode[i + 2]) == 56)	number = number + 8;
		if (int(Encode[i + 2]) == 57)	number = number + 9;

		for (int k = 0; k < 33; k++)
		{
			if ((int(table2[k]) > 0) && (int(table2[k]) < 127))
			{
				number0 = (((k + 1) * 2) + int(table2[k]));
			}
			else
			{
				number0 = (((k + 1) * 2) + int(table2[k]) + 256);
			}
			if (number == number0)
			{
				Decode[t] = table1[k];
			}
		}
		t++;
		i = i + 2;
	}
	return t;
}