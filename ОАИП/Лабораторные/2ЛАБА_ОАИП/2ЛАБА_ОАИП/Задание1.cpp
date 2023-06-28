#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	setlocale (LC_ALL , "");
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "FileA.bin", "w");
	if (err != 0)
	{
		perror("ошибка открытия a.txt");
		return EXIT_FAILURE;
	}

	int* mas;
	int n;
	cout << "Введите количесвто чисел"<<endl;
	cin >> n;
	mas = new int[n];
	int* mas2 = new int[n];
	cout << "Введите последовательность чисел"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}
	fwrite(mas, sizeof(int), n, fp);
	cout << "Последовательность записана"<<endl;
	fclose(fp);
	cout << "Что записано в файле:"<<endl;
	err = fopen_s(&fp, "FileA.bin", "r");
	fread(mas2,sizeof(int),n,fp);
	for (int i = 0; i < n; i++) {
		cout << mas2[i]<<endl;
	}
	int x;
	cout << "Введите x:";
	cin >> x;
	double f = x-abs((mas2[0] + mas2[1]) / 2), t;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double b = abs((mas2[i] + mas2[j]) / 2);
			t = abs(x - b);
			if (x == b)
			{
				cout << "совпадение: среднее арифметическое " << mas2[i] << " и " << mas2[j] << " = " << b << endl << endl;
				fclose(fp);
				return 0;
			}
			else if (t < f)
			{
				cout << "новое среднее ближе всего к х: среднее арифметическое " << mas2[i] << " и " << mas2[j] << " = " << b << endl << endl;
				f = t;
			}
		}
	}
	fclose(fp);
}