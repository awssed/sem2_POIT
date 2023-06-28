#pragma once
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct  Node
{
	int key;
	int data;
	int count;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* node = nullptr;
	int counter;
	void AddNode(int k);
	void PrintTree(Node* temp, int l);
	void Delete(int k);
	int Height(Node* temp);
	bool IsBalanced(Node* temp);
	void DirectBypass(Node* temp);
	void ReverseBypass(Node* temp);
	void MyTask(Node* temp, int l);
	void DownScan(Node* temp);
	int check_right(Node* temp);
	int sumtask(Node* tmp);
};