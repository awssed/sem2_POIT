#include<iostream>
using namespace std;
double f1(double x);
double f2(double x);
double dihotom(double (*f)(double x), double e);
void main() {
	double e = 0.001;
	cout << "cos(x)+x-7" << endl;
	cout << "x=" << dihotom(f1, e) << endl;
	cout << "e^x -1/x" << endl;
	cout << "x=" << dihotom(f2, e) << endl;
}
double f1(double x) {
	return cos(x)+x-7;
}
//a=0 b=100
double f2(double x) {
	return exp(x) -1/x;
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