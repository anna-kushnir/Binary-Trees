/// Побудувати дерево, що відображає формулу (a*(b+c))/d, де коренем дерева та 
/// його підкоренями є операції "+,*,-,/", а листками - змінні a, b, c, d.
/// Надрукувати дерево переліком своїх вершин на рівнях, які містять відповідні вершини.

#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string nums;
	cout << "Введіть a, b, c та d (одним рядком через пробіл): ";
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