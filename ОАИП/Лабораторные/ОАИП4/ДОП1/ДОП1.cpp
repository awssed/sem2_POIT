#include<iostream>
#include<string>
using namespace std;

struct student {
	string fio;
	int num_ex;
	int* marks;
};
bool zachet(student a);
double prosent(student* a, int n);

void main() {
	setlocale(LC_ALL, "rus");
	student a[10];
	cout << "Введите количесвто студентов" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "fio" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, a[i].fio);
		cout << "Количество экзаменов" << endl;
		cin >> a[i].num_ex;
		cout << "Оценки" << endl;
		a[i].marks = new int[a[i].num_ex];
		for (int j = 0; j < a[i].num_ex; j++) {
			cin >> a[i].marks[j];
		}
	}
	int q;
	cout << "Введите номер студента которого нужно проверить:" << endl;
	cin >> q;
	if (zachet(a[q]) == true) {
		cout << "Данный студент успешно закрыл сессию на 4 и 5"<<endl;
	}
	cout << "Процентное отношение отличников к общему количеству студентов:" << endl;
	cout << prosent(a, n);
	cout << " процентов";
}
bool zachet(student a) {
		int count = a.num_ex;
		for (int j = 0; j < count; j++) {
			if (a.marks[j] < 4)
				return false;
		}
		return true;
}
double prosent(student* a, int n) {
	double good = 0;
	int all = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		int count = a[i].num_ex;
		for (int j = 0; j < count; j++) {
			if (a[i].marks[j] < 4) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			good++;
		}
	}
	double pros = (good / n)*100;
	return pros;
}