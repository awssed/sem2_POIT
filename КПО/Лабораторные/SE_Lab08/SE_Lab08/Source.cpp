#include<iostream>
using namespace std;
double  _stdcall defaultparm1(int a=1, int b=2,...) {
	int* p = &a;
	int count=0;
	int sum = 0;
	while (*p>0) {
		sum +=*p;
		p = p + 2;
		count++;
	}
	return sum / count;
}
double defaultparm(int a, int b, int c, int d, int e, int i = 7, int k = 8) {
	int sum = a + b + c + d + e + i + k;
	return sum / 7;
}
void main() {
	int x1= defaultparm(1, 2,3, 4, 5);
	int x2= defaultparm(1, 2, 3, 4, 5,8,9);

}