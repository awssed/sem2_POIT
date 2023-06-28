#include<iostream>
using namespace std;
int fmin(int i, ...);
void main() {
	cout << fmin(5, 1, 2, 4, 3, 5)<<endl;
	cout << fmin(3, 1, 2, 3);
	cout << fmin(6, 5, 3, 2, 6, 4, 8);
}
int fmin(int i, ...) {
	int min = 999;
	int* ptr = &i + 1;
	for (; i > 0; i--) {
		if (*ptr < min) {
			min = *ptr;
		}
		ptr++;
	}
	return min;
}