#include<iostream>
using namespace std;
double f1(double x);
double f2(double x);
double dihotom(double (*f)(double x), double e);
void main() {
	double e = 0.001;
	cout << "x^2+4x-2" << endl;
	cout << "x=" << dihotom(f1, e) << endl;
	cout << "sin(x)+0.1" << endl;
	cout << "x=" << dihotom(f2, e) << endl;
}
double f1(double x) {
	return pow(x,2)+4*x-2;
}
//a=0 b=100
double f2(double x) {
	return sin(x)+0.1;
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
