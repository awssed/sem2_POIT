#include"stdafx.h"
string holidays(int number_of_day)
{
	switch (number_of_day)
	{
	case 1:
		return "Новый год";
	case 7:
		return "C Рождеством !";
	case 54:
		return "День Защитника Отечества";
	case 67:
		return "C Международным женским днём!";
	case 121:
		return "C Праздником весны и труда!";
	case 129:
		return "С днём Победы!";
	case 256:
		return "С днём програмиста !";
	case 260:
		return "C Днём народного единства !";
	default:
		break;
	}
	return "Нету прздиников. Иди работай!!!!";
}
