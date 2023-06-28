#include"fun.h"


int Peek(Node* top) {
	if (top == NULL) {
		return NULL;
	}
	else {
		return top->data;
	}
}

int show(Node* top) {
	Node* buf = top;
	while (buf) {
		cout << buf->data << endl;
		buf = buf->next;
	}
	return 0;
}
int clear(Node** top) {
	Node* buf = *top;
	while (buf->next != NULL) {
		*top = buf->next;
		buf = *top;
	}
	*top = NULL;
	return 0;
}
int toFile(Node** top) {
	Node* buf = *top;
	ofstream f("File.bin");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}
	while (buf) {
		f.write((char*)buf, sizeof(Node));
		buf = buf->next;
	}
	f.close();
	cout << "Данные записаны в файл" << endl;
	return 0;
}
int fromFile() {
	Node buf;
	ifstream f("File.bin");
	if (f.fail()) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}
	f.read((char*)&buf, sizeof(Node));
	while (!f.eof()) {
		cout << buf.data << endl;
		f.read((char*)&buf, sizeof(Node));
	}
	f.close();
	return 0;
}

int menu() {
	cout << "1-Push" << endl;
	cout << "2-Pop" << endl;
	cout << "3-Peek" << endl;
	cout << "4-Clear" << endl;
	cout << "5-toFile" << endl;
	cout << "6-fromFile" << endl;
	cout << "7-Проверка в диапозоне" << endl;
	cout << "8-Вывод всего стека" << endl;
	return 0;
}