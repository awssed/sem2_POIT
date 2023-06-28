#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

int NodesCount;

void Push(struct Node** top, int x) {
	Node* buf = new (Node);
	buf->data = x;
	buf->next = *top;
	*top = buf;
	NodesCount++;
}
int Peek(Node* top) {
	if (top == NULL) {
		return NULL;
	}
	else {
		return top->data;
	}
}
void Pop(Node** top) {
	Node* buf = new(Node);
	buf = *top;
	*top = buf->next;
	delete buf;
}
void show(Node* top) {
	Node* buf = top;
	while (buf) {
		cout << buf->data << endl;
		buf = buf->next;
	}

}
void clear(Node** top) {
	Node* buf = *top;
	while (buf->next != NULL) {
		*top = buf->next;
		buf = *top;
	}
	*top = NULL;
}
void toFile(Node** top) {
	Node* buf = *top;
	ofstream f("File.bin");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (buf) {
		f.write((char*)buf, sizeof(Node));
		buf = buf->next;
	}
	f.close();
	cout << "Данные записаны в файл" << endl;
}
void fromFile() {
	Node buf;
	ifstream f("File.bin");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	f.read((char*)&buf, sizeof(Node));
	while (!f.eof()) {
		cout << buf.data << endl;
		f.read((char*)&buf, sizeof(Node));
	}
	f.close();
}
void delete_plus(Node** top) {
	Node* buf = *top;
	Node* next = buf->next;
	while (buf->next!=NULL) {
		if (next->data > 0) {
			buf->next = next->next;
			return;
		}
		buf = buf->next;
		next = next->next;
	}
	cout << "Нету положительных элементов" << endl;
}
void menu() {
	cout << "1-Push" << endl;
	cout << "2-Pop" << endl;
	cout << "3-Peek" << endl;
	cout << "4-Clear" << endl;
	cout << "5-toFile" << endl;
	cout << "6-fromFile" << endl;
	cout << "7-Удаление первого положительного элемента" << endl;
	cout << "8-Вывод всего стека" << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	Node* top = NULL;
	int a;
	int value;
	int x, y;
	for (;;) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			cout << "Введите значение" << endl;
			cin >> value;
			Push(&top, value);
			break;
		case 2:
			Pop(&top);
			break;
		case 3:
			if (Peek(top) == NULL) {
				cout << "Пусто" << endl;
			}
			cout << Peek(top);
			break;
		case 4:
			clear(&top);
			break;
		case 5:
			toFile(&top);
			break;
		case 6:
			fromFile();
			break;
		case 7:
			if (top->data > 0) {
				top = top->next;
				break;
			}
			delete_plus(&top);
			break;
		case 8:
			show(top);
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
}