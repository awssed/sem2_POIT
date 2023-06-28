
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include <cstdlib>
using namespace std;
#include <limits>
struct student
{
	string name;
	string date;
	string spes;
	int group;
	string faculty;
	double ball;
};

FILE* f;
FILE* f2;
errno_t err;



union students
{
	string name;
	string date;
	string spes;
	int group;
	string faculty;
	double ball;
};
void input(int size);
void output();
void find(int ball);

void main() {
	setlocale(LC_ALL, "rus");
	int ball;

	for (;;) {
	start:
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по цене\n";
		cout << "Введите номер операции: ";
		int q;
		cin >> q;
		switch (q)
		{
		case 1:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите количество студентов" << endl;
			int n;
			cin >> n;
			input(n);
			return;
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "Введите средний балл" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> ball;
			find(ball);
			break;
		}
	}

}
void input(int size) {
	student buf;
	int model;
	int i;
	if (!fopen_s(&f, "base.bin", "ab"))
	{

		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите фио" << endl;
			getline(cin, buf.name);
			for (int i = 0; i < buf.name.length(); i++) {
				if (buf.name[i] == '1' || buf.name[i] == '2' || buf.name[i] == '3' || buf.name[i] == '4' || buf.name[i] == '5' || buf.name[i] == '6' || buf.name[i] == '7' || buf.name[i] == '8' || buf.name[i] == '9'|| buf.name[i]=='0') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Введите дату" << endl;
			getline(cin, buf.date);
			if (sizeof(buf.date) != 40) {
				cout << "Некоректные данные";
				return;
			}
			for (int i = 0; i < buf.date.length(); i++) {
				if (buf.date[i] != '0' && buf.date[i] != '1' && buf.date[i] != '2' && buf.date[i] != '3' && buf.date[i] != '4' && buf.date[i] != '5' && buf.date[i] != '6' && buf.date[i] != '7' && buf.date[i] != '8' && buf.date[i] != '9') {
					cout << "Некоректные данные";
					return;
				}
			}
			int year;
			year = ((buf.date[4]-'0') * 1000 + (buf.date[5]-'0') * 100 + (buf.date[6]-'0') * 10+buf.date[7]-'0');
			if (year > 2023) {
				cout << "Некоректные данные";
				return;
			}
			cout << "Введите специальность" << endl;
			getline(cin, buf.spes);
			cout << "Введите группу" << endl;
			cin >> buf.group;
			if (buf.group <= 0) {
				cout << "error";
				return;
			}
			cout << "Введите факультет" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, buf.faculty);
			cout << "Введите средний балл" << endl;
			cin >> buf.ball;
			if (buf.ball < 1) {
				cout << "error";
				return;
			}
			fwrite(&buf, sizeof(buf), 1, f);
		}

		
		fclose(f);
		cout << '\n';

	}
	else {
		cout << "Ошибка открытия файла";
	}
	return;
}


void output() {
	ifstream file("base.bin");
	student buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.name << endl;
		cout << buf.date << endl;
		cout << buf.spes << endl;
		cout << "Группа" << buf.group << endl;
		cout << buf.faculty << endl;
		cout << "Средний балл" << buf.ball << endl;

		cout << '\n';
	}
	file.close();
}
void find(int ball) {
	bool flag = false;
	student buf;
	fopen_s(&f, "base.bin", "r");
	while (fread(&buf, sizeof(buf), 1, f))
	{
		if (ball <= buf.ball)
		{
			cout << buf.name << endl;
			cout << buf.date << endl;
			cout << buf.spes << endl;
			cout << "Группа" << buf.group << endl;
			cout << buf.faculty << endl;
			cout << "Средний балл" << buf.ball << endl;
			cout << '\n';
			flag = true;
		}

	}
	if (flag = false) cout << "Ничего не найдено\n";
	return;
	fclose(f);
	return;
}

