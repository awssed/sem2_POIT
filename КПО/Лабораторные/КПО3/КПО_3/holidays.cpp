#include"stdafx.h"
string holidays(int number_of_day)
{
	switch (number_of_day)
	{
	case 1:
		return "����� ���";
	case 7:
		return "C ���������� !";
	case 54:
		return "���� ��������� ���������";
	case 67:
		return "C ������������� ������� ���!";
	case 121:
		return "C ���������� ����� � �����!";
	case 129:
		return "� ��� ������!";
	case 256:
		return "� ��� ����������� !";
	case 260:
		return "C ��� ��������� �������� !";
	default:
		break;
	}
	return "���� ����������. ��� �������!!!!";
}
