#include<iostream>
#include<string>
using namespace std;

typedef unsigned int kod;
typedef unsigned  int provider;
typedef unsigned int nomer;
typedef string owner;
typedef string plan;
typedef bool limitoff;
typedef int minutes;

struct client {
	kod k;
	provider p;
	nomer n;
	owner o;
	plan pl;
	limitoff l;
	minutes m;
};

bool operator < (client a, client b) {
	bool result = false;
	if (a.l == b.l && a.m < b.m) {
		return true;
	}
	else {
		return false;
	}
}
std::ostream& operator << (std::ostream& os, client a)
{
	if (a.l == true) {
		return os << '+' << a.k << " " << a.p << " " << a.n << endl << "Владелец: " << a.o << endl << "Безлимит" << endl << "Минуты " << a.m;;
	}
	else {
		return os << '+' << a.k << " " << a.p << " " << a.n << endl << "Владелец: " << a.o << endl << "Безлимит отсутсвует" << endl << "Минуты :" << a.m;;

	}
	
}

bool operator==(client a, client b) {
	if ( a.l==b.l&& a.m==b.m){
		return true;
	}
	else
		return false;
}

void main() {
	setlocale(LC_ALL, "rus");
	client client1={ 375,44,1332503,"Ivanov","plan1",true,300 };
	client client2={ 375,44,1312203,"Petrov","plan3",true,500 };
	client client3={ 375,29,1150312,"Sidorov","plan2",true,300 };
	if (client1<client2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
	if (client1 == client3) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
	if (client1 == client2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}
	cout << client1;
}