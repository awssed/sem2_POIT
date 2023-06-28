#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "");
	FILE* fp = fopen("FileA.txt", "r");
	FILE* fp2 = fopen("FileB.txt", "w");
	char c[100];
	int x;
	cout << "Введите количесвто символов:";
	cin >> x;
	while ((fscanf(fp, "%[^\n]", c)) != EOF)
	{
		fgetc(fp);
		if (strlen(c) > x) {
			fprintf(fp2, "%s\n", c);
			printf("Line = %s \n", c);
		}
	}
	fclose(fp);
	fclose(fp2);
}