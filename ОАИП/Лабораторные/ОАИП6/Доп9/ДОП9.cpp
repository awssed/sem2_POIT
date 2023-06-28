#include<iostream>
#include<fstream>
using namespace std;

struct list {
	float data;
	list* next;
};
void insert(list*& head, float value);
void output(list* head);
int del(list*& p, float value);
void menu(void);
void find(list*& p, float value);
void toFile(list*& p);
void fromFile();
void sred(list*& p);
void proizFile();
void delFromFile(float value);

void main() {
	setlocale(LC_ALL, "rus");
	list* first = NULL;
	float value;
	int a;
	for (;;) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			int size;
			cout << "Введите колтчество:" << endl;
			cin >> size;
			for (int i = 0; i < size; i++) {
				cin >> value;
				if (value - floor(value) == 0) {
					cout << "Введено целое число" << endl;
					return;
				}
				insert(first, value);
			}
			break;
		case 2:
			output(first);
			break;
		case 3:
			cout << "Введите число которое хотите удалить" << endl;
			cin >> value;
			if (value - floor(value) == 0) {
				cout << "Введено целое число" << endl;
				return;
			}
			del(first, value);
			break;

		case 4:
			sred(first);
			break;
		case 5:
			cout << "Введите число для поиска" << endl;
			cin >> value;
			if (value - floor(value) == 0) {
				cout << "Введено целое число" << endl;
				return;
			}
			find(first, value);
			break;
		case 6:
			toFile(first);
			break;
		case 7:
			fromFile();
			break;
		}
	}
}

void insert(list*& head, float value) {
	list* tmp = new list;
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = head;
		head = tmp;
	}
}
void output(list* p) {

	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
int del(list*& p, float value) {
	list* previous, * current, * temp;
	if (value == p->data) {
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->data != value) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			free(temp);
		}
	}
	return 0;
}
void find(list*& p, float value) {
	while (p != NULL && p->data != value) {
		p = p->next;
	}
	if (p != NULL) {
		cout << p->data << endl;
		cout << p->next << endl;
		return;
	}
	cout << "Элемент не найден" << endl;
	return;
}
void sred(list*& p) {
	float sum = 0;
	int count = 0;
	list* temp = p;
	while (temp != NULL) {
		if (temp->data < 0) {
			sum = sum + temp->data;
			count++;
		}
		temp = temp->next;
	}
	sum = sum / count;
	cout << sum;
}
void proizFile() {
	float proiz = 1;
	int value;
	list buf, * first = nullptr;
	ifstream f("data.dat");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	f.read((char*)&buf, sizeof(list));
	while (!f.eof()) {
		value = buf.data;
		if (buf.data < 10) {
			proiz = proiz * buf.data;
		}
		f.read((char*)&buf, sizeof(list));
	}
	f.close();
	cout << proiz << endl;
}
void toFile(list*& p) {
	list* temp = p;
	list buf;
	ofstream f("data.dat", std::ios::app);
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (temp) {
		buf = *temp;
		f.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	f.close();
	cout << "Cписок записан в файл" << endl;
}
void fromFile() {
	list buf, * first = nullptr;
	ifstream f("data.dat");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	f.read((char*)&buf, sizeof(list));
	while (!f.eof()) {
		cout << buf.data << endl;
		f.read((char*)&buf, sizeof(list));
	}
	f.close();
}
void delFromFile(float value) {
	list* previous, * current, * temp;
	ifstream f("data.dat");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	list* p;
	f.read((char*)&p, sizeof(list));
	if (value == p->data) {
		temp = p;
		p = p->next;
		delete temp;
		return;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->data != value) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			free(temp);
		}
	}
	f.close();
	toFile(p);
	return;
}
void menu(void)
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Вывод чисел" << endl;
	cout << " 3 - Удаление числа" << endl;
	cout << " 4 - Вычисление среднего отрицательных элементов" << endl;
	cout << " 5 - Поиск элемента" << endl;
	cout << " 6 - Запись в файл" << endl;
	cout << " 7 - Вывод из файла" << endl;
}