#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "");
	FILE* fp = fopen("f.txt", "r");
	FILE* fp2 = fopen("g.txt", "w");
	char c[100];
	cout << "¬ведите значение:";
	int x;
	cin >> x;
	while ((fscanf(fp, "%[^\n]", c)) != EOF)
	{
		fgetc(fp);
		if ((int(c[0] - '0')*10+int(c[1]-'0'))>x) {
			fprintf(fp2, "%s\n", c);
		}
		printf("Line = %s \n", c);
	}
	fclose(fp);
	fclose(fp2);
}