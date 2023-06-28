#include<iostream>
#include <iomanip>
#include<time.h>
#include <chrono>
using namespace std;
void main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int A[1000];
	int B[1000];
	int C[1000];
	int n;
	cout << "������� ��������� ��������� ��� ��������"<<endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 50;
		B[i] = rand() % 30;
	}
	cout << "������ A:" << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << "  ";
	}
	cout << endl;
	cout << "������ B:" << endl;
	for (int i = 0; i < n; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	int maxB = -99;
	for (int i = 0; i < n; i++) {
		if (B[i] > maxB) {
			maxB = B[i];
		}
	}
	cout << "������������ ������� ������� B: " << maxB << endl;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > maxB) {
			C[c] = A[i];
			c++;
		}
	}
	cout << "������ �:" << endl;
	for (int i = 0; i < c; i++) {
		cout << C[i] << ' ';
	}
	cout << endl;
	int c1[1000], c2[1000];
	for (int i = 0; i < c; i++) {
		c1[i] = C[i];
		c2[i] = C[i];
	}
	cout << "����������� ����������" << endl;
	int temp;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < c; i++)
	{
		for (int j = i; j < c; j++)
		{
			if (c1[i] < c1[j]) swap(c1[i], c1[j]);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float>duration = end - start;
	cout << "��������� �����: " << duration.count() << " ������" << endl;
	for (int i = 0; i < c; i++) {
		cout <<c1[i] << ' ';
	}
	int max_idx;
	cout << endl;
	cout << "��������� �������" << endl;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < c - 1; i++) {
		max_idx = i;
		// ������� ������ ����������� �������� � ����������������� ����� �������
		for (int j = i + 1; j < n; j++) {
			if (c2[j] > c2[max_idx]) {
				max_idx = j;
			}
		}
		// ����� ���������� �������� � ����������� ���������
		int temp = c2[i];
		c2[i] = c2[max_idx];
		c2[max_idx] = temp;
	}
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "��������� �����: " << duration.count() << " ������" << endl;
	for (int i = 0; i < c; i++) {
		cout << c2[i] << ' ';
	}
}