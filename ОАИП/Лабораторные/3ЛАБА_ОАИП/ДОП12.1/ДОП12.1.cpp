#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	string line;
	string word;
	string first_word;

	ofstream out("FILE2.txt");
	ifstream from("FILE1.txt");
	if (!from || !out)
	{
		cout << "Файл не открыт\n";
	}
	else
	{
		cout << "Вск ОК! Файл открыт\n";
	}
	from >> first_word;
	cout << first_word;
	cout << endl;
	out << first_word << ' ';
	while (getline(from, line, '\n')) {
		bool set = false;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] != ' ') {
				word += line[i];
			}
			else if (line[i] == ' ')
			{
				if (word == first_word) {
					set = true;
					word.clear();
					break;
				}
				word.clear();
			}
		}
		if (set == true) {
			out << line << endl;
		}
	}
	from.close();
	out.close();
	ifstream f("FILE2.txt");
	string buff;
	string last_line;
	while (getline(f, buff, '\n')) {
		last_line = buff;
	}
	cout << last_line<<endl;
	string sog = "bcdfghjklmnpqrstvwxz";
	int count = 0;
	for (int j = 0; j < sog.size(); j++) {
		for (int i = 0; i < last_line.size(); i++) {
			if (last_line[i] == sog[j])
				count++;
		}
	}
	cout << "Количество согласных букв в строке :" << count;
}
