#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


int HashFunction(int key, int size, int p)
{
    double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
    return (p + key) % size;
}

struct Hash_table
{
public:
    int size = 10;
    int count{};
    int* data = new int[size];

    Hash_table(int size) :size(size)
    {
        data = new int[size];
        fill(data, data + size, 0);
    }
    Hash_table() {}

    int Next_hash(int hash, int size, int p)
    {
        int index = (hash + 5 * p + 3 * p * p) % size;
        if (data[index] != NULL) { cout << "коллизия" << endl; Next_hash(index, size, rand() % size + 1); }
        else return (hash + 5 * p + 3 * p * p) % size;
    }

    void Add(int& value)
    {
        int index = HashFunction(value, size, 2);
        cout << "Зашифрованная строка:" << '\t' << index << endl;
        if (count == size) { cout << "Таблица полная((( " << endl; return; }
        if (data[index % size] != NULL)
        {
            cout << "Коллизия" << endl;
            index = Next_hash(value, size, 2);
        }
        else index = index % size;
        data[index] = value;
        ++count;
    }


    void Output()
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] > -1000)
            {
                cout << "\nКлюч:\t" << i << '\t';
                cout << "значение:\t" << data[i] << endl;
            }
        }
    }

    void Search(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != NULL)
            {
                if (i == key)
                {
                    cout << "Ключ:\t" << i << '\t';
                    cout << "значение:\t" << data[i] << endl;
                    return;
                }
            }

        }
        cout << "Элемент не найден" << endl;

    }

    void Remove(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != NULL)
            {
                if (i == key)
                {
                    data[i] = NULL;
                    --count;
                    cout << "Элемент удален" << endl;
                    return;
                }
            }
        }
        cout << "Элемент не найден" << endl;
    }
};

void main()
{
    system("chcp 1251");
    clock_t start, end;
    double searching_time;
    int choice = 0;
    int amount = 0;
    int value;
    int key = 0;
    Hash_table* hash1 = new Hash_table();
    for (;;)
    {
        cout << "1 - создание хэш-таблицы\n";
        cout << "2 - добавление элемента\n";
        cout << "3 - вывод\n";
        cout << "4 - Поиск\n";
        cout << "5 - Удаление элемента\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "Введите размер хэш-таблицы: " << endl;
            cin >> amount;
            hash1 = new Hash_table(amount);
            break;
        case 2:
            cout << "\nВведите строку: ";
            cin.ignore();
            cin >> value;
            hash1->Add(value);
            break;
        case 3:
            cout << "\nВывод:\n ";
            hash1->Output();
            break;
        case 4:
            cout << "\nВведите ключ: ";
            cin >> key;
            start = clock();
            hash1->Search(key);
            end = clock();
            searching_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "время поиска: " << searching_time << endl;
            break;

        case 5:
            cout << "\nВведите ключ: ";
            cin >> key;
            hash1->Remove(key);
            break;
        case 8:  exit(0);
        }
    }
}