#include<iostream>
#include <conio.h>
#include <math.h>
using namespace std;

double fun(double x);
double dihotom(double (*f)(double x), double e);

void main() {
	bool Task4_1 = true;
	bool Task4_2 = false;
	char Task5_1 = 'a';
	char Task5_2 = 's';
	char Task6 = 'a';
	wchar_t Task7 = L's';
	wchar_t Task8 = L'ñ';
	//0000000 00000101 -> 1000000 00000101->1111111 11111010 -> ff fb

	cout << "task9:" << endl;
	short p1 = 5;
	short p2 = -5;
	cout << hex << p1 << endl;//5
	cout << hex << p2 << endl;//fffb

	cout << "task10:" << endl;
	short max10 = 0;
	while (max10 <= 0) {
		max10--;
	}
	short min10 = 0;
	while (min10 >= 0) {
		min10++;
	}
	cout << hex << max10 << endl;//7fff
	cout <<hex<< min10 << endl;

	cout << "task11:" << endl;
	unsigned short max11 = 0;
	unsigned short min11 = 0;
	while (max11 <= 0) {
		max11--;
	}
	while (min11 > 0) {
		min11++;
	}
	cout << hex << max11 << endl;//ffff
	cout << hex << min11 << endl;//0

	cout << "task12" << endl;
	int y1 = 53;//35
	int y2 = -53;//ffffffcb

	cout << "task13:" << endl;
	int task13_1 = INT_MAX;//7fffffff
	int task12_2 = INT_MIN;//80000000

	cout << "task14" << endl;
	unsigned int task14_1= UINT_MAX;//ffffffff
	unsigned int task14_2 = 0;//0

	cout << "task15" << endl;
	long z1 = 55;//37
	long z2 = -55;//ffffffc9

	cout << "Task16" << endl;
	long task16_1 = LONG_MAX;//7fffffff
	long task16_2 = LONG_MIN;//80000000
	cout << hex << LONG_MAX << endl;
	cout << dec << LONG_MAX << endl;
	cout << hex << LONG_MIN << endl;
	cout << dec << LONG_MIN << endl;

	cout << "Task17:" << endl;
	unsigned long task17_1 = ULONG_MAX;//ffffffff
	unsigned long task17_2 = 0;

	cout << "Task18:" << endl;
	float s1 = 110.345;//a4 b0 dc 42
	float s2 = -110.345;//a4 b0 dc c2
	char s[100];

	cout << "Task19:" << endl;
	float a = 13.1;//402A333333333333
	float b = -13.2;//C02A33333333333
	float zero = 0.0;
	float f1 = a / zero;
	float f2 = b / zero;
	double f4 = sqrt(-1.2);
	cout << "Tassk20:" << endl;

	char char_a = 'a';
	wchar_t wchar_t_a = L'a';
	short short_a = 10;
	int int_a = 15;
	float float_a = 10.521;
	double double_a = 20.487;

	char* char_p = &char_a;//61
	wchar_t* wchar_t_p = & wchar_t_a;//61 00
	short* short_p = &short_a;//0a 00
	int* int_p = &int_a;//0f 00 00 00
	float* float_p=& float_a;//04 56 28 41
	double* double_p = &double_a;//e9 26 31 08 ac 7c 34 40

	char_p+=3;
	wchar_t_p +=3;
	short_p +=3;
	int_p+=3;
	float_p += 3;
	double_p+=3;

	cout << "Task21" << endl;
	double e = 0.001;
	double (*fun_p)(double) = fun;
	fun_p(1.0);
}
double fun(double x) {
	return exp(x) - 1 / x;
}

double dihotom(double (*f)(double x), double e) {
	double a;
	double b;
	cout << "a:";
	cin >> a;
	cout << "b:";
	cin >> b;
	double x;
	while (b - a > 2 * e) {
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
		if (x == 0) {
			break;
		}
	}
	return x;
}