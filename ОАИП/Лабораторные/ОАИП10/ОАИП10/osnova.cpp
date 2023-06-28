#include<iostream>
using namespace std;
int F(int m, int n);

void main() {
	int m;
	int n;
	cout << "Enter m:";
	cin >> m;
	cout << "Enter n:";
	cin >> n;
	if (m < 0 || n < 0) {
		cout << "error";
		return;
	}
	cout<<"result:"<<F(m, n);
}
int F(int m, int n) {
	if (m == 0 || n == 0) {
		n++;
		return n;
	}
	cout << "m=" << m << endl;
	cout << "n=" << n << endl;
	cout << endl;
	return F(m - 1, F(m, n - 1));

}