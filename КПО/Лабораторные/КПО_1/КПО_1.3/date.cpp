#include"date.h"
#include"stdafx.h"
int date_fun(string date, string set) {
	int year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + date[7] - '0';
	int month = (date[2] - '0') * 10 + date[3] - '0';
	int day = (date[0] - '0') * 10 + date[1] - '0';
	if (set == "day")
		return day;
	if(set == "month")
		return month;
	if (set == "year")
		return year;
	return 0;
}