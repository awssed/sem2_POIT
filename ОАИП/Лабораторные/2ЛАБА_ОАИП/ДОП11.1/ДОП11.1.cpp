#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "");
	FILE* fp = fopen("fileA.txt", "r");
	FILE* fp2 = fopen("fileB.txt", "w");
	char c[100];
	int* mas = new int[1000];
	int* mas2 = new int[100];
	char mas3[50];
	int i = 0;
	while ((fscanf(fp, "%[^\n]", c)) != EOF)
	{
		fgetc(fp);
		int n = stoi(c);
		mas[i] = n;
		i++;
	}
	for (int i = 0; i < sizeof(mas) - 1; i++) {
		for (int j = i+1; j < sizeof(mas)+1; j++) {
			if (mas[i] == mas[j]) {
				mas[i] = 0;
				mas[j] = 0;
			}
		}
	}
	cout << endl;
	int j = 0;
	for (int i = 0; i < sizeof(mas); i++) {
		if (mas[i] != 0) {
			mas2[j] = mas[i];
			j++;
		}
	}
	for (int i = 0; i < j; i++) {
		_itoa(mas2[i], mas3, 10);
		fputs(mas3, fp2);
		fputs("\n", fp2);
	}
	fclose(fp);
	fclose(fp2);
}
