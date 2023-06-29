#include<iostream>
#include"stdafx.h"
string mes(int month);
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	int monthes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string date;
	cout << "Введите дату в формате ДДММГГГГ: ";
	cin >> date;
	if (sizeof(date)!=40) {
		cout << "error";
		return 0;
	}
	for (int i = 0; i < 8; i++) {
		if (int(date[i]) < int('0') || int(date[i]) > int('9')) {
			cout << "error";
			return 0;
		}
	}
	int year = date_fun(date,"year");
	int month = date_fun(date,"month");
	int day = date_fun(date,"day");
	cout << month << '-' << mes(month)<<endl;
	if (day > 31 || month > 12 || day == 0 || month == 0 || year == 0 || month > monthes[month - 1]) {
		cout << "error";
		return 0;
	}
	vis(year);
	int numerday = 0;
	for (int i = 0; i < month; i++) {
		numerday += monthes[i];
	}
	numerday = numerday - (monthes[month - 1] - day);
	cout << "Порядковый номер дня" << numerday << endl;
	cout << days(numerday, year, monthes);
	return 0;
}

