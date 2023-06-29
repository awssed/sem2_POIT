
#include"stdafx.h"
bool vis(int year) {
	if (year % 400 == 0) {
		cout << "Високосный год" << endl;
		return true;
	}
	if (year % 100 == 0) {
		cout << "Не високосный год" << endl;
		return false;
	}
	if (year % 4 == 0) {
		cout << "Високосный год" << endl;
		return false;
	}
	cout << "Не висоскосный год" << endl;
	return false;
}