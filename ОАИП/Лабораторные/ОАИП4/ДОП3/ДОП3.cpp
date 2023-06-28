#include <iostream>
#include <fstream>
#include <string>


using namespace std;

FILE* f;

void input(int size);
void output();
void find(string name);

struct camp {
	string campName;
	string campPlace;
	string campType;
	int voucher;
};

void main() {
	setlocale(LC_ALL, "rus");
	for (;;) {
		cout << "1.���� ������ ���������" << endl;
		cout << "2.������ ���� ������� ����������" << endl;
		cout << "3.����� ��������� �� ��������" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1:
			input(1);
			break;
		case 2:
			output();
			break;
		case 3:
			cout << "����� ������� �� ��������" << endl;
			string name;
			cin.ignore(numeric_limits<streamsize>::max (), '\n');
			getline(cin, name);
			find(name);

		}
	}
}
void input(int size) {
	camp buf;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "�������� ��������� " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, buf.campName);
			cout << "����� ������������: ";
			getline(cin, buf.campPlace);
			cout << "�������� �������: ";
			getline(cin, buf.campType);
			cout << "���������� �������: ";
			cin >> buf.voucher;
			fwrite(&buf, sizeof(camp), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
	}
	return;
}
void output() {
	camp buf;
	ifstream file("base.bin");
	while (file.read((char*)&buf, sizeof(buf))) {
		cout << "�������� ������: " << buf.campName << "\t";
		cout << "����� ������: " << buf.campPlace << "\t";
		cout << "������� �������: " << buf.campType << "\t\t";
		cout << "���������� �������: " << buf.voucher << "\t" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	}
}
void find(string name) {
	camp buf;
	ifstream file("base.bin");
	while (file.read((char*)&buf, sizeof(buf))) {
		if (name == buf.campName) {
			cout << "�������� ������: " << buf.campName << "\t";
			cout << "����� ������: " << buf.campPlace << "\t";
			cout << "������� �������: " << buf.campType << "\t\t";
			cout << "���������� �������: " << buf.voucher << "\t" << endl;
			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
}
