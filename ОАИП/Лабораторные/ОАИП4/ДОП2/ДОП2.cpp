#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct train {
	string move_to;
	int number;
	string time;
};
void input();
void output();
void find(string);

void main() {
	setlocale(LC_ALL, "rus");
	int a;
	for (;;) {
		cout << "1.Ввод данных" << endl;
		cout << "2.Вывод" << endl;
		cout << "3.Поиск по времени" << endl;
	cin >> a;
		switch (a) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "Введите время для поиска" << endl;
			string time;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, time);
			find(time);
			break;
		}
	}
}
void input() {
	ofstream f("base.bin");
	train buf[2];
	for (int i = 0; i < 2; i++) {
		cout << "Коненчный пункт"<<endl;
		cin >> buf[i].move_to;
		cout << "Номер поезда"<<endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >>buf[i].number;
		cout << "Время" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, buf[i].time);
	}
	train buf1[2];
	char first = 'A';
	int num = 0;
	char first_buf;
	for (int i = 0; i < 26; i++) {
		for (int i = 0; i < 2; i++) {
			 first_buf = buf[i].move_to[0];
			if (buf[i].move_to[0] == first) {
				buf1[num] = buf[i];
				num++;
			}
		}
		first++;
	}
	f.write((char*)&buf1, sizeof(buf));
	f.close();
}
void output() {
	ifstream file("base.bin");
	train buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.move_to << endl;
		cout << buf.number << endl;
		cout << buf.time << endl;
		cout << '\n';
	}
	file.close();
}
void find(string time) {
	int hour = (time[0] - '0') * 10 + (time[1] - '0');
	int minute = (time[3] - '0') * 10 + (time[4] - '0');
	int all_minuts = hour * 60 + minute;
	ifstream file("base.bin");
	train buf;
	bool flag = false;
	while (file.read((char*)&buf, sizeof(buf))) {
		int buf_hour = (buf.time[0] - '0') * 10 + (buf.time[1] - '0');
		int buf_minute = (buf.time[3] - '0') * 10 + (buf.time[4] - '0');
		int buf_minuts = buf_hour * 60 + buf_minute;
		if (buf_minuts >= all_minuts) {
			cout << buf.move_to << endl;
			cout << buf.number << endl;
			cout << buf.time << endl;
			cout << '\n';
			flag = true;
		}
	}
	if (flag == false) {
		cout << "Поездов нет" << endl;
	}
	file.close();
}