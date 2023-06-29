#include"stdafx.h"
int razn_hour(string date1) {
	time_t now = time(0);

	tm* ltm = localtime(&now);
	int year= 1900 + ltm->tm_year ;
	int month =1 + ltm->tm_mon;
	int day= ltm->tm_mday ;
	int hour = 1 + ltm->tm_hour;
	int monthes1[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year2 = date_fun(date1, "year");
	int month2 = date_fun(date1, "month");
	int day2 = date_fun(date1, "day");
	if (year > year2) {
			return 0;
	}
	if (month==month2 && day>day2&&year==year2) {
		return 0;
	}
	if (month > month2 && year==year2) {
		return 0;
	}

	if (year == year2) {
		int numerday1 = 0;
		for (int i = 0; i < month; i++)
		{
			numerday1 += monthes1[i];
		}
		numerday1 = numerday1 - (monthes1[month - 1] - day);
		int numerday2 = 0;
		for (int i = 0; i < month2; i++)
		{
			numerday2 += monthes1[i];
		}
		numerday2 = numerday2 - (monthes1[month2 - 1] - day2);
		return abs(numerday2 - numerday1)*24-hour;
	}
	int all_days1 = year * 365;
	for (int i = month - 1; i < 12; i++) {
		all_days1 = all_days1 - monthes1[i];
	}
	all_days1 += day;
	int all_days2 = year2 * 365;
	for (int i = month2 - 1; i < 12; i++) {
		all_days2 = all_days2 - monthes1[i];
	}
	all_days2 += day2;
	return abs(all_days1 - all_days2)*24-hour;
}