#pragma comment (lib,"D:\\�����\\2���\\���\\������������\\SE_Lab06S\\Debug\\SE_Lab06L.lib")
#include"D:\�����\2���\���\������������\SE_Lab06S\SE_Lab06L\SE_Lab06L.h"
void main(){
	setlocale(LC_ALL, "rus");
	dictionary::Instance d1 = dictionary::Create("�������������", 5);
	dictionary::Entry e1 = { 1,"�������" }, e2 = { 2,"�������" },
		e3 = { 3,"������" }, e4 = { 4,"���������" }, e5 = { 5,"�����" };
	dictionary::AddEntry(d1, e1);
	dictionary::AddEntry(d1, e2);
	dictionary::AddEntry(d1, e3);
	dictionary::AddEntry(d1, e4);
	dictionary::Entry ex2 = dictionary::GetEntry(d1, 4);
	dictionary::Print(d1);
	dictionary::DelEntry(d1, 2);
	dictionary::Print(d1);
	dictionary::Entry newEntry1 = { 6,"�����" };
	dictionary::UpdEntry(d1, 3, newEntry1);
	dictionary::Print(d1);
	dictionary::Instance d2 = { "C�������", 5 };
	dictionary::Entry s1 = { 1,"������" }, s2 = { 2,"������" }, s3 = { 3,"�������" };
	dictionary::AddEntry(d2, s1);
	dictionary::AddEntry(d2, s2);
	dictionary::AddEntry(d2, s3);
	dictionary::Entry newEntry2 = { 4,"��������" };
	dictionary::UpdEntry(d2, 3, newEntry2);
	dictionary::DelEntry(d2, 2);
	dictionary::Print(d2);
	Delete(d1);
	Delete(d2);
}