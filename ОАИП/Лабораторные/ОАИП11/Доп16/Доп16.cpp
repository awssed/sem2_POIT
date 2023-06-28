#include<iostream>
using namespace std;

struct Tree {
	int key;
	int el;
	Tree* left;
	Tree* right;
};


int keys[1000];

Tree* list(int key, int el) {
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	t->el = el;
	t->left = t->right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key, int el) {
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
		t = list(key, el);           //��������� ����� ���� 
		if (key < Prev->key)  // � �������������� ���� 
			Prev->left = t;    //������� �� ����� �����,
		else
			Prev->right = t;   // ���� �� ������ 
	}
	return t;
}
Tree* makeTree(Tree* Root, int n) {
	int key;
	int el;
	if (Root == NULL) {
		cout << "������� ���� �����" << endl;
		cin >> key;
		cout << "������� �������� �����" << endl;
		cin >> el;
		Root = list(key, el);
	}
	for (int i = 0; i < n; i++) {
		cout << "������� ����" << endl;
		cin >> key;
		cout << "������� ��������" << endl;
		cin >> el;
		insertElem(Root, key, el);
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
Tree* search(Tree* n, int key) {
	Tree* rc = n;
	if (rc != NULL) {
		if (key < (key, n->key)) {
			rc = search(n->left, key);
		}
		else {
			if (key > (key, n->key)) {
				rc = search(n->right, key);
			}
		}
	}
	else {
		cout << "��� ������ ��������" << endl;
		return NULL;
	}
	return rc;
}
void view(Tree* t, int level) {
	if (t) {
		view(t->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << ' ';
		}
		int tm = t->key;
		cout << tm << ' ';
		cout << t->el << endl;
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
int sum = 0;
int Sum(Tree* t) {
	if (t) {
		if (t->left == NULL & t->right == NULL) {
			sum += t->el;
		}
		Sum(t->right);
		Sum(t->left);
	}
	return sum;
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
		cout << "3 -	����� �� �����\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -    c���� �������� ������\n";
		cout << "7 -	������� ������\n";
		cout << "8 -	�����\n";
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
			insertElem(Root, key, s); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			cout << "��������� ��������";
			cout << rc->el << endl;
			break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = Delete(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6:
			sum = 0;
			Sum(t);
			cout << "����� �������� �������" << sum << endl;
			break;
		case 7:  delAll(Root); break;
		case 8:  exit(0);
		}
	}
}
