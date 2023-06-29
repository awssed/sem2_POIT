#include"stdafx.h"
int razn(string date1, string date2) {
	int monthes1[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year1 = date_fun(date1, "year");
	int month1 = date_fun(date1, "month");
	int day1 = date_fun(date1, "day");
	int year2 = date_fun(date2, "year");
	int month2 = date_fun(date2, "month");
	int day2 = date_fun(date2, "day");
	if (year1 == year2) {
		int numerday1 = 0;
		for (int i = 0; i < month1; i++)
		{
			numerday1 += monthes1[i];
		}
		numerday1 = numerday1 - (monthes1[month1 - 1] - day1);
		int numerday2 = 0;
		for (int i = 0; i < month2; i++)
		{
			numerday2 += monthes1[i];
		}
		numerday2 = numerday2 - (monthes1[month2 - 1] - day2);
		return abs(numerday2 - numerday1);
	}
	int all_days1 = year1 * 365;
	for (int i = month1 - 1; i < 12; i++) {
		all_days1 = all_days1 - monthes1[i];
	}
	all_days1 += day1;
	int all_days2 = year2 * 365;
	for (int i = month2 - 1; i < 12; i++) {
		all_days2 = all_days2 - monthes1[i];
	}
	all_days2 += day2;
	return abs(all_days1 - all_days2);
}