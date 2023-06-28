#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

FILE* f;

void input(int size);

void output();

void del(string name);

void find(int people);

enum formC {
	monarchy = 1,
	republic,
	federation
};
struct gosud {
	string name;
	string capital;
	formC formG;
	int people;
	double size;
};



void main() {
	setlocale(LC_ALL, "rus");
	int size;
	string name;
	int people;
		cout << "1.���� ������ ������������" << endl;
		cout << "2.����� ���� ����������" << endl;
		cout << "3.��������" << endl;
		cout << "4.�����" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1:
			cout << "������� ���������� �����" << endl;
			cin >> size;
			input(size);
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "������� ����������� ������� ����� �������" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			del(name);
			break;
		case 4:
			cout << "������� ���������� ��������� ��� ������" << endl;
			cin >> people;
			find(people);
			break;
		}
	}

void input(int size) {
	gosud buf;
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
			cout << "������� �������� �����������" << endl;
			getline(cin, buf.name);
			for (int i = 0; i < buf.name.length(); i++) {
				if (buf.name[i] == '1' || buf.name[i] == '2' || buf.name[i] == '3' || buf.name[i] == '4' || buf.name[i] == '5' || buf.name[i] == '6' || buf.name[i] == '7' || buf.name[i] == '8' || buf.name[i] == '9') {
					cout << "����������� ������";
					return;
				}
			}
			cout << "������� �������" << endl;
			getline(cin, buf.capital);
			for (int i = 0; i < buf.capital.length(); i++) {
				if (buf.capital[i] == '1' || buf.capital[i] == '2' || buf.capital[i] == '3' || buf.capital[i] == '4' || buf.capital[i] == '5' || buf.capital[i] == '6' || buf.capital[i] == '7' || buf.capital[i] == '8' || buf.capital[i] == '9') {
					cout << "����������� ������";
					return;
				}
			}
			cout << "������� ����� ���������:1.��������  2.����������  3.���������" << endl;
			cin >> i;
			if (i > 3) {
				cout << "error" << endl;
				return;
			}
			buf.formG = (formC)i;
			cout << "������� ���-�� ���������" << endl;
			cin >> buf.people;
			cout << "������� �������" << endl;
			cin >> buf.size;
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
	gosud buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.name << endl;
		cout << buf.capital << endl;
		switch (buf.formG) {
		case formC::monarchy:
			cout << "��������" << endl;
			break;
		case formC::republic:
			cout << "����������" << endl;
			break;
		case formC::federation:
			cout << "���������" << endl;
			break;
		}
		cout << "���������:" << buf.people << endl;
		cout << "������:" << buf.size << endl;
		cout << '\n';
	}
	file.close();
}
void del(string name) {
	bool flag = false;
	gosud buf;
	ofstream f2("base_copy.bin");
	ifstream f("base.bin");
	while (f.read((char*)&buf, sizeof(buf)))
	{
		if (name != buf.name)
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
void find(int people) {
	bool flag = false;
	gosud buf;
	if (!fopen_s(&f, "base.bin", "r"))
	{
		bool flag = false;
		while (fread(&buf, sizeof(buf), 1, f))
		{
			if (people<=buf.people)
			{
				cout << buf.name << endl;
				cout << buf.capital << endl;
				switch (buf.formG) {
				case formC::monarchy:
					cout << "��������" << endl;
					break;
				case formC::republic:
					cout << "����������" << endl;
					break;
				case formC::federation:
					cout << "���������" << endl;
					break;
				}
				cout << "���������:" << buf.people << endl;
				cout << "������:" << buf.size << endl;
				cout << '\n';
				flag = true;
			}
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