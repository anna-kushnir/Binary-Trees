// ����������� ����� ��� ������������� ��������� ������ ������, ���������� ����� � �������, �� �� ������������.
// ���������� ��������� ������������, ����� ��������� ������, ���� ������ ��� ��������� ������������ ��������. 
// ������ ������� ������ �� ������� ����� (����� ����) �� ������ �� �������� �������, ��������� � ���������.
// �������� ������� ������������� ������ ��������� ��� �������, �������� �� �������� �����, � ����� �������� 
// �������� �������. ��� ������� ������� (� ���� ���� �� ���������� �������� �����) ����������� �������� ��������.

#include "functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	cout << "������ �����: "; cin >> str;

	string newStr = deleteRecurringSymbs(str);
	cout << "\n�������� ���� ����� ���� ��������� �������, �� ������������: " << newStr;

	BinarySearchTree Tree(newStr);

	cout << "\n\n�������� ������:\n\n";
	Tree.printTree();

	int height = Tree.countHeight();
	cout << "\n\n������� ������: " << height;

	char ch;
	cout << "\n\n������ ������, ���� �� ����� �� ������ ������: "; cin >> ch;
	int way = Tree.countWay(ch);
	if (way == -1) {
		cout << "\n�������� ������ �� ��������� � �����!\n\n";
	}
	else {
		cout << "\n���� �� ��������� ������� �����: " << way << "\n\n";
	}

	Tree.clearMemory();

	system("pause");
	return 0;
}
