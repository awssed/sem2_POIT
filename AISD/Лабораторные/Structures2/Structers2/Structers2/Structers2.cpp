#include<iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	int N;
	cout << "������� ����� N:" << endl;
	int count = 0;
	cin >> N; 
	int Nmax = N;
	int Nmid = N/2;
	int Nmin = 1;
	for (int i = 0; i < log2(N);i++) {
		int a;
		cout << "1-����" << endl;
		cout << "2-�����" << endl;
		cout << "3-������" << endl;
		cout << Nmid<<endl;
		cin >> a;
		switch (a) {
		case 1:
			if (count == int(log2(N))-1) {
				Nmid++;
				break;
			}
			Nmin = Nmid+1;
			Nmid = ((Nmax + Nmin) / 2);
			  
			break;
		case 2:
			if (count == int(log2(N)) - 1) {
				Nmid--;
				break;
			}
			Nmax = Nmid-1;
			Nmid = (Nmin+Nmax)/2;
			break;
		case 3:break;
		default:i-1;

			break;
		}
		if (a == 3)
			break;
		count++;
	}
	cout << "��� ���� ����� �������!"<<endl;
	cout << Nmid<<endl;
	cout << "������������ ����� �������� �����: " <<ceil( log2(N));
}