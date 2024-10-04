#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
const int n = 100;
string FEncode(int count, string Text);
string FDecode(int count, string Text);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int count = 0;
	string Text;

	cout << "Введите текст, который нужно зашифровать:" << endl;
	getline(cin, Text);
	count = Text.size();
	Text = FEncode(count, Text);
	cout << "Зашифрованный текст:" << endl;
	cout << Text << endl;
	Text = FDecode(count, Text);
	cout << "Расшифрованный текст:" << endl;
	cout << Text << endl;

	return 0;
}

string FEncode(int count, string Text)
{
	char Encode[n];
	for (int i = 0; i <= count; i++)
	{
		Encode[i] = Text[i];
		Encode[i] = 255 - (int)(Encode[i]);
		Text[i] = Encode[i];
	}
	return Text;
}

string FDecode(int count, string Text)
{
	char Decode[n];
	for (int i = 0; i <= count; i++)
	{
		Decode[i] = Text[i];
		Decode[i] = 255 - (int)(Decode[i]);
		Text[i] = Decode[i];
	}
	return Text;
}