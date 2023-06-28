#include<iostream>
#include<string>
using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	string str;
	string str2;
	cout << "Введиет строку" << endl;
	getline(cin, str);
	if (str.length() % 2 != 0) {
		cout << "Нечетное количество символов";
		return;
	}
	str2 = str;
	int j = 0;
	for (int i = str.length() / 2-1; i >= 0; i--) {
		str2[j] = str[i];
		j++;
	}
	for (int i = str.length() - 1; i > str.length() / 2 - 1; i--) {
		str2[j] = str[i];
		j++;
	}
	cout << str2;
}