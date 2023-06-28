#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct gosud {
	string fio;
	string obraz;
	string spesiality;
	string podraz;
	string dolzh;
	double oklad;
	string date;
};

FILE* f;

void input(int size);

void output();

void find(string dolzh);
union gosuds {
	string fio;
	string obraz;
	string spesiality;
	string podraz;
	string dolzh;
	double oklad;
	string date;
};



void main() {
	setlocale(LC_ALL, "rus");
	int size;
	string dolzh;
	int people;
	cout << "1.Ввод нового сторудника" << endl;
	cout << "2.Вывод " << endl;
	cout << "3.Поиск" << endl;
	int a;
	cin >> a;
	switch (a) {
	case 1:
		cout << "Введите количесвто сотрудников" << endl;
		cin >> size;
		input(size);
		break;
	case 2:
		output();
		break;
	case 3:
		cout << "Введите должность для поиска" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, dolzh);
		find(dolzh);
		break;
	}
}

void input(int size) {
	gosud buf;
	int form;
	int i;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Фио" << endl;
			getline(cin, buf.fio);
			for (int i = 0; i < buf.fio.length(); i++) {
				if (buf.fio[i] == '1' || buf.fio[i] == '2' || buf.fio[i] == '3' || buf.fio[i] == '4' || buf.fio[i] == '5' || buf.fio[i] == '6' || buf.fio[i] == '7' || buf.fio[i] == '8' || buf.fio[i] == '9') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Образование" << endl;
			getline(cin, buf.obraz);
			for (int i = 0; i < buf.obraz.length(); i++) {
				if (buf.obraz[i] == '1' || buf.obraz[i] == '2' || buf.obraz[i] == '3' || buf.obraz[i] == '4' || buf.obraz[i] == '5' || buf.obraz[i] == '6' || buf.obraz[i] == '7' || buf.obraz[i] == '8' || buf.obraz[i] == '9') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Специальность" << endl;
			getline(cin, buf.spesiality);
			for (int i = 0; i < buf.spesiality.length(); i++) {
				if (buf.spesiality[i] == '1' || buf.spesiality[i] == '2' || buf.spesiality[i] == '3' || buf.spesiality[i] == '4' || buf.spesiality[i] == '5' || buf.spesiality[i] == '6' || buf.spesiality[i] == '7' || buf.spesiality[i] == '8' || buf.spesiality[i] == '9') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Подразделение" << endl;
			getline(cin, buf.podraz);
			cout << "Должность" << endl;
			getline(cin, buf.dolzh);
			for (int i = 0; i < buf.dolzh.length(); i++) {
				if (buf.dolzh[i] == '1' || buf.dolzh[i] == '2' || buf.dolzh[i] == '3' || buf.dolzh[i] == '4' || buf.dolzh[i] == '5' || buf.dolzh[i] == '6' || buf.dolzh[i] == '7' || buf.dolzh[i] == '8' || buf.dolzh[i] == '9') {
					cout << "Некоректные данные";
					return;
				}
			}
			cout << "Оклад :" << endl;
			cin >> buf.oklad;
			if (buf.oklad <= 0) {
				cout << "Некоректные данные";
				return;
			}
			cout << "Дата" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, buf.date);
			if (sizeof(buf.date) != 40) {
				cout << "Некоректные данные";
				return;
			}
			int year = (buf.date[4] - '0') * 1000 + (buf.date[5] - '0') * 100 + (buf.date[6] - '0') * 10 + buf.date[7] - '0';
			int day = (buf.date[0] - '0') * 10 + (buf.date[1] - '0');
			int month = (buf.date[2] - '0') * 10 + (buf.date[3] - '0');
			if (year > 2023 || day > 31 || month > 12) {
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
	gosud buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.fio << endl;
		cout << buf.obraz << endl;
		cout << buf.spesiality << endl;
		cout << buf.podraz << endl;
		cout << buf.dolzh << endl;
		cout <<"Оклад" << buf.oklad << endl;
		cout << buf.date << endl;
		cout << '\n';
	}
	file.close();
}
void find(string dolzh) {
	bool flag = false;
	gosud buf;
	if (!fopen_s(&f, "base.bin", "r"))
	{
		bool flag = false;
		while (fread(&buf, sizeof(buf), 1, f))
		{
			if (dolzh==buf.dolzh)
			{
				cout << buf.fio << endl;
				cout << buf.obraz << endl;
				cout << buf.spesiality << endl;
				cout << buf.podraz << endl;
				cout << buf.dolzh << endl;
				cout << "Оклад :" << buf.oklad << endl;
				cout << buf.date << endl;
				cout << '\n';
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