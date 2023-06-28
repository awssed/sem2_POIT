// 5 Ввести массивы А и В. В массив С перенести элементы массива А с четным значением и элементы массива В с нечетным значением. 
 //Массив С отсортировать по возрастанию, используя алгоритмы сортировок: «пузырек», сортировка выбором.

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include<chrono>
using namespace std;

void main()
{
    srand(time(NULL));
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
            if (c[i] > c[j]) swap(c[i], c[j]);
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

    cout << "Сортировка методом выбора:\n";
    start = chrono::high_resolution_clock::now();
    for (int start = 0; start < size; ++start)
    {
        int smallest = start;
        for (int current = start + 1; current < size; ++current)
        {
            if (s[current] < s[smallest])
                smallest = current;
        }
        swap(s[start], s[smallest]);
    }
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Расчетное время: " << duration.count() << " секунд" << endl;
    for (int i = 0; i < size; ++i)
    {
        if (c[i] > 0)
        {
            cout << c[i] << ' ';
        }
    }

    _getch();
}