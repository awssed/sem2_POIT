#include"dictionary.h"
#include <windows.h>
void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		dictionary::Instance d1 = dictionary::Create("�������������", 5);
		dictionary::Entry e1 = { 1,"�������" }, e2 = { 2,"�������" },
			e3 = { 3,"������" }, e4 = { 4,"���������" }, e5 = { 5,"�����" };
		dictionary::AddEntry(d1, e1);
		dictionary::AddEntry(d1, e2);
		dictionary::AddEntry(d1, e3);
		dictionary::AddEntry(d1, e4);
		
	}
	catch (char* e) {
		std::cout << e << std::endl;
	};
}