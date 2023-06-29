#include<iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
	day dd;
	month mm;
	year yyyy;
};

bool operator < (Date a, Date b) {
	if (a.yyyy < b.yyyy)
		return true;
	else {
		if (a.yyyy>b.yyyy)
			return false;
		else {
			if (a.mm < b.mm)
				return true;
			else {
				if (a.mm > b.mm)
					return false;
				else {
					if (a.dd < b.dd)
						return true;
					else
						return false;
				}
			}
		}
	}
}

bool operator > (Date a, Date b) {
	return a.yyyy > b.yyyy || (a.yyyy == b.yyyy) && (a.mm > b.mm) || (a.yyyy == b.yyyy) && (a.mm == b.mm) && (a.dd > b.dd);
}

bool operator ==(Date a, Date b) {
	return a.yyyy == b.yyyy && a.mm == b.mm && a.yyyy == b.yyyy;
}

void main() {
	setlocale(LC_ALL, "rus");
	Date date1={ 12,02,1970 };
	Date date2 = { 23,04,1923 };
	Date date3 = { 8,10,2021 };
	Date date4 = { 12,02,1970 };
	if (date1 < date2) { 
		cout << "истина" <<endl;
	}
	else {
		cout << "ложь" << endl;
	}
	if (date1 < date3) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
	if (date1 ==date4) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
	if (date1 ==date2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
}