#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int Peek(Node* top);
int show(Node* top);
int clear(Node** top);
int toFile(Node** top);
int fromFile();
int menu();