//Ввести массивы А и В.В массив С перенести четные элементы массива А и нечетные элемента массива В.Массив С отсортировать по убыванию, 
//используя алгоритмы сортировок : «пузырек», сортировка Хоара.

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include<chrono>
using namespace std;
void qs(int* c, int first, int last);
void main()
{
    setlocale(LC_ALL, "rus");
    int a[1000], b[1000], c[1000];
    int q = 0;
    int* p = a; int* r = b; int* s = c;
    int i, j, k, tmp;
    int size;
    cin >> size;
    cout << "Массив A: " << endl;
    for (int i = 0; i < size; i++) {
        *p = rand() % 40;
        cout << *p << "\t";
        p++;
    }
    cout << endl;

    cout << "Массив B: " << endl;
    for (int i = 0; i < size; i++) {
        *r = rand() % 40;
        cout << *r << "\t";
        r++;
    }
    cout << endl;

    p = a;
    r = b;
    for (i = 0; i < size; i++) {
        if (a[i] % 2 == 0)
        {
            *s = a[i];
            cout << *s << "\t";
            s++;
        }
    }
    for (i = 0; i < size; i++) {
        if (b[i] % 2 != 0) {
            *s = b[i];
            cout << *s << "\t";
            s++;
        }
    }
    s = c;
    cout << endl;
    cout << "Сортировка методом пузырька:\n";
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (c[i] < c[j]) swap(c[i], c[j]);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float>duration = end - start;
    cout << "Расчетное время: " << duration.count() << " секунд" << endl;
    for (int i = 0; i < size; i++)
    {
        if (c[i] >= 0) {
            cout << c[i] << " ";
        }
    }
    cout << endl;

    cout << "Сортировка методом Хоара:\n";
    start = chrono::high_resolution_clock::now();
    qs(c, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Расчетное время: " << duration.count() << " секунд" << endl;
    for (int i = 0; i < size; i++)
    {
        if (c[i] >= 0) {
            cout << c[i] << " ";
        }
    }
    _getch();
}
void qs(int* c, int first, int last)
{
    int i = first, j = last, x = c[(first + last) / 2];

    do {
        while (c[i] < x) i++;
        while (c[j] > x) j--;

        if (i <= j) {
            if (c[i] < c[j]) swap(c[i], c[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(c, i, last);
    if (first < j)
        qs(c, first, j);
}