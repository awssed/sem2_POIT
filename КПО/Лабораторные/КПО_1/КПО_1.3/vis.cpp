
#include"stdafx.h"
bool vis(int year) {
	if (year % 400 == 0) {
		cout << "���������� ���" << endl;
		return true;
	}
	if (year % 100 == 0) {
		cout << "�� ���������� ���" << endl;
		return false;
	}
	if (year % 4 == 0) {
		cout << "���������� ���" << endl;
		return false;
	}
	cout << "�� ����������� ���" << endl;
	return false;
}