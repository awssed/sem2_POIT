#include<iostream>
#include<string>
using namespace std;
struct sk {
	char el;
	sk* next;
};
void Push(struct sk** top, char x);
void Pop(sk** top);
void main(){
	setlocale(LC_ALL, "rus");
	string tmp;
	sk* head = NULL;
	sk* buf = new sk;
	getline(cin, tmp);
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '[' || tmp[i] == '{' || tmp[i] == '(') {
			Push(&head, tmp[i]);
		}
		if (tmp[i] == ']' && head->el == '[') {
			Pop(&head);
		}
		if (tmp[i] == '}' && head->el == '{') {
			Pop(&head);
		}
		if (tmp[i] == ')' && head->el == '(') {
			Pop(&head);
		}
	}
	if (head == NULL) {
		cout << "Скобички раставлены правильно" << endl;
	}
	else {
		cout << "Скобички раставлены неправильно" << endl;

	}
}
void Push(struct sk** top, char x) {
	sk* buf = new (sk);
	buf->el = x;
	buf->next = *top;
	*top = buf;
}
void Pop(sk** top) {
	sk* buf = new(sk);
	buf = *top;
	*top = buf->next;
	delete buf;
}