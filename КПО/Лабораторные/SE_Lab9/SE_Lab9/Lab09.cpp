#include"Varparm.h"
#include<iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	Varparm::ivarparm(3, 5, 2, 2);

	Varparm::svarparm(3, 25, 115, 50);
	Varparm::fvarparm(2, 2.0, 3.0);

	Varparm::dvarparm(25.2, 5.2, 10.0, DBL_MAX); 
}