#include<iostream>
using namespace std;
double f1(double x);
double f2(double x);
double dihotom(double (*f)(double x), double e);
void main() {
	double e = 0.001;
	cout << "2-x^2+x" << endl;
	cout << "x=" << dihotom(f1, e) << endl;
	cout << "sin(x)^2+0.2" << endl;
	cout << "x=" << dihotom(f2, e) << endl;
}
double f1(double x) {
	return 2-pow(x,2)+x;
}
double f2(double x) {
	return pow(sin(x),2)+0.2;
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
