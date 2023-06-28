#include <iostream>

using namespace std;


struct Node {
    string data;
    Node* next;
};


void addToCircularList(Node*& head, string data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}


void printCircularList(Node* head) {
    if (head == NULL) {
        cout << "������ ����" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}


void traverseCircularList(Node* head, int steps) {
    if (head == NULL) {
        cout << "������ ����" << endl;
        return;
    }
    if (steps == 0) {
        cout << head->data;
        return;
    }
    traverseCircularList(head->next, steps - 1);
}


void clearCircularList(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current->next != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
    head = NULL;
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* head = NULL;
    int n;
    string data;
    cout << "������� ���-�� ��������� � ������������������: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "������� ������� " << i + 1 << ": ";
        cin >> data;
        addToCircularList(head, data);
    }
    cout << "�������� ������: ";
    printCircularList(head);
    int steps;
    cout << "������� n: ";
    cin >> steps;
    cout << "�������� ����� " << 26 + steps << " ����� ";
    traverseCircularList(head, 25 + steps);
    clearCircularList(head);
    return 0;
}