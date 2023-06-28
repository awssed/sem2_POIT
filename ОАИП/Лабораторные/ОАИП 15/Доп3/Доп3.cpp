#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using std::endl; using std::cin; using std::cout;

int hash_f(std::string data)
{
    uint64_t* hashes = new uint64_t[data.size() + 1];
    hashes[0] = 0;
    uint64_t* primes = new uint64_t[data.size() + 1];
    primes[0] = 1;

    const int p = 301;
    const int m = 1e9 + 7;

    for (int i = 0; i < data.size(); ++i)
    {
        hashes[i + 1] = hashes[i] * p + (data[i] - 'a' + 1);
        hashes[i + 1] %= m;
        primes[i + 1] = primes[i] * p;
        primes[i + 1] %= m;
    }

    int i = 3, j = 7;

    long long substr_hash = (hashes[j + 1] - (hashes[i] * primes[j - i + 1]) % m) % m;
    if (substr_hash < 0)
        substr_hash += m;
    return substr_hash;
}

struct Node
{
    std::string data;
    Node* next;

    Node() :next(nullptr) {}

    void add(Node*& node, std::string data)
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
    std::string data;
    Node** Hash_node;
    friend int hash_f(std::string data);

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

    void file_include()
    {
        std::ifstream input("fileA.txt");
        std::string line, word;
        while (std::getline(input, line))
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (line[i] != ' ')
                {
                    word += line[i];
                }
                else
                {
                    add(word);
                    word.clear();
                }
            }
        }
    }

    void add(std::string data)
    {
        int hash = hash_f(data + "12" + std::to_string(data[0] * data.size()));
        hash %= size;
        Hash_node[hash]->add(Hash_node[hash], data);
    }

    void find(std::string word)
    {
        for (int i = 0; i < size; ++i)
        {
            if (Hash_node[i]->next != nullptr)
            {
                Node* p = Hash_node[i];
                while (p->next != nullptr)
                {
                    if (p->data == word)
                    {
                        cout << "Мы смогли найти это число! " << '\n' << "Позиция: " << i << "\tЗначение: " << '\t' << p->data;
                        cout << endl;
                        return;
                    }
                    p = p->next;
                }
            }
        }
        cout << "Мы не смогли найти слово( ";
    }

    void output()
    {
        for (int i = 0; i < size; ++i)
        {
            if (Hash_node[i]->data != "")
            {
                cout << "Позиция: " << i << '\t';
                cout << "Значение: ";
                Hash_node[i]->output(Hash_node[i]);
                cout << '\n';
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n{}; cout << "Введите размер: "; cin >> n;
    Hash_table* table = new Hash_table(n);

    table->file_include();

    table->output();
    cout << "Введите число для поиска: " << endl;
    std::string line;
    cin >> line;
    table->find(line);
    cout << endl;
    table->output();
}