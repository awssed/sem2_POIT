#include<iostream>
using namespace std;
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
void main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int amount;
	int sum=0;
	cout << "Введите количество товаров";
	cin >> amount;
	int* tovars = new int[amount];
	for (int i = 0; i < amount; i++) {
		tovars[i]=rand()%100+1;
	}
	for (int i = 0; i < amount; i++) {
		cout << tovars[i] << ' ';
	}
	cout << endl;
	quicksort(tovars, 0, amount - 1);
	
	cout << endl;
	int q = 0;
	for (int z = 0; z < amount / 2 ; z++) {
		for (int i = amount-1; i  >q; i--) {
			swap(tovars[i], tovars[i - 1]);
		}
		q = q + 2;
	}
	for (int i = 0; i < amount; i++) {
		cout<< tovars[i]<<' ';
	}
	for (int i = 0; i < amount; i = i + 2) {
		sum = sum + tovars[i];
	}
	cout << endl;
	cout << "Чек : " << sum;
}