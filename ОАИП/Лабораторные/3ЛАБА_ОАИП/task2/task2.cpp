#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void main() {
	string buff;
	getline(cin, buff);
	ofstream out("FILE.txt");
	out << buff;
	out.close();
	buff.clear();
	ifstream from("FILE.txt");
	while (getline(from, buff, ' ')) {
		for (int i = 0; i < buff.size(); i++) {
			if (buff[i] == 'p') {
				cout << buff << endl;
				break;
			}
		}
	}
}