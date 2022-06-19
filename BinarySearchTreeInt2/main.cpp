// ����������� ����� ��� ������������� ��������� ������ ������, � �������� ����� ����������� ��� �����. 
// ���������� ��������� ������������, ����� ��������� ������, ���� ������ ��� ��������� ������������ ��������. 
// ��������� �� � ������ �������������.
// �������� ������� ������������� ������ ��������� ��� �������, �������� �� �������� �����, � ����� �������� 
// �������� �������. ��� ������� ������� (� ���� ���� �� ���������� �������� �����) ����������� �������� ��������.

#include "functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = inputNumOfElem();
	int* nums = inputArray(n);

	BinarySearchTree Tree(nums, n);
	delete[] nums;

	cout << "\n������� ���� ������:\n\n";
	Tree.printTree();
	cout << "\n\n";
	Tree.clearMemory();

	system("pause");
	return 0;
}
