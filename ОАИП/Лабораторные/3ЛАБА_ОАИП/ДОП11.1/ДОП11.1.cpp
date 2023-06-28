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
	while (getline(from, buff, '\n')) {
		set = true;
		 for (int i = 0; i < buff.size(); i++) {
			 if (buff[i] == ' ') {
				 set = false;
				 break;
			 }
		}
		if (set == true) {
			out << buff<<'\n';
		}
		buff.clear();
	}
	buff.clear();
	from.close();
	out.close();
	ifstream file("FILE2.txt");
	string words;
	while (getline(file, buff, '\n')) {
		words += buff;
		words += ' ';
	}
	int min = 99;
	int mini;
	int count;
	cout << words;
	for (int i = 0; i < words.size()+1; i++) {
		if (words[i] == ' ' || i == 0) {
			count = 0;
			for (int j=i+1; j < words.size();j++) {
				if (words[j] != ' ') {
					count++;
				}
				if (j == 1)
					count++;
				if (words[j] == ' ') {
					if (count < min) {
						min = count;
						mini = i;
					}
					break;
				}
			}
		}
	}
	cout << endl;
	cout << min;
	cout << " Самое короткое слово:" << endl;
	for (int i = mini; i <mini+min+1; i++) {
		cout << words[i];
	}
}