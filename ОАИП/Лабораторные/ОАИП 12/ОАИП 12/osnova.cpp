#include "Tree.h"
#include <fstream>
int sum2 = 0;
void main()
{
	Tree* mainRoot = new Tree;
	int choice;


	while (1)
	{
		system("cls");
		int numRight = 0;
		if (!mainRoot->node) cout << "The tree is empty.\n";
		else mainRoot->PrintTree(mainRoot->node, 0);
		cout << "\n";
		cout << "1 - Add elements;\n";
		cout << "2 - Delete element;\n";
		cout << "3 - Downward tree walk;\n";
		//cout << "4 - Reverse tree walk;\n";
		cout << "5 - Mixed tree walk;\n";
		cout << "6 - Check if the is balanced;\n";
		cout << "7 - Count the summ of all the elements\n";
		cout << "0 - Exit.\n";
		cout << "Your choise: ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
		{
			int value;
			cout << "input the element" << endl;
			string temp;
			cin >> temp;
			char temp1[10] = "         ";
			bool flag = false;
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == '.')
					flag = true;
			}
			for (int i = 0; i < temp.length(); i++) {
				temp1[i] = temp[i];
			}
			if (flag == false)
				value = atoi(temp1);
			else {
				cout << "Incorrect input" << endl;
				break;
			}
			mainRoot->AddNode(value);
			break;
		}

		case 2:
		{
			int key;
			cout << "Enter the element to delete: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 3:
		{
			if (!mainRoot->node) cout << "the tree is empty.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}
		/*
		case 4:
		{
			if (!mainRoot->node) cout << "The tree is empty.\n";
			else mainRoot->DownScan(mainRoot->node);
			break;
		}
		*/

		case 5:
		{
			if (!mainRoot->node) cout << "The tree is empty.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}

		case 6:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "The tree is empty.\n";
			else
				if (mainRoot->IsBalanced(mainRoot->node))
					cout << "The tree is balanced." << endl;
				else
					cout << "The tree is NOT balanced." << endl;
			break;
		}
		case 7: {
			sum2 = 0;
			cout << "The summ of all the elements is " << mainRoot->sumtask(mainRoot->node) << endl;
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}

		default:
		{
			cout << "Incorrect input. Your chouise?.\n";
			break;
		}

		}
		system("pause");
	}
}