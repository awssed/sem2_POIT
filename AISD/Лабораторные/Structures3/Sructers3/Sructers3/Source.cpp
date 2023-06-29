#include<iostream>
#include <iomanip>
#include<time.h>
using namespace std;
void quicksort(int* mas, int first, int last);
void main() {
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите число N:" << endl;
	cin >> N;
	int* a;
	a = new int[N];
	int* b=new int[N];
	int* c=new int[N];
	int* d= new int[N];
	int* e= new int[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		a[i] = rand()%30;
	}
	for (int i = 0; i < N; i++) {
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
		e[i] = a[i];
	}
	for (int i = 0; i < N; i++) {
		cout << b[i] << "  ";
	}
	//Пузырьковая сортировка
	cout << "Пузырьковая" << endl;
	
	cout << endl;
	clock_t time;
	time = clock();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (b[j] > b[j + 1]) {
				b[j] = b[j] + b[j + 1];
				b[j + 1] = b[j] - b[j + 1];
				b[j] = b[j] - b[j + 1];
			}
		}
	}
	time = clock() - time;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << std::endl;
	for (int i = 0; i < N; i++) {
		cout << b[i] << "  ";
	}
	cout << endl;
	cout << "Метод шелла" << endl;
	int i, j, step;
	int tmp;
	time = clock();
		for (step = N / 2; step > 0; step /= 2) {
			if (step == 1) {
				for (j = 0; j < N;j++) {
					tmp = c[j];
					while (c[j] < c[j - 1]) {
							c[j] = c[j -1];
							c[j -1] = tmp;
							j--;
					}
				}
			}
			for (i = step; i < N; i++) {
				tmp = c[i];
				if (c[i] < c[i - step]) {
					c[i] = c[i - step];
					c[i - step] = tmp;
				}
			}
			cout << endl;
		}
	
		time = clock() - time;
		std::cout << std::fixed << std::setprecision(6);
		std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << std::endl;
	for (int i = 0; i < N; i++) {
		cout << c[i] << "  ";
	}
	cout << endl;
	cout << "Сортировка выбором" << endl;
	int max=-99;
	int maxJ;
	int n = N;
	time = clock();
	for (int i = 0; i < N; i++) {
		max = -99;
	for (int j = 0; j < n; j++) {
			if (d[j] > max) {
				maxJ = j;
				max = d[j];
			}
		}
		tmp = d[n-1];
		d[n-1] = d[maxJ];
		d[maxJ] = tmp;
		n--;
	}
	time = clock() - time;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << std::endl;
	for (int i = 0; i < N; i++) {
		cout << d[i] << "  ";
	}
	cout <<endl<< "Быстрая сортировка" << endl;
	time = clock();
	quicksort(e, 0, N - 1);
	time = clock() - time;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << std::endl;
	for (int i = 0; i < N; i++) {
		cout << e[i] << "  ";
	}
}

void quicksort(int* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}