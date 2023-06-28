#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	string str;
	ofstream in("FILE1.txt");
	cout << "Введите первую строку:" << endl;
	getline(cin, str);
	in << str << endl;
	cout << "Введите вторую строку:" << endl;
	getline(cin, str);
	in << str << endl;
	in.close();
	str.clear();
	ifstream out("FILE1.txt");
	int min = 99;
	int mini;
	int count;
	string glas = "eyuioa";
	getline(out, str, '\n');
		str += ' ';
		cout << str<<endl;
		for (int i = 0; i < str.size() + 1; i++) {
			if (str[i] == ' ' || i == 0) {
				count = 0;
				for (int j = i + 1; j < str.size(); j++) {
					if (str[j] != ' ') {
						count++;
					}
					if (j == 1)
						count++;
					if (str[j] == ' ') {
						if (count < min) {
							min = count;
							mini = i;
						}
						break;
					}
				}
			}
		}
		int count_glas = 0;
		cout << " Самое короткое слово:" << endl;
		for (int i = mini; i < mini + min + 1; i++) {
			cout << str[i];
		}
		cout << endl;
		cout << "Количесвто гласных:" << endl;
		for (int j = 0; j < glas.size(); j++) {
			for (int i = mini; i < mini + min + 1; i++) {
				if (glas[j] == str[i]) {
					count_glas++;
				}
			}
		}
		cout << count_glas;
		cout << endl;
		str.clear();
		getline(out, str, '\n');
		cout << "вторая строка"<<endl << str<<endl;
		int max = -99;
		int maxi;
		for (int i = 0; i < str.size() + 1; i++) {
			if (str[i] == ' ' || i == 0) {
				count = 0;
				for (int j = i + 1; j < str.size(); j++) {
					if (str[j] != ' ') {
						count++;
					}
					if (j == 1)
						count++;
					if (str[j] == ' ') {
						if (count > max) {
							max = count;
							maxi = i;
						}
						break;
					}
				}
			}
		}
		cout << endl;
		count_glas = 0;
		cout << " Самое большое слово:" << endl;
		for (int i = maxi; i < maxi + max + 1; i++) {
			cout << str[i];
		}
		for (int j = 0; j < glas.size(); j++) {
			for (int i = maxi; i < maxi + max + 1; i++) {
				if (glas[j] == str[i]) {
					count_glas++;
				}
			}
		}
		cout << "Количесвто гласных:" << endl;
		cout << count_glas;
		str.clear();
}