#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;
using namespace std;
struct Address
{
	int el;
	Address* next;
	Address* prev;
};

Address* head = NULL;
Address* last = NULL;
//-----------------------------------------------------------


void addXBegin(int x) {
	Address* buf;
	Address* pred = head;
	buf = new(Address);
	buf->el = x;
	head = buf;
	buf->next = pred;
	/*Address* buf;
	Address* pred;
	pred = last->prev;
	buf = new(Address);
	buf->el = x;
	buf->next = last;
	pred->next = buf;*/
	
}

void menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод" << endl;
	cout << "2. Удаление" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Чтение из файла" << endl;
	cout << "7.Добавлнеи элемента в начало" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	int el;
	cin >> el;
	temp->el = el;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->el<< endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(int el, Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (t->el==el) break;
		t = t->next;
	}
	if (!t)
		cerr << "не найдено" << endl;
	else
		cout << t->el << ' ' << t->next <<' ' <<t->prev<< endl;
}
//-----------------------------------------------------------
void delet(int el, Address** phead, Address** plast){  // Удаление имени {	
	struct Address* t = *phead;
	while (t->el!=el)
	{
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

//-----------------------------------------------------------

int main(void)
{
	int el;
	int a;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		menu();
		cin >> a;
		switch (a)
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> el;
			delet(el, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> el;
			find(el, &head);
		}
			  break;
		case 5:writeToFile(&head);
			break;
		case 6:readFromFile(&head, &last);
			break;
		case 7:
			cin >> el;
			addXBegin(el);
			break;
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
