#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
const int n = 200;
int FEncode(int count, string Text, char Encode[n], int razr[n]);
int FDecode(int count, char Encode[n], char Decode[n], int razr[n]);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int count = 0;
	char Encode[n];
	char Decode[n];
	int razr[n];
	string Text;

	cout << "Введите текст, который нужно зашифровать:" << endl;
	getline(cin, Text);
	count = Text.size();
	cout << "Зашифрованный текст:" << endl;
	count = FEncode(count, Text, Encode, razr);
	for (int i = 0; i < count; i++)
	{
		cout << Encode[i];
	}
	cout << endl;
	cout << "Расшифрованный текст:" << endl;
	count = FDecode(count, Encode, Decode, razr);
	for (int i = 0; i < count; i++)
	{
		cout << Decode[i];
	}
	
	return 0;
}

int FEncode(int count, string Text, char Encode[n], int razr[n])
{
	int del = 0;
	int k = 0;
	bool sw = false;//----Логический флаг

	for (int i = 0; i < count; i++)
	{
		Encode[i] = Text[count - i -1];
	}
	for (int i = 0; i < count; i++)
	{
		if (del % 2 == 0)//------Определение четной позиции числа
		{
			if (int(Encode[i]) / 100 == 0)//--Определение двузначный или трехзначный код ASCII
			{
				razr[k] = 2;
				count++;
			}
			else
			{
				razr[k] = 3;
				count = count + 2;
			}
			switch (razr[k])
			{
			case 2://---Цикл с двузначным кодом
			{
				for (int t = count; t > i; t--)
				{
					Encode[t] = Encode[t - 1];//--Сдвиг массива на 1 вправо
				}
				if (int(Encode[i]) % 10 == 0)	Encode[i + 1] = char(48);
				if (int(Encode[i]) % 10 == 1)	Encode[i + 1] = char(49);
				if (int(Encode[i]) % 10 == 2)	Encode[i + 1] = char(50);
				if (int(Encode[i]) % 10 == 3)	Encode[i + 1] = char(51);
				if (int(Encode[i]) % 10 == 4)	Encode[i + 1] = char(52);
				if (int(Encode[i]) % 10 == 5)	Encode[i + 1] = char(53);
				if (int(Encode[i]) % 10 == 6)	Encode[i + 1] = char(54);
				if (int(Encode[i]) % 10 == 7)	Encode[i + 1] = char(55);
				if (int(Encode[i]) % 10 == 8)	Encode[i + 1] = char(56);
				if (int(Encode[i]) % 10 == 9)	Encode[i + 1] = char(57);

				if ((int(Encode[i]) / 10 == 3) && sw == false) { Encode[i] = char(51); sw = true; }
				if ((int(Encode[i]) / 10 == 4) && sw == false) { Encode[i] = char(52); sw = true; }
				if ((int(Encode[i]) / 10 == 5) && sw == false) { Encode[i] = char(53); sw = true; }
				if ((int(Encode[i]) / 10 == 6) && sw == false) { Encode[i] = char(54); sw = true; }
				if ((int(Encode[i]) / 10 == 7) && sw == false) { Encode[i] = char(55); sw = true; }
				if ((int(Encode[i]) / 10 == 8) && sw == false) { Encode[i] = char(56); sw = true; }
				if ((int(Encode[i]) / 10 == 9) && sw == false) { Encode[i] = char(57); sw = true; }
				i++;
				sw = false;//----Обнуление флага
				break;
			};

			case 3://---Цикл с трехзначным кодом
			{
				for (int t = count; t > i; t--)
				{
					Encode[t] = Encode[t - 2];//--Сдвиг массива на 2 вправо
				}
				if (int(Encode[i]) % 10 == 0)	Encode[i + 2] = char(48);
				if (int(Encode[i]) % 10 == 1)	Encode[i + 2] = char(49);
				if (int(Encode[i]) % 10 == 2)	Encode[i + 2] = char(50);
				if (int(Encode[i]) % 10 == 3)	Encode[i + 2] = char(51);
				if (int(Encode[i]) % 10 == 4)	Encode[i + 2] = char(52);
				if (int(Encode[i]) % 10 == 5)	Encode[i + 2] = char(53);
				if (int(Encode[i]) % 10 == 6)	Encode[i + 2] = char(54);
				if (int(Encode[i]) % 10 == 7)	Encode[i + 2] = char(55);
				if (int(Encode[i]) % 10 == 8)	Encode[i + 2] = char(56);
				if (int(Encode[i]) % 10 == 9)	Encode[i + 2] = char(57);

				if ((int(Encode[i]) / 10) % 10 == 0)	Encode[i + 1] = char(48);
				if ((int(Encode[i]) / 10) % 10 == 1)	Encode[i + 1] = char(49);
				if ((int(Encode[i]) / 10) % 10 == 2)	Encode[i + 1] = char(50);
				if ((int(Encode[i]) / 10) % 10 == 3)	Encode[i + 1] = char(51);
				if ((int(Encode[i]) / 10) % 10 == 4)	Encode[i + 1] = char(52);
				if ((int(Encode[i]) / 10) % 10 == 5)	Encode[i + 1] = char(53);
				if ((int(Encode[i]) / 10) % 10 == 6)	Encode[i + 1] = char(54);
				if ((int(Encode[i]) / 10) % 10 == 7)	Encode[i + 1] = char(55);
				if ((int(Encode[i]) / 10) % 10 == 8)	Encode[i + 1] = char(56);
				if ((int(Encode[i]) / 10) % 10 == 9)	Encode[i + 1] = char(57);

				if (int(Encode[i]) / 100 == 1)	Encode[i] = char(49);
				if (int(Encode[i]) / 100 == 2)	Encode[i] = char(50);
				i = i + 2;;
				break;
			};
			}
			k++;
		}
		del++;
	}
	return count;
}

