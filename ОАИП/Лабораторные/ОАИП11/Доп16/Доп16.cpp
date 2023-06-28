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
		t = list(key, el);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->left = t;    //переход на левую ветвь,
		else
			Prev->right = t;   // либо на правую 
	}
	return t;
}
Tree* makeTree(Tree* Root, int n) {
	int key;
	int el;
	if (Root == NULL) {
		cout << "Введите ключ корня" << endl;
		cin >> key;
		cout << "Введите значение корня" << endl;
		cin >> el;
		Root = list(key, el);
	}
	for (int i = 0; i < n; i++) {
		cout << "Введите ключ" << endl;
		cin >> key;
		cout << "Введите значение" << endl;
		cin >> el;
		insertElem(Root, key, el);
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
		cout << "Нет такого элемента" << endl;
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
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -    cумма значений листев\n";
		cout << "7 -	очистка дерева\n";
		cout << "8 -	выход\n";
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
			insertElem(Root, key, s); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденное значение";
			cout << rc->el << endl;
			break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = Delete(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:
			sum = 0;
			Sum(t);
			cout << "Сумма значений листьев" << sum << endl;
			break;
		case 7:  delAll(Root); break;
		case 8:  exit(0);
		}
	}
}
