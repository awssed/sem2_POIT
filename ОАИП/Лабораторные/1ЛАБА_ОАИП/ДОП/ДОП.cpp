#include<iostream>
using namespace std;
int fmin(int i, ...);
void main() {
	cout << fmin(5, 1, 2, 4, 3, 5);
}
int fmin(int i, ...) {
	int min = 999;
	int* ptr = &i;
	for (; i > 0; i--) {
		if (*(ptr=ptr+2) < min) {
			min = *ptr;
		}
	}
	return min;
}