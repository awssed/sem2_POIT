#include<iostream>
using namespace std;

struct Queue {
	int data;
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
void Enqueue1(Queue** end, int value) {
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
}
void Dequeue(Queue** end) {
	Queue* buf =new Queue;
	buf = *end;
	Queue* next = new Queue;
	next = buf->next;
	while(next->next!=NULL) {
			
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
	while (buf->next!=NULL) {
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
void MinMax(Queue*end) {
	Queue* cope = end;
	Queue* Queue1 = NULL;
	Queue* Queue2 = NULL;
	int max = -9999;
	int max_pred = 9999;
	int min = 10000;
	int min_pred=-10000;
	double size = Node_size/2;
	for (int i = 0; i <ceil(size); i++) {
		cope = end;
		while (cope->next != NULL) {
			if (cope->data > max && cope->data<max_pred) {
				max = cope->data;
			}
			if (cope->data < min && cope->data>min_pred) {
				min = cope->data;
			}
			cope = cope->next;
		}
		if (cope->data > max && cope->data < max_pred) {
			max = cope->data;
		}
		if (cope->data < min && cope->data>min_pred) {
			min = cope->data;
		}
		Enqueue1(&Queue1, min);
		Enqueue1(&Queue2, max);
		max_pred = max;
		min_pred = min;
		max = -9999;
		min = 9999;
	}
	cout << "Queue1: " << endl;
	Print(Queue1);
	cout << "Queue2: " << endl;
	Print(Queue2);

}
void menu() {
	cout << "1-Запись" << endl;
	cout << "2-Доступ к начальному элементу" << endl;
	cout << "3-Удаление" << endl;
	cout << "4-Размер" << endl;
	cout << "5-Печать" << endl;
	cout << "6-MaxMin" << endl;

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
			cout<<Peek(end)<<endl;
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
		case 6:
			MinMax(end);
			break;
		default:
			cout << "Что-то не так" << endl;
			break;
		}
	}
	
}