int FDecode(int count, char Encode[n], char Decode[n], int razr[n])
{
	//int razr = 0;
	int k = 0;
	int q = 0;
	int sw = 0;
	for (int i = 0; i < count; i++)
	{
		if (sw % 2 == 0)
		{//-------------------------------------------------------Определяем код символа двузначный или трехзначный
			switch (razr[k])
			{
			case 2:
			{//-------------------------------------------Замена двуразрядного числа на символ
				if (int(Encode[i]) == 51)	q = 10 * 3;
				if (int(Encode[i]) == 52)	q = 10 * 4;
				if (int(Encode[i]) == 53)	q = 10 * 5;
				if (int(Encode[i]) == 54)	q = 10 * 6;
				if (int(Encode[i]) == 55)	q = 10 * 7;
				if (int(Encode[i]) == 56)	q = 10 * 8;
				if (int(Encode[i]) == 57)	q = 10 * 9;

				if (int(Encode[i + 1]) == 48)	q = q + 0;
				if (int(Encode[i + 1]) == 49)	q = q + 1;
				if (int(Encode[i + 1]) == 50)	q = q + 2;
				if (int(Encode[i + 1]) == 51)	q = q + 3;
				if (int(Encode[i + 1]) == 52)	q = q + 4;
				if (int(Encode[i + 1]) == 53)	q = q + 5;
				if (int(Encode[i + 1]) == 54)	q = q + 6;
				if (int(Encode[i + 1]) == 55)	q = q + 7;
				if (int(Encode[i + 1]) == 56)	q = q + 8;
				if (int(Encode[i + 1]) == 57)	q = q + 9;

				for (int t = i; t < count; t++)
				{
					Encode[t + 1] = Encode[t + 2];
				}
				Encode[i] = char(q);
				count--;
				break;
			};
			case 3:
			{//------------------------------------------Замена трехразрядного числа на символ
				if (int(Encode[i]) == 49)	q = 100 * 1;
				if (int(Encode[i]) == 50)	q = 100 * 2;

				if (int(Encode[i + 1]) == 48)	q = q + (10 * 0);
				if (int(Encode[i + 1]) == 49)	q = q + (10 * 1);
				if (int(Encode[i + 1]) == 50)	q = q + (10 * 2);
				if (int(Encode[i + 1]) == 51)	q = q + (10 * 3);
				if (int(Encode[i + 1]) == 52)	q = q + (10 * 4);
				if (int(Encode[i + 1]) == 53)	q = q + (10 * 5);
				if (int(Encode[i + 1]) == 54)	q = q + (10 * 6);
				if (int(Encode[i + 1]) == 55)	q = q + (10 * 7);
				if (int(Encode[i + 1]) == 56)	q = q + (10 * 8);
				if (int(Encode[i + 1]) == 57)	q = q + (10 * 9);

				if (int(Encode[i + 2]) == 48)	q = q + 0;
				if (int(Encode[i + 2]) == 49)	q = q + 1;
				if (int(Encode[i + 2]) == 50)	q = q + 2;
				if (int(Encode[i + 2]) == 51)	q = q + 3;
				if (int(Encode[i + 2]) == 52)	q = q + 4;
				if (int(Encode[i + 2]) == 53)	q = q + 5;
				if (int(Encode[i + 2]) == 54)	q = q + 6;
				if (int(Encode[i + 2]) == 55)	q = q + 7;
				if (int(Encode[i + 2]) == 56)	q = q + 8;
				if (int(Encode[i + 2]) == 57)	q = q + 9;

				for (int t = i; t < count; t++)
				{
					Encode[t + 1] = Encode[t + 3];
				}
				Encode[i] = char(q);
				count = count - 2;
				break;
			};
			}
			q = 0;
			k++;
		}
		sw++;
	}

	for (int i = 0; i < count; i++)
	{
		Decode[i] = Encode[count - i - 1];
	}
	return count;
}