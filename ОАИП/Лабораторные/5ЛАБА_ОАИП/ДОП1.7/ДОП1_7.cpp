#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include <cstdlib>
using namespace std;
#include <limits>

FILE* f;
FILE* f2;
errno_t err;

enum prosents {
	p5 = 5,
	p7 = 7,
	p11=11,
	p20=20,
	p25=25,
	p30=30

};

struct tovar
{
	string name;
	int num;
	double cost;
	prosents prosent;
};
void input(int size);
void output();
void find(int cost);
void del(string name);

void main() {
	setlocale(LC_ALL, "rus");
	tovar* a = new  tovar[10];
	double cost;
	string name;

	for (;;) {
	start:
		cout << "\n1.���� ������ � ���������� � ������ � ����\n";
		cout << "2.����� ������ �� �����\n";
		cout << "3.����� �� ����\n";
		cout << "4.�������� ��������\n\n";
		cout << "������� ����� ��������: ";
		int q;
		cin >> q;
		switch (q)
		{
		case 1:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ���������� �������" << endl;
			int n;
			cin >> n;
			input(n);
			return;
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "������� ���� ��� ������" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> cost;
			find(cost);
			break;
		case 4:
			cout << "������� �������� ��� ��������" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			del(name);
			break;
		}
	}

}
void input(int size) {
	tovar buf;
	int model;
	int i;
	if (!fopen_s(&f, "base.bin", "ab"))
	{

		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������� ������" << endl;
			getline(cin, buf.name);
			cout << "������� ��������� ������" << endl;
			cin >> buf.cost;
			cout << "������� ����������" << endl;
			cin >> buf.num;
			cout << "������� ������� ��������:5, 7, 11, 20, 25, 30"<<endl;
			cin >> i;
			if (i != 5 && i != 7 && i != 11 && i != 20 && i != 25 && i != 30) {
				cout << "error" << endl;
				return;
			}
			buf.prosent = prosents(i);
			fwrite(&buf, sizeof(buf), 1, f);
		}
		
			
			fclose(f);
			cout << '\n';
		
	}
	else {
		cout << "������ �������� �����";
	}
	return;
	}


void output() {
	ifstream file("base.bin");
	tovar buf;
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << buf.name<<endl;
		cout <<"���� " << buf.cost<<endl;
		cout <<"���������� " << buf.num<<endl;
		switch (buf.prosent) {
		case 5:
			cout << "5 ���������"<<endl;
			break;
		case 7:
			cout << "7 ���������"<<endl;
			break;
		case 11:
			cout << "11 ���������"<<endl;
			break;
		case 20:
			cout << "20 ���������"<<endl;
			break;
		case 25:
			cout << "25 ���������"<<endl;
			break;
		case 30:
			cout << "30 ��������"<<endl;
		}
		
		cout << '\n';
	}
	file.close();
}
void find(int cost) {
	bool flag = false;
	tovar buf;
	fopen_s(&f, "base.bin", "r");
	while (fread(&buf, sizeof(buf), 1, f))
	{
		if (cost <= buf.cost)
		{
			cout << buf.name << endl;
			cout << "���� " << buf.cost << endl;
			cout << "���������� " << buf.num << endl;
			switch (buf.prosent) {
			case 5:
				cout << "5 ���������" << endl;
				break;
			case 7:
				cout << "7 ���������" << endl;
				break;
			case 11:
				cout << "11 ���������" << endl;
				break;
			case 20:
				cout << "20 ���������" << endl;
				break;
			case 25:
				cout << "25 ���������" << endl;
				break;
			case 30:
				cout << "30 ��������" << endl;
				break;
			}
			cout << '\n';
			flag = true;
		}

	}
	if (flag = false) cout << "������ �� �������\n";
	return;
	fclose(f);
	return;
}

void del(string name) {
	bool flag = false;
	tovar buf;
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