#include "days.h"
#include"stdafx.h"
int days(int numerday, int year, int* monthes) {
	cout << "Ââåäèòå äàòó ÄÐ â ôîðìàòå ÄÄÌÌÃÃÃÃ" << endl;
	string dateofborn;
	cin >> dateofborn;
	if (sizeof(dateofborn) != 28) {
		cout << "error";
		return 0;
	}
	int yearo_of_born = date_fun(dateofborn,"year");
	int month_of_born = date_fun(dateofborn,"month");
	int day_of_born = date_fun(dateofborn,"day");
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