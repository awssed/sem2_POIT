#include<iostream>
using namespace std;
int fmin(int i, ...);
void main() {
	cout << fmin(5, 22, 22, 10, 23, 25) << endl;
	cout << fmin(3, 1, 2, 3) << endl;
	cout << fmin(6, 5, 3, 2, 6, 4, 8) << endl;
}
int fmin(int i, ...) {
	int min = 999;
	int* ptr = &i + 2;
	for (; i > 0; i--) {
		if (*ptr < min) {
			min = *ptr;
		}
		ptr = ptr + 2;
	}
	return min;
}