#include<iostream>
using namespace std;
int days(int numerday, int year, int* monthes);
int vis(int year);
int date_fun(string date, string set);
int main() {
	setlocale(LC_ALL, "");
	int monthes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string date;
	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> date;
	for (int i = 0; i < 8; i++) {
		if (int(date[i]) < int('0') || int(date[i]) > int('9')) {
			cout << "error";
			return 0;
		}
	}
	int year = date_fun(date, "year");
	int month = date_fun(date, "month");
	int day = date_fun(date, "day");
	if(day>31||month>12||day==0||month==0||year==0 || month> monthes[month-1]) {
		cout << "error";
		return 0;
	}
	vis(year);
	int numerday = 0;
	for (int i = 0; i < month; i++) {
		numerday += monthes[i];
	}
	numerday = numerday - (monthes[month-1] - day);
	cout <<"Порядковый номер дня"<< numerday<<endl;
	cout << days(numerday, year, monthes);
	return 0;
}
int days(int numerday, int year, int* monthes) {
	cout << "Введите дату ДР в формате ДДММГГГГ" << endl;
	string dateofborn;
	cin >> dateofborn;
	if (sizeof(dateofborn) != 28) {
		cout << "error";
		return 0;
	}
	int yearo_of_born = date_fun(dateofborn , "year");
	int month_of_born = date_fun(dateofborn , "month");
	int day_of_born = date_fun(dateofborn , "day");
	int numerday_born = 0;
	vis(year);
	for (int i = 0; i < month_of_born; i++) {
		numerday_born += monthes[i];
	}
	numerday_born = numerday_born - (monthes[month_of_born - 1] - day_of_born);
	int days_to_born = numerday_born - numerday;
	if (days_to_born < 0) {
		days_to_born += 365;
		if (year % 4 == 0) {
			days_to_born += 1;
		}
	}
	return days_to_born;
}
int vis(int year) {
	if (year % 400 == 0) {
		cout << "Високосный год"<<endl;
		return 0;
	}
	if (year % 100 == 0) {
		cout << "Не високосный год"<<endl;
		return 0;
	}
	if (year % 4 == 0) {
		cout << "Високосный год"<<endl;
		return 0;
	}
	cout << "Не висоскосный год"<<endl;
	return 0;
}
int date_fun(string date, string set) {
	int year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + date[7] - '0';
	int month = (date[2] - '0') * 10 + date[3] - '0';
	int day = (date[0] - '0') * 10 + date[1] - '0';
	if (set == "day")
		return day;
	if (set == "month")
		return month;
	if (set == "year")
		return year;
	return 0;
}