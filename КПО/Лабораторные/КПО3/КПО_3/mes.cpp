#include"stdafx.h"
string mes(int month) {
	string monthes[12] = { "Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь", };
	return monthes[month - 1];
}