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

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N;
	cout << "Введите число участников";
	cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; i++) {
		mas[i] = rand()%101;
	}
	for (int i = 0; i < N; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl;
	quicksort(mas, 0, N-1);
	for (int i = 0; i < N; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl;
	int first_ball = mas[N - 1];
	int second_ball;
	int third_ball;
	for (int i = N-1; i > 0; i--) {
		if (first_ball > mas[i]) {
			second_ball = mas[i];
			break;
		}
	}
	for (int i = N-1; i > 0; i--) {
		if (second_ball > mas[i]) {
			third_ball = mas[i];
			break;
		}
	}
	int first=0;
	int second=0;
	int third=0;
	for (int i = 0; i < N; i++) {
		if (mas[i] == first_ball) {
			first++;
		}
		if (mas[i] == second_ball) {
			second++;
		}
		if (mas[i] == third_ball) {
			third++;
		}
	}
	cout << "Количество дипломов первой степени: " << first << endl;
	cout << "Количесвто дипломов второй степени: " << second<<endl;
	cout << "Колличество дипловом третей стпени: " << third << endl;
	cout << "Число призёров: " << first + second + third << endl;
}