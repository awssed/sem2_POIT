// 12 Ввести массив А. В массив В скопировать элементы массива А, имеющие четный индекс. Массив В отсортировать по возрастанию, используя 
 //алгоритмы сортировок: «пузырек», сортировка выбором.
#include <iostream>
#include <cstdlib>
#include<chrono>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "RU");
	int size = 10;
	int A[1000], B[1000];
	int i = 0;
	cin >> size;
	cout << "Рандомно сгенерированный массив А:" << endl;
	for (i = 0; i < size; i++) {
		A[i] = rand() % 20;
		cout << A[i] << "\t";
	}cout << endl;
	cout << "Массив B, содержащий элементы массива А, имеющие четный индекс:" << endl;
	int how = 0;
	for (i = 0; i < size; i++) {
		if (i % 2 == 0) {
			B[i] = A[i];
			cout << B[i] << "\t";

		}
	}cout << endl;

	cout << "Сортировка методом пузырька:\n";
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (B[i] > B[j]) swap(B[i], B[j]);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float>duration = end - start;
	cout << "Расчетное время: " << duration.count() << " секунд" << endl;
	for (int i = 0; i < size; i++)
	{
		if (B[i] >= 0) {
			cout << B[i] << " ";
		}
	}
	cout << endl;

	cout << "Сортировка методом выбора:\n";
	start = chrono::high_resolution_clock::now();
	for (int start = 0; start < size; ++start)
	{
		int smallest = start;
		for (int current = start + 1; current < size; ++current)
		{
			if (B[current] < B[smallest])
				smallest = current;
		}
		swap(B[start], B[smallest]);
	}
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Расчетное время: " << duration.count() << " секунд" << endl;
	for (int i = 0; i < size; ++i)
	{
		if (B[i] > 0)
		{
			cout << B[i] << ' ';
		}
	}
}