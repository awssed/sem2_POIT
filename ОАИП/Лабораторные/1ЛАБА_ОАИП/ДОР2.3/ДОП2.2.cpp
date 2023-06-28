#include<iostream>
using namespace std;
int fsum(int i, ...);
void main() {
	cout << fsum(6, 1, 2, 3, 4, 5, 6)<<endl;
	cout << fsum(3, 1, 2, 3)<<endl;
	cout << fsum(4, 5, 3, 2, 4)<<endl;
}
int fsum(int i, ...) {
	int* ptr = &i;
	int result = 0;
	for (; i-1 > 0; i--) {
		ptr = ptr + 2;
		result = result + *ptr * (*(ptr + 2));
	}
	return result;
}