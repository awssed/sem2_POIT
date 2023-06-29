#pragma comment (lib,"D:\\Учёба\\2сем\\КПО\\Лабораторные\\SE_Lab06S\\Debug\\SE_Lab06L.lib")
#include"D:\Учёба\2сем\КПО\Лабораторные\SE_Lab06S\SE_Lab06L\SE_Lab06L.h"
void main(){
	setlocale(LC_ALL, "rus");
	dictionary::Instance d1 = dictionary::Create("Преподаватели", 5);
	dictionary::Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" },
		e3 = { 3,"Смелов" }, e4 = { 4,"Урбанович" }, e5 = { 5,"Пацей" };
	dictionary::AddEntry(d1, e1);
	dictionary::AddEntry(d1, e2);
	dictionary::AddEntry(d1, e3);
	dictionary::AddEntry(d1, e4);
	dictionary::Entry ex2 = dictionary::GetEntry(d1, 4);
	dictionary::Print(d1);
	dictionary::DelEntry(d1, 2);
	dictionary::Print(d1);
	dictionary::Entry newEntry1 = { 6,"Гурин" };
	dictionary::UpdEntry(d1, 3, newEntry1);
	dictionary::Print(d1);
	dictionary::Instance d2 = { "Cтуденты", 5 };
	dictionary::Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
	dictionary::AddEntry(d2, s1);
	dictionary::AddEntry(d2, s2);
	dictionary::AddEntry(d2, s3);
	dictionary::Entry newEntry2 = { 4,"Николаев" };
	dictionary::UpdEntry(d2, 3, newEntry2);
	dictionary::DelEntry(d2, 2);
	dictionary::Print(d2);
	Delete(d1);
	Delete(d2);
}