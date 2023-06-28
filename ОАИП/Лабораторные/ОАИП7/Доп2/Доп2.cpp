#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;


struct Integer
{
	Integer* head, * next, * end;

	int num;
} *Area, * NewEl;

string path = "inf.txt";

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Area = new Integer;
	Area->head = Area;

	int min = 10000, numStr, i = 0;
	string str = " ";

	fstream file;
	file.open(path, fstream::in);

	while (!file.eof())
	{
		str = " ";
		getline(file, str);

		if (str.size() <= min)
		{
			min = str.size();
			numStr = i + 1;
		}

		NewEl = new Integer;
		NewEl->num = str.size();
		NewEl->next = Area->head;
		Area->head = NewEl;
		i++;
		cout << i << ") " << str << endl;
	}

	cout << "Длина самой короткой строки = " << min
		<< "\nЕё номер = " << numStr << endl;

	cout << "Стек состоит из : \n";
	i = 1;
	while (Area->head != Area)
	{
		cout << i++ << ") " << Area->head->num << endl;
		NewEl = Area->head->next;
		delete Area->head;
		Area->head = NewEl;
	}

	file.close();
	return 0;
}