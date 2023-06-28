#include<iostream>
using namespace std;
struct Queue {
	double data;
	Queue* next;
};
int Node_size = 0;

void Enqueue(Queue** end, int value) {
	Queue* buf = new Queue;
	buf->data = value;
	if (Node_size == 0) {
		buf->next = NULL;
		*end = buf;
		Node_size++;
		return;
	}
	buf->next = *end;
	*end = buf;
	Node_size++;
}
void Dequeue(Queue** end) {
	Queue* buf = new Queue;
	buf = *end;
	Queue* next = new Queue;
	next = buf->next;
	while (next->next != NULL) {

		buf = buf->next;
		next = next->next;
	}
	buf->next = NULL;
	delete[] next;
	return;
	Node_size--;
	cout << "Пусто";
}
int Peek(Queue* end) {
	Queue* buf = end;
	while (buf->next != NULL) {
		buf = buf->next;
	}
	return buf->data;
}
int Size() {
	return Node_size;
}
void Print(Queue* end) {
	Queue* buf = end;
	while (buf) {
		cout << buf->data << endl;
		buf = buf->next;
	}
}
void Sdvig(Queue** end) {
	Queue* buf = new Queue;
	buf = *end;
	Queue* max = new Queue;
	max->data = -99;
	int count=0;
	int maxI;
	while (buf->next != NULL) {
		count++;
		if (buf->data > max->data) {
			max->data = buf->data;
			maxI = count;
		}
		buf = buf->next;
	}
	count++;
	if (buf->data > max->data) {
		max->data = buf->data;
		maxI = count;
	}
	buf = buf->next;
	if (maxI == count) {
		cout << "Максимальный элемент уже в начале" << endl;
		return;
	}
	buf = *end;
	Queue* next = new Queue;
	next = buf->next;
	for (int i = 0; i < maxI-2; i++) {
		buf = buf->next;
		next = next->next;
	}
	if (next->data ==max->data) {
		buf->next = next->next;
		delete[] next;
	}
	buf = *end;
	while (buf->next != NULL) {
		buf = buf->next;
	}
	buf->next = max;
	max->next = NULL;
}
void menu() {
	cout << "1-Запись" << endl;
	cout << "2-Доступ к начальному элементу" << endl;
	cout << "3-Удаление" << endl;
	cout << "4-Размер" << endl;
	cout << "5-Печать" << endl;
	cout << "6-Сдвиг" << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	int a;
	int value;
	Queue* end = NULL;
	for (;;) {
		menu();
		cin >> a;
		switch (a)
		{
		case 1:
			cin >> value;
			Enqueue(&end, value);
			break;
		case 2:
			cout << Peek(end) << endl;
			break;
		case 3:
			Dequeue(&end);
			break;
		case 4:
			cout << Size() << endl;
			break;
		case 5:
			Print(end);
			break;
		case 6:Sdvig(&end);
			break;
		default:
			cout << "Что-то не так" << endl;
			break;
		}
	}

}