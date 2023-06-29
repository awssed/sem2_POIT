#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

	using namespace std;


	int main() {
		setlocale(LC_ALL, "Russian");
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10 };
		int target1 = 3;
		int num_items1 = count(v.begin(), v.end(), target1);
		cout << "�����: " << target1 << " ���������� " << num_items1 << '\n';
		//[](i) {}(i)
		//[i]() {}()
		//[] - �����, ���. ����� �������� ����� ������������ �������� (�� ��������, �� ������
		//() - ����� ��������� �� ����� ���������
		//{} - ���� �������
		int num_item3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
		cout << "���������� ��������� ������� 3 " << num_item3 << '\n';
		cout << endl << "������, ������ ����������" << endl;

		for (auto i : v)[i]() {if (i % 3 == 0) cout << i << " "; }();

		cout << endl << " ������ � �����������" << endl;

		for (auto i : v)[](auto i) {if (i % 3 == 0) cout << i << " "; }(i);

		cout << endl << " ������ ��� ����������" << endl;

		for (auto i : v)[i] {if (i % 3 == 0)cout << i << " "; }();

		cout << endl;
		// ������������� 1
		float z = 5;

		if ([](auto y) {if (y >= 0) { return true; } else { return false; }}(z))
			cout << "true\n";
		else
			cout << "false\n";
		// ������������� 2
		auto lambda_dop2 = [](auto x) {
			if (x < 0)
				return false;
			if ((int)x > 127)
				return false;
			else
				return true;
		};
		cout << lambda_dop2(5) << endl;
		cout << lambda_dop2(-3) << endl;
		cout << lambda_dop2('d') << endl;
		cout << lambda_dop2('g') << endl;



		return 0;
	}