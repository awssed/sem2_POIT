#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	ifstream from("FILE1.txt");
	ofstream out("FILE2.txt");

	string buff;
	bool set = true;
	int count = 0;

	while (getline(from, buff, '\n')) {
		set = true;
		for (int i = 0; i < buff.size(); i++) {
			if (buff[i] >= '0' && buff[i] <= '9') {
				set = false;
				break;
			}
		}
		if (set == true) {
			out << buff << '\n';
		}
		buff.clear();
	}
	buff.clear();
	from.close();
	out.close();
	ifstream file("FILE2.txt");
	while (getline(file, buff, '\n')) {
		if (buff[0] == 'a'||buff[0]=='A') {
			count++;
		}
		buff.clear();
	}
	file.close();
	cout << "количество строк, которые начинаются на букву «А» :" << count;
}