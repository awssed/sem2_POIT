#include <string>
#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;
#define INT_MAX 32767 
#define NUM 13

struct arr
{
    string str = "\0";
    int num = 0;
    arr* next = NULL;
};

int hash_f(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++) sum += str[i];
    return sum % NUM;
}
void output(arr* tab, int size)
{
    for (int i = 0; i < size; i++)// пока не выведем весь массив
    {
        arr* ptr = &tab[i];
        cout << endl;
        cout << "индекс #" << i << ":\n";
        do
        {
            if (ptr->str[0] == '\0')
            {
                cout << "Пусто\n";
                break;
            }
            else
            {
                cout << "строка: " << ptr->str << " номер: " << ptr->num ;
                cout << "->";
            }
        } while (ptr = ptr->next);
    }
    cout << endl;
}
void dlt(arr* tab, int size, int num)
{
    int k = hash_f(to_string(num));
    while (k > size - 1) k -= size;
    arr* ptr = &tab[k];
    if (ptr->num == num)//если элемент найден
    {
        if (ptr->next)
        {
            ptr->next = ptr->next->next;//меняяем указатель на следующий элемент от удалённого
            ptr->num = ptr->num;// записываем ключ
            ptr->str = ptr->str;
        }
        else
        {
            ptr->num = 0;
            ptr->str = '\0';
        }
        return;
    }
    if (ptr->num!=NULL)//если список не пуст
    {
        arr* ptr_prev = new arr;
        while ((ptr->num != num))
        {
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->num == num)
        {
            ptr_prev->next = ptr->next;
            delete ptr;
            return;
        }
        //exit(1);
    }
    cout << "Элемента нет\n";
    return;
}
void input(arr* tab, int size, string str, int num)
{
    int k = hash_f(to_string(num));//ищем ключ для элемента в хеш-функции
    while (k > size - 1) k -= size;// уменьшаем ключ,чтобы влез в размерность
    arr* ptr = &tab[k];
    if (!ptr->num)//если элемент пуст
    {
        ptr->next = NULL;//следующий элемент NULL
        ptr->str = str;//записываем ФИО
        ptr->num = num;// записываем ключ
    }
    else
    {
        while (ptr->next) ptr = ptr->next;//устанавливаем элемент в конце односвязного списка
        arr* p = new arr;
        p->next = NULL;//для следующего элемента p установили Null
        p->str = str;//ФИО
        p->num = num;//ключ
        ptr->next = p;// для ptr установили следующим элементом p
    }
}
void search(arr* tab, int size, int num)
{
    int k = hash_f(to_string(num));
    while (k > size - 1) k -= size;//Уменьшение ключа ддо размера массива
    arr* ptr = &tab[k];
    if (ptr->num)
    {
        while (ptr->next && ptr->num != num)
        {
            ptr = ptr->next;
        }
        if (ptr->num == num)
        {
            cout << "ключ: " << ptr->num << " ФИО: " << ptr->str << endl;
            return;
        }
        cout << "ошибка\n";
        exit(1);
    }
    cout << "Элемента нет\n";
    return;
}
void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 7;
    cout << "Введите размер хеш-таблицы" << endl;
    cin >> size;
    int clearMas[256] = { 0 };
    arr* mas = new arr[size];
    int choise;
    do
    {
        system("cls");
        cout << "1 - Вывод хеш-таблицы\n2 - Добавление элемента\n3 - Поиск элнмента\n4 - Удаление\n0 - Выход\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
        {
            output(mas, size);
            break;
        }
        case 2:
        {
            string str;
            int num;
            cout << "Введите ФИО: ";
            cin.ignore();
            getline(cin, str);
            cout << "Введите номер телефона: ";
            cin >> num;
            if (0 < num < INT_MAX)
            {
                input(mas, size, str, num);
            }
            else cout << "Некорректный номер\n";
            break;
        }
        case 3:
        {
            cout << "Введите ключ: ";
            int num;
            cin >> num;
            cin.ignore();
            auto start = chrono::high_resolution_clock::now();
            search(mas, size, num);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float>duration = end - start;
            cout << "Расчетное время: " << duration.count() << " секунд" << endl;
            break;
        }
        case 4:
        {
            cout << "Введите ключ: ";
            int num;
            cin >> num;
            dlt(mas, size, num);
        }
        default:
            break;
        }
        system("pause");
    } while (choise);
}