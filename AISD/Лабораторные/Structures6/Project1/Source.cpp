#include<iostream>
using namespace std;
struct HT_item {
	int number;
	char* fio;
};
struct Hash_table {
	HT_item** items;
	Linked_List** overflow_buckets;
	int size;
	int count;
};
struct Linked_List {
	HT_item* item;
	Linked_List* next;
};
int Hash_fun(int num) {
	int N = 13; double A = 0.618033;
	int h = N * fmod(num * A, 1);
	return h;
}
HT_item* create_item(int number, char* fio) {
	HT_item* item = new HT_item;
	item->number = number;
	strcpy(item->fio, fio);
	return item;
}
