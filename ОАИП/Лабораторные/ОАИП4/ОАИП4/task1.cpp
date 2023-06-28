#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include <cstdlib>
using namespace std;
#include <limits>

FILE *f;
FILE* f2;
errno_t err;

struct car
{
	string model;
	string color;
	string number;
	int date_reales;
	string type;
	int date_techosm;
	string owner;
};
void input(int size);
void output();
void find(string owner);
void del(string owner);

void main() {
	setlocale(LC_ALL, "rus");
	car* a= new  car[10];
	string owner1;
	string owner;
	for (;;) {
		start:
		cout << "\n1.���� ������ � ���������� � ������ � ����\n";
		cout << "2.����� ������ �� �����\n";
		cout << "3.����� �� ���������\n";
		cout << "4.�������� ��������\n\n";
		cout << "������� ����� ��������: ";
		int q;
		cin >> q;
		switch (q)
		{
		case 1:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ���������� ����������� ������� ����� ��������" << endl;
			int n;
			cin >> n;
			input(n);
			return;
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "������� ��������� ��� ������" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, owner);
			find(owner);
			break;
		case 4:
			cout << "������� ��������� ��� ��������" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, owner1);
			del(owner1);
			break;
		}
	}

}
void input(int size) {
	car buf;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		time_t now = time(0);

		tm* ltm = localtime(&now);
		int year = 1900 + ltm->tm_year;
		for (int p = 0; p < size; p++)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ����� ����: " << endl;
			getline(cin, buf.model);
			cout << "������� ���� ����: ";
			getline(cin, buf.color);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ��������� ����� ����: ";
			getline(cin, buf.number);
			cout << "������� ���� �������: ";
			cin>>buf.date_reales;
			if (buf.date_reales > year) {
				cout << "����������� ���";
				return;
				fclose(f);
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ("������� ��� ������: ");
			getline(cin, buf.type);
			cout << "������� ���� ���������� ����������: ";
			cin>>buf.date_techosm;
			if (buf.date_techosm > year) {
				cout << "����������� ���";
				return;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ���������: ";
			getline(cin, buf.owner);
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
		car buf;
		while (file.read((char*)&buf, sizeof(buf))) {
			cout << buf.model << endl;
			cout << buf.color << endl;
			cout << buf.number << endl;
			cout << buf.date_reales << endl;
			cout << buf.type << endl;
			cout << buf.date_techosm << endl;
			cout << buf.owner << endl;
			cout << '\n';
		}
		file.close();
}
void find(string owner) {
		bool flag = false;  
		car buf;
		if (!fopen_s(&f, "base.bin", "r"))
		{
			bool flag = false;
			while (fread(&buf, sizeof(buf), 1, f))
			{
				if (owner==buf.owner) 
				{
					cout << buf.model << endl;
					cout << buf.color << endl;
					cout << buf.number << endl;
					cout << buf.date_reales << endl;
					cout << buf.type << endl;
					cout << buf.date_techosm << endl;
					cout << buf.owner << endl;
					cout << '\n';
					flag = true;
				}
			}
			if (flag=false) cout << "������ �� �������\n";
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
void del(string owner){
	bool flag = false;
	car buf;
	ofstream f2("base_copy.bin");
	ifstream f("base.bin");
		while (f.read((char*)&buf, sizeof(buf)))
		{
			if (owner != buf.owner)
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