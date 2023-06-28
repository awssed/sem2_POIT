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
	Tree* Prev = NULL;	     // Prev - элемент перед текущим
	bool find = false;        // признак поиска
	while (t && find == false)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->left;
			else t = t->right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->left = t;    //переход на левую ветвь,
		else
			Prev->right = t;   // либо на правую 
	}
	return t;
}
Tree* makeTree(Tree* Root, int n) {
	int key;
	if (Root == NULL) {
		cout << "Введите ключ корня" << endl;
		cin >> key;
		Root = list(key);
	}
	for (int i = 0; i < n; i++) {
		cout << "Введите ключ" << endl;
		cin >> key;
		insertElem(Root, key);
	}
	return Root;
}
Tree* Delete(Tree* Root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->right == NULL) // поиск элемента R для замены
		R = Del->left;		// переход на левую ветвь
	else
		if (Del->left == NULL)
			R = Del->right;		// или на правую
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R; // на левую ветвь 
		else
			Prev_Del->right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
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
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	удаление элемента\n";
		cout << "4 -	вывод дерева\n";
		cout << "5 -	очистка дерева\n";
		cout << "6 -	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		Tree* t = Root;
		cout << "\n";
		switch (choice)
		{
		case 1:
			cout << "Введите количество элементов" << endl;
			cin >> n;
			Root = makeTree(Root, n);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите значение: ";
			cin >> s;
			insertElem(Root, key); break;
		case 3:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = Delete(Root, key);  break;
		case 4:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 5:  delAll(Root); break;
		case 6:  exit(0); break;
		case 7:heapify(Root);
		}
	}
}
