#include"dictionary.h"
using namespace dictionary;

Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
	Instance newDict;
	if (strlen(name) > DICTNAMEMAXSIZE) {
		throw(char*)TROW01;
	}
	for (int i = 0; i < strlen(name); i++) {
		newDict.name[i] = name[i];
	}
	newDict.name[strlen(name)] = '\0';
	if (size > DICTMAXSIZE) {
		throw(char*)TROW02;
	}
	newDict.maxsize = size;
	newDict.size = 0;
	return newDict;
}
void AddEntry(Instance& inst, Entry ed) {
	if (inst.size == inst.maxsize) {
		throw(char*)TROW03;
	}
	for (int i = 0; i < inst.size; i++) {
		if (ed.id == inst.dictionary[i].id) {
			throw(char*)TROW04;
		}
	}
	inst.size++;
	inst.dictionary = new Entry[inst.size];
	inst.dictionary[inst.size].id = ed.id;
	for (int i = 0; i < strlen(ed.name); i++) {
		inst.dictionary[inst.size].name[i] = ed.name[i];
	}
	inst.dictionary[inst.size].name[strlen(ed.name)] = '\0';
}
void DelEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			delete[] & (inst.dictionary[i]);
		}
	}
	throw(char)TROW06;
}
Entry GetEntry(Instance& inst, int id) {
	Entry GetElement;
	for (int i = 0; i < inst.size; i++) {
		if (id == inst.dictionary[i].id) {
			GetElement.id = inst.dictionary[i].id;
			for (int j = 0; j < strlen(inst.dictionary[i].name); j++) {
				GetElement.name[j] = inst.dictionary[i].name[j];
			}
			return GetElement;
		}
	}
	throw(char)TROW05;
}
void UpdEntry(Instance& inst, int id, Entry new_ed) {
	for (int i = 0; i < inst.size; i++) {
		if (id == inst.dictionary[i].id) {
			if (inst.dictionary[i].name == new_ed.name) {
				throw(char*)TROW08;
			}
			inst.dictionary[i].id = new_ed.id;
			for (int j = 0; j < strlen(new_ed.name); j++) {
				inst.dictionary[i].name[j] = new_ed.name[j];
			}
			inst.dictionary[i].name[strlen(new_ed.name)] = '\0';
			return;
		}
	}
	throw(char*)TROW07;

}

void Delete(Instance& inst) {
	for (int i = 0; i < inst.size; i++) {
		delete& inst.dictionary[i];
	}
	inst.maxsize = NULL;
	inst.size = NULL;
}
void Print(Instance inst) {
	std::cout << "-------" << inst.name << "-------" << std::endl;
	for (int i = 0; i < inst.size; i++) {
		std::cout << inst.dictionary[i].id << ' ';
		for (int j = 0; j < strlen(inst.dictionary[i].name); j++) {
			std::cout << inst.dictionary[i].name[j];
		}
		std::cout << std::endl;
	}
}