#include"dictionary.h"
#include <windows.h>
void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		dictionary::Instance d1 = dictionary::Create("Преподаватели", 5);
		dictionary::Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" },
			e3 = { 3,"Смелов" }, e4 = { 4,"Урбанович" }, e5 = { 5,"Пацей" };
		dictionary::AddEntry(d1, e1);
		dictionary::AddEntry(d1, e2);
		dictionary::AddEntry(d1, e3);
		dictionary::AddEntry(d1, e4);
		
	}
	catch (char* e) {
		std::cout << e << std::endl;
	};
}