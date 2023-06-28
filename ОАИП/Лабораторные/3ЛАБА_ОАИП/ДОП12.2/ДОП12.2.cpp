#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	ofstream file1("FILE1.txt");
	string buff;
	cout << "Введите строку:" << endl;
	getline(cin, buff);
	file1 << buff;
	buff.clear();
	file1.close();
	ifstream file2("FILE1.txt");
	int count = 0;
	while (getline(file2, buff, '\n')) {
		string str = buff;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ',')
				count++;
		}
	}
	cout << "Количество запятых:" << count;
	file2.close();
}