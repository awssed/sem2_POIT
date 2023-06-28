
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include <limits>

FILE* f;
struct prepod {
	string familia;
	string ex;
	unsigned int dаte:10;
	string date_of_ex;
};

void input(int size);
void output();
void find(string date);
void del(string name);

void main() {
	setlocale(LC_ALL, "rus");
	int i;
	int size;
	string date;
	string familia;
		cout << "1.Ввод преподавателя" << endl;
		cout << "2.Вывод преподавателей" << endl;
		cout << "3.Поиск по дате" << endl;
		cout << "4.Удаление" << endl;
		cin >> i;
		switch (i) {
		case 1:
			cin >> size;
			input(size);
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "Введите дату для поиска" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, date);
			find(date);
		case 4:
			cout << "Введите фамилию для удаления" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, familia);
			del(familia);
			break;
		}

}
void input(int size) {
	prepod buf;
	int form;
	int i;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		time_t now = time(0);

		tm* ltm = localtime(&now);
		int year = 1900 + ltm->tm_year;
		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите фамилию" << endl;
			getline(cin, buf.familia);
			for (int i = 0; i < buf.familia.length(); i++) {
				if (buf.familia[i] == '1' || buf.familia[i] == '2' || buf.familia[i] == '3' || buf.familia[i] == '4' || buf.familia[i] == '5' || buf.familia[i] == '6' || buf.familia[i] == '7' || buf.familia[i] == '8' || buf.familia[i] == '9'|| buf.familia[i] == '0') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Введите название экзамена" << endl;
			getline(cin, buf.ex);
			for (int i = 0; i < buf.ex.length(); i++) {
				if (buf.ex[i] == '1' || buf.ex[i] == '2' || buf.ex[i] == '3' || buf.ex[i] == '4' || buf.ex[i] == '5' || buf.ex[i] == '6' || buf.ex[i] == '7' || buf.ex[i] == '8' || buf.ex[i] == '9'||buf.ex[i]=='0') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Введите дату экзамена" << endl;
			getline(cin, buf.date_of_ex);
			if (sizeof(buf.date_of_ex) != 40) {
				cout << "Некоректные данные";
				return;
			}
			for (int i = 0; i < buf.date_of_ex.length(); i++) {
				if (buf.date_of_ex[i] != '1' && buf.date_of_ex[i] != '2' && buf.date_of_ex[i] != '3' && buf.date_of_ex[i] != '4' && buf.date_of_ex[i] != '5' && buf.date_of_ex[i] != '6' && buf.date_of_ex[i] != '7' && buf.date_of_ex[i] != '8' && buf.date_of_ex[i] != '9'&&buf.date_of_ex[i]!='0') {
					cout << "Некоректные данные";
					return;
				}
			}
			int year = (buf.date_of_ex[4] - '0') * 1000 + (buf.date_of_ex[5] - '0') * 100 + (buf.date_of_ex[6] - '0') * 10 + buf.date_of_ex[7] - '0';
			int day = (buf.date_of_ex[0] - '0') * 10 + (buf.date_of_ex[1] - '0');
			int month = (buf.date_of_ex[2] - '0') * 10 + (buf.date_of_ex[3] - '0');
			if (day > 31 || month > 13) {
				cout << "Некоректные данные";
				return;
			}
			
			fwrite(&buf, sizeof(buf), 1, f);
			cout << '\n';
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
	}
	return;
}
void output() {
	ifstream file("base.bin");
	prepod buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.familia<<endl;
		cout << buf.ex<<endl;
		cout << buf.date_of_ex<<endl;
		cout << '\n';
	}
	file.close();
}
void find(string date) {
	bool flag = false;
	prepod buf;
	if (!fopen_s(&f, "base.bin", "r"))
	{
		while (fread(&buf, sizeof(buf), 1, f))
		{
			if (date==buf.date_of_ex)
			{
				cout << buf.familia<<endl;
				cout << buf.ex<<endl;
				cout << buf.date_of_ex<<endl;
				cout << '\n';
				flag = true;
			}
		}
		if (flag = false) cout << "Ничего не найдено\n";
		return;
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
	fclose(f);
	return;
}
void del(string familia) {
	bool flag = false;
	prepod buf;
	ofstream f2("base_copy.bin");
	ifstream f("base.bin");
	while (f.read((char*)&buf, sizeof(buf)))
	{
		if (familia != buf.familia)
		{
			f2.write((char*)&buf, sizeof(buf));
		}
	}
	f.close();
	f2.close();
	ifstream file2("base_copy.bin");
	ofstream file1("base.bin");
	while (file2.read((char*)&buf, sizeof(buf)))
	{
		file1.write((char*)&buf, sizeof(buf));

	}
	file1.close();
	file2.close();
}
