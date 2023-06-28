#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "");
	FILE* fp = fopen("FileA.bin", "w");
	int n;
	cout << "Введите количество чисел:";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}
	fwrite(mas, sizeof(int), n, fp);
	cout << "Последовательность записана" << endl;
	fclose(fp);
	fp = fopen("FileA.bin", "r");
	int* mas2 = new int[n];
	fread(mas2, sizeof(int), n, fp);
	for (int i = 0; i < n; i++) {
		cout << mas2[i]<<endl;
	}
	fclose(fp);
	int* mas3 = new int[n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (mas2[i] > 0) {
			mas3[j] = mas2[i];
			j++;
		}
	}
	fp = fopen("FileB", "w");
	fwrite(mas3, sizeof(int), j, fp);
	fclose(fp);
	fp = fopen("FileB", "r");
	fread(mas, sizeof(int), n, fp);
	cout << "Числа записанные в FileB:" << endl;
	for (int i = 0; i < j; i++) {
		cout << mas[i] << endl;
	}
	fclose(fp);
}