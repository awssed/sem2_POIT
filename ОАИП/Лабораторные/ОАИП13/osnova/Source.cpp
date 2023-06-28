#include<iostream>
using namespace std;

struct Tree {
	int key;
	Tree* left;
	Tree* right;
};


int keys[1000];
int temp;
int count1 = 0;
int size(Tree* t, int level) {
	if (t) {
		size(t->right, level + 1);
		count1++;
		size(t->left, level + 1);
	}
	return count1;
}
void heapify(Tree* item) {
	Tree* left = item->left;
	Tree *right=item->right;
	if (size(item, 0) < 1) {
		return;
	}
	if (right == NULL && left == NULL) {
		return;
	}
	if (left != NULL) {
		if (item->key < left->key) {
			temp = item->key;
			item->key = left->key;
			left->key = temp;
		}
	}
	if (right != NULL) {
		if (item->key < right->key) {
			temp = item->key;
			item->key = right->key;
			right->key = temp;
		}
	}
	if(left!=NULL)
		heapify(left);
	if(right!=NULL)
		heapify(right);
}
Tree* list(int key) {
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	t->left = t->right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key) {
	Tree* Prev = NULL;	     // Prev - ������� ����� �������
	bool find = false;        // ������� ������
	while (t && find == false)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->key) t = t->left;
			else t = t->right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		t = list(key);           //��������� ����� ���� 
		if (key < Prev->key)  // � �������������� ���� 
			Prev->left = t;    //������� �� ����� �����,
		else
			Prev->right = t;   // ���� �� ������ 
	}
	return t;
}
Tree* makeTree(Tree* Root, int n) {
	int key;
	if (Root == NULL) {
		cout << "������� ���� �����" << endl;
		cin >> key;
		Root = list(key);
	}
	for (int i = 0; i < n; i++) {
		cout << "������� ����" << endl;
		cin >> key;
		insertElem(Root, key);
	}
	return Root;
}
Tree* Delete(Tree* Root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->right == NULL) // ����� �������� R ��� ������
		R = Del->left;		// ������� �� ����� �����
	else
		if (Del->left == NULL)
			R = Del->right;		// ��� �� ������
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R; // �� ����� ����� 
		else
			Prev_Del->right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}
void view(Tree* t, int level) {
	if (t) {
		view(t->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << ' ';
		}
		int tm = t->key;
		cout << tm << ' ';
		cout << endl;
		view(t->left, level + 1);
	}
}

void delAll(Tree* t) {
	if (t != NULL) {
		delAll(t->left);
		delAll(t->right);
		delete t;
	}
}
Tree* Root = NULL;
void main()
{
	setlocale(0, "Russian");
	int key, choice, n;
	Tree* rc; int s;
	for (;;)
	{
		cout << "1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	�������� ��������\n";
		cout << "4 -	����� ������\n";
		cout << "5 -	������� ������\n";
		cout << "6 -	�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		Tree* t = Root;
		cout << "\n";
		switch (choice)
		{
		case 1:
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			Root = makeTree(Root, n);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;
			cout << "������� ��������: ";
			cin >> s;
			insertElem(Root, key); break;
		case 3:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = Delete(Root, key);  break;
		case 4:  if (Root->key >= 0)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 5:  delAll(Root); break;
		case 6:  exit(0); break;
		case 7:heapify(Root);
		}
	}
}
