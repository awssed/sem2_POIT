#include<iostream>
#include<cmath>
using namespace std;
int kvadr(int i,int a ...);
void main() {
	cout << kvadr(5, 1, 4, 3, 12, 25);
}
int kvadr(int i,int a ...) {
	int* ptr = &a;
	int number = 0;
	for (; i > 0; i--) {
		cout << sqrt(*(ptr))<<endl;
		ptr = ptr + 2;
	}
	return number;
}