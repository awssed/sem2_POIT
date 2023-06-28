#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	string buff;
	ofstream file("FILE.txt");
	cout << "Введите строку символов:" << endl;
	getline(cin, buff);
	file << buff << '\n';
	file.close();
	buff.clear();

	ifstream file1("FILE.txt");
	int count = 0;
	while (getline(file1, buff, '\n')) {
		int max = -99;
		int maxi;
		for (int i = 0; i < buff.size() + 1; i++) {
			if (buff[i] == ' ' || i == 0) {
				count = 0;
				for (int j = i + 1; j < buff.size(); j++) {
					if (buff[j] != ' ') {
						count++;
					}
					if (j == 1)
						count++;
					if (buff[j] == ' ') {
						if (count > max) {
							max = count;
							maxi = i;
						}
						break;
					}
				}
			}
		}
		cout << " Самое большое слово:" << endl;
		for (int i = maxi; i < maxi + max + 1; i++) {
			cout << buff[i];
		}
		cout << endl;
		cout << "Количество букв:" << max;

	}
}