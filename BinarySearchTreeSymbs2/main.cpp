// ����������� ����� ��� ������������� ��������� ������ ������, �� ���� �������� �����, �� �� ������������.
// ���������� ��������� ������������, ����� ��������� ������, ���� ������ ��� ��������� ������������ ��������. 
// ��������� � ����� ������� (����� ��� �������) ������� ������ �������� �����.
// ������� �� �������� �� ����� ��� ������� �������� ������.
// �������� ������� ������������� ������ ��������� ��� �������, �������� �� �������� �����, � ����� �������� 
// �������� �������. ��� ������� ������� (� ���� ���� �� ���������� �������� �����) ����������� �������� ��������.

// 19:14

#include "functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	cout << "������ �����: "; cin >> str;
	string newStr = deleteRecurringSymbs(str);
	cout << "\n�������� ����� � ���������� ���������, �� ������������: " << newStr;

	BinarySearchTree Tree(newStr);
	cout << "\n\n�������� ������:\n\n";
	Tree.printTree();

// 19:37
	
	int flag = Tree.whereMoreEvenNums();
	switch (flag) {
	case 1:
		cout << "\n\nʳ������ ������ �������� ����� � ����� �������.";
		break;
	case 2:
		cout << "\n\nʳ������ ������ �������� ����� � ������� �������.";
		break;
	default:
		cout << "\n\nʳ������ ������ �������� �������� � ����� �� ������� ���������.";
	}

//19:58

	cout << "\n\n����� �������� ����� ��������: ";
	Tree.printEvenNums(Tree.Root->left);
	cout << "\n\n����� �������� ������� ��������: ";
	Tree.printEvenNums(Tree.Root->right);
	cout << "\n\n";

// 20:05

	Tree.clearMemory();

	system("pause");
	return 0;
}