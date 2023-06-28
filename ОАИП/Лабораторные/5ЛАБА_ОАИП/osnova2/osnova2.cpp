
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#undef max
using namespace std;
struct person {
	string fio;
	string date;
	string adres;
	char gender;
};

FILE *f;

void input(int size);
void output();
void find(string year);

union persons {
	string fio;
	string date;
	string adres;
	char gender;
};

void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a;
	int size;
	string year;
	cout << "1.���� ������ ��������" << endl;
	cout << "2.�����" << endl;
	cout << "3. �����" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cin >> size;
		input(size);
		break;
	case 2:
		output();
		break;
	case 3:
		cout << "������� ��� ��� ������" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, year);
		for (int i = 0; i < year.length(); i++) {
			if (year[i] != '1' && year[i] != '2' && year[i] != '3' && year[i] != '4' && year[i] != '5' && year[i] != '6' && year[i] != '7' && year[i] != '8' && year[i] != '9'&&year[i]!='0') {
				cout << "����������� ������";
				return;
			}
		}
		int year1 = stoi(year);
		if (year1 > 2023) {
			cout << "����������� ������";
			return;
		}
		find(year);
		break;
	}

}

void input(int size) {
	person buf;
	int form;
	int year;
	int day;
	int month;
	int i;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ���" << endl;
			getline(cin, buf.fio);
			for (int i = 0; i < buf.fio.length(); i++) {
				if (buf.fio[i] == '1' || buf.fio[i] == '2' || buf.fio[i] == '3' || buf.fio[i] == '4' || buf.fio[i] == '5' || buf.fio[i] == '6' || buf.fio[i] == '7' || buf.fio[i] == '8' || buf.fio[i] == '9') {
					cout << "����������� ������";
					return;
				}
			}
			cout << "������� ���� ��������" << endl;
			getline(cin, buf.date);
			for (int i = 0; i < buf.date.length(); i++) {
				if (buf.date[i] != '1' && buf.date[i] != '2' && buf.date[i] != '3' && buf.date[i] != '4' && buf.date[i] != '5' && buf.date[i] != '6' && buf.date[i] != '7' && buf.date[i] != '8' && buf.date[i] != '9'&& buf.date[i]!='0') {
					cout << "����������� ������";
					return;
				}
			}

				int year = (buf.date[4] - '0') * 1000 + (buf.date[5] - '0') * 100 + (buf.date[6] - '0') * 10 + buf.date[7] - '0';
				int day = (buf.date[0] - '0') * 10 + (buf.date[1] - '0');
				int month = (buf.date[2] - '0') * 10 + (buf.date[3] - '0');
				if (year > 2023 || day > 31 || month > 13) {
					cout << "����������� ������";
					return;
				}
				cout << "������� �����" << endl;
				getline(cin, buf.adres);
				cout << "������� ���: � ��� �";
				cin >> buf.gender;
				if (buf.gender != '�' && buf.gender != '�') {
					cout << "���������� ������" << endl;
					return;
				}
				fwrite(&buf, sizeof(buf), 1, f);
				cout << '\n';
			}
			fclose(f);
	}
	else {
		cout << "������ �������� �����";
	}
	return;
}

void output() {
	ifstream file("base.bin");
	person buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.fio << endl;
		cout << buf.date << endl;
		cout << buf.adres << endl;
		cout << "���: " << buf.gender << endl;
		cout << '\n';
	}
	file.close();
}

void find(string year) {
	bool flag = false;
	int q = 0;
	person buf;
	string person_year;
	
	if (!fopen_s(&f, "base.bin", "r"))
	{
		bool flag = false;
		while (fread(&buf, sizeof(buf), 1, f))
		{
			for (int i = 4; i < 8; i++) {
				person_year += buf.date[i];
			}
			if (year == person_year)
			{
				cout << buf.fio << endl;
				cout << buf.date << endl;
				cout << buf.adres << endl;
				cout << "���: " << buf.gender << endl;
				cout << '\n';
				cout << '\n';
				flag = true;
			}
			person_year.clear();
		}
		if (flag = false) cout << "������ �� �������\n";
		return;
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
	fclose(f);
	return;
}
