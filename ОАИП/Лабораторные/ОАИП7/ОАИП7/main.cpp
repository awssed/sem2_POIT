#include<iostream>
#include<fstream>
#include"fun.h"
using namespace std;

int NodesCount;


void Push(struct Node** top, int x) {
	Node* buf = new (Node);
	buf->data = x;
	buf->next = *top;
	*top = buf;
	NodesCount++;
}
void Pop(Node** top) {
	Node* buf = new(Node);
	buf = *top;
	*top = buf->next;
	delete buf;
	NodesCount--;
}
void diaposon(Node* top, int x, int y, int value) {
	Node* buf = top;
	for (int i = 1; i <= NodesCount - y; i++) {
		buf = buf->next;
	}
	if (buf->data == value) {
		cout << "ДА" << endl;
		return;
	}
	int count = y;
	while (buf) {
		if (count == x) {
			cout << "Нет" << endl;
			return;
		}
		if (buf->data == value) {
			cout << "ДА" << endl;
			return;
		}
		buf = buf->next;
		count--;
	}
	cout << "Нет" << endl;
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
			Push(&top,value);
			break;
		case 2:
			Pop(&top);
			break;
		case 3:
			if (Peek(top) == NULL) {
				cout << "Пусто" << endl;
			}
			cout<<Peek(top);
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
			cin >> x;
			cin >> y;
			cin >> value;
			diaposon(top,x,y,value);
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