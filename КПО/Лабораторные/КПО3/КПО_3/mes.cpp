#include"stdafx.h"
string mes(int month) {
	string monthes[12] = { "������","�������","����","������","���","����","����","������","��������","�������","������","�������", };
	return monthes[month - 1];
}