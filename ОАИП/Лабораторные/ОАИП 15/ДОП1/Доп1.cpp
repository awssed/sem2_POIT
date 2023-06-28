#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <set>

using std::endl; using std::cin; using std::cout;

int hash_f(std::string data, char letter)
{
    return std::count(data.begin(), data.end(), letter);
}

struct Node
{
    char data;
    Node* next;

    void add(Node*& node, char data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = node;
        node = newNode;
    }

    void output(Node* node)
    {
        while (node->next != nullptr)
        {
            cout << node->data << '\t';
            node = node->next;
        }
    }
};

class Hash_table
{
private:
    int size = 5;
    int index;
    std::string line;
    Node** Hash_node;
    friend int hash_f(std::string data, char letter);

    void realization()
    {
        Hash_node = new Node * [size];
        for (int i = 0; i < size; ++i)
        {
            Hash_node[i] = new Node();
        }
    }

public:
    Hash_table() { realization(); };
    Hash_table(int size) : size(size) { realization(); }

    void add(std::string data)
    {
        line = data;
        std::set<char> key;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] >= 'a' && data[i] <= 'z')
                if (data[i] != ' ') {
                    key.insert(data[i]);
                }
            else
                i++;
        }
        for (std::set<char>::iterator it = key.begin(); it != key.end(); ++it)
        {
            int hash = hash_f(data, *it);
            hash %= size;
            Hash_node[hash]->add(Hash_node[hash], *it);
        }
    }

    void output()
    {
        for (int i = 0; i < size; ++i)
        {
            if (Hash_node[i]->next != nullptr)
            {
                cout << "Количество: " << i << '\t' << "Значения: " << '\t';
                Hash_node[i]->output(Hash_node[i]);
                cout << '\n';
            }
        }
    }

    void find(char letter)
    {
        int count = std::count(line.begin(), line.end(), letter);
        while (Hash_node[count]->next != nullptr)
        {
            if (Hash_node[count]->data == letter)
            {
                cout << "Такая буква и вправду есть! " << "\nКлюч: " << count << "\tБуква: " << letter;
                return;
            }
            Hash_node[count] = Hash_node[count]->next;
        }
        cout << "Мы не нашли( ";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n{}; cout << "Введите размер: "; cin >> n;
    Hash_table* table = new Hash_table(n);

    std::string line; cout << "Введите строку: "; cin.ignore();
    std::getline(cin, line);

    table->add(line);
    cout << "Вывод" << endl;
    table->output();
    cout << endl;
    cout << "Введите букву для поиска: " << endl;
    char letter; cin >> letter;
    table->find(letter);
}