#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
class Heap {
	static const int SIZE = 100;
	int* h2;
	int left = 0, right = 0;
public:
	int* h;
	int HeapSize;
	Heap();
	void addElem(int n);
	void outHeap();
	void getMax();
	void out();
	void outMas();
	void heapify(int i);
	void getMin();
	void getI(int i);
};
Heap::Heap() {
	h = new int[SIZE];
	HeapSize = 0;
}
void Heap::addElem(int n) {
	int i, parent;
	for (int i = 0; i < HeapSize; i++) {
		if (h[i] == n) {
			return;
		}
	}
	i = HeapSize;
	h[i] = n;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (h[i] > h[parent]) {
			int temp = h[i];
			h[i] = h[parent];
			h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}
void Heap::outMas() {
	for (int i = 0; i < HeapSize; i++) {
		cout << h[i] << "  ";
	}
	cout << endl;
}
void Heap::out() {
	const int levels = log2(HeapSize) + 1;

	std::vector<int> offsets(levels + 1, 0);
	for (int i = offsets.size() - 2; i >= 0; --i)
		offsets[i] = 2 * offsets[i + 1] + 2;

	auto printOffset = [](int offset) {
		for (int i = 0; i < offset; ++i) std::cout << ' ';
	};

	for (int level = 0; level < levels; ++level)
	{
		printOffset(offsets[level]);
		for (int j = pow(2, level) - 1; j < min(HeapSize, int(pow(2, level + 1)) - 1); ++j) {
			std::cout << std::setw(2) << h[j];
			if (level) printOffset(offsets[level - 1]);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Heap::heapify(int i){
	int temp;
	left = i * 2 + 1;
	right = i * 2 + 2;
	if (left < HeapSize) {
		if (h[i] < h[left]) {
			temp = h[i];
			h[i] = h[left];
			h[left] = temp;
			heapify(left);
			heapify(right);
		}
	}
	if (right < HeapSize) {
		if (h[i] < h[right]) {
			temp = h[i];
			h[i] = h[right];
			h[right] = temp;
			heapify(right);
			heapify(left);
		}
	}
}
void Heap::getMax() {
	int x;
	x = h[0];
	h[0] = h[HeapSize - 1];
	HeapSize--;
	heapify(0);
}void Heap::getMin() {
	int min=999;
	int minI;
	for (int i = 0; i < HeapSize; i++) {
		if (min > h[i]) {
			min = h[i];
			minI = i;
		}
	}
	Heap h2;
	for (int i = 0; i < HeapSize; i++) {
		if (h[i] != h[minI]) {
			h2.addElem(h[i]);
		}
	}
	HeapSize--;
}
void Heap::getI(int i) {
	int tmp = h[i];
	Heap h2;
	int q = 0;
	for (int j = 0; j < HeapSize;j++) {
		if (h[j] != tmp) {
			h2.addElem(h[j]);
		}

	}
	h = h2.h;
	HeapSize--;
}
void unionHeap(Heap H1, Heap H2) {
	Heap H3;
	for (int i = 0; i < H1.HeapSize; i++) {
		H3.addElem(H1.h[i]);
	}
	for (int i = 0; i < H2.HeapSize; i++) {
		H3.addElem(H2.h[i]);
	}
	for (int i = 0; i<H3.HeapSize; i++) {
		H1.h[i] = H3.h[i];
	}
	H1.HeapSize = H3.HeapSize;
	H1.out();
}
int main() {
	setlocale(LC_ALL, "rus");
	Heap heap;
	Heap heap2;
	int k;
	int a;
	for (;;) {;
		cout << "1-Добавление элемента" << endl;
		cout << "2-удалить максимальный элемент" << endl;
		cout << "3-Вывод в виде дерева" << endl;
		cout << "4-Вывод в виде массива" << endl;
		cout << "5-Удаление минимального элемента" << endl;
		cout << "6-Удаление i-го элемента" << endl;
		cout << "7-Заполнить вторую кучу" << endl;
		cout << "8-Вывести вторую кучу" << endl;
		cout << "9-Обеденить кучи и вывести " << endl;
		cin >> a;
		switch (a) {
		case 1:
			cout << "Введите ключ" << endl;
			cin >> k;
			heap.addElem(k);
			break;
		case 2:
			heap.getMax();
			break;
		case 3:
			heap.out();
			break;
		case 4:
			heap.outMas();
			break;
		case 5:
			heap.getMin();
			break;
		case 6:
			cout << "Введите удаляемый элемент" << endl;
			cin >> k;
			heap.getI(k);
			break;
		case 7:
			cout << "Введите ключ" << endl;
			cin >> k;
			heap2.addElem(k);
			break;
		case 8:
			heap2.out();
			break;
		case 9:
			unionHeap(heap, heap2);
			break;
		}
	}
}