/// ���������� ������, �� �������� ������� (a*(b+c))/d, �� ������� ������ �� 
/// ���� ���������� � �������� "+,*,-,/", � �������� - ���� a, b, c, d.
/// ����������� ������ �������� ���� ������ �� �����, �� ������ ������� �������.

#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string nums;
	cout << "������ a, b, c �� d (����� ������ ����� �����): ";
	getline(cin, nums);
	Node* Root = createTree(nums);
	outputTree(Root, 0);

	cout << "\n\n";
	outputTreeCorrect(Root);
	cout << "\n\n";

	clearMemory(Root);
	free(Root);

	system("pause");
	return 0;
}