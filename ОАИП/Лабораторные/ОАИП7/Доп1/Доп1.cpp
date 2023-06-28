#include<iostream>
#include<string>
using namespace std;

void main() {
	string str;
	cout << "Введиет строку" << endl;
	getline(cin, str);
	if (str.length() % 2 != 0) {
		cout << "Нечетное количество символов";
		return;
	}
	int size = str.length() / 2;
	cout << size;
	char* buf1=(char*)malloc(size*sizeof(char));
	char* buf2 = new char[str.length()];
	for (int i = 0; i < str.length()/2; i++) {
		buf1[i] = str[i];
	}
	int j = 0;
	for (int i = str.length()/2; i < str.length(); i++) {
		buf2[j] = str[i];
		j++;
	}
	cout << buf1 << endl;
	cout << buf2;
}