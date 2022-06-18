// Спроєктувати класи для представлення бінарного дерева, елементами
// якого є дійсні числа. Реалізувати необхідні конструктори, метод
// виведення дерева, інші методи для виконання поставленого завдання.
// Вивести термінальні вершини (листя) цього дерева у порядку зростання 
// їх значень, а також середнє арифметичне значення цих вершин.
// Програма повинна забезпечувати наочне виведення усіх вхідних, вихідних
// та проміжних даних, а також контроль можливих помилок. Для обробки помилок
// (у тому числі і не коректного введення даних) використати виключні ситуації.

#include "functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	double* nums = inputNums(n);
	if (n == 0) {
		cout << "Дерево не має вершин!\n";
		return 0;
	}

	BinaryTree Tree = BinaryTree::createTree(nums, 0, n);
	delete[] nums;

	cout << "\nВведене вами дерево:\n\n";
	Tree.printTree();
	cout << "\n";

	int m = n - pow(2, floor(log2(n))) + 1;
	m = m + ceil(pow(2, floor(log2(n)) - 1)) - floor((m + 1) / 2);
	cout << "Кількість термінальних вершин: " << m << "\n";

	double* leafs = Tree.findLeafs(m);
	cout << "Невідсортований перелік термінальних вершин: ";
	for (int i = 0; i < m; ++i) {
		cout << leafs[i] << "  ";
	}
	
	sortArray(leafs, m);
	cout << "\n\nВідсортований перелік термінальних вершин: ";
	for (int i = 0; i < m; ++i) {
		cout << leafs[i] << "  ";
	}

	double average = countAverage(leafs, m);
	cout << "\n\nСереднє арифметичне значень листків дерева: " << average << "\n\n";

	delete[] leafs;
	Tree.clearMemory();

	system("pause");
	return 0;
}
