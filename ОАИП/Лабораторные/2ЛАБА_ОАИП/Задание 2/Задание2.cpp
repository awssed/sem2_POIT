#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "");
	FILE* fp=fopen("FileA.txt","r");
	FILE* fp2 = fopen("FileB.txt", "w");
	char c[100];
	while ((fscanf(fp, "%[^\n]", c)) != EOF)
	{
		bool set;
		fgetc(fp);
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] < '0' || c[i]>'9') {
				set = true;
			}
			else {
				set = false;
				break;
			}
		}
		if (set == true) {
			fprintf(fp2, "%s\n", c);
		}
		printf("Line = %s \n", c);
	}
	fclose(fp);
	fclose(fp2);
}