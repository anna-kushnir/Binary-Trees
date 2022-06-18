#include "functions.h"
using namespace std;

BinaryTree createTree()
{
	char flag = 'Y';
	int num;
	BinaryTree Tree;
	while (true) {
		cout << "Введіть корінь дерева (перше число послідовності): ";
		try {
			cin >> num;
			if (cin.fail()) throw "Некоректне введення числа!";
			else {
				Tree.Root = new Node(num);
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректне введення даних: ви повинні ввести ціле число!\n";
		}
	}
	while (flag == 'Y' || flag == 'y') {
		cout << "\nВведіть число: ";
		try {
			cin >> num;
			if (cin.fail()) throw "Некоректне введення числа!";
			else {
				Tree.addNode(num); 
				cin.clear();
				cin.ignore(32767, '\n');
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректне введення даних: ви повинні ввести ціле число!\n";
			continue;
		}
		cout << "Бажаєте продовжити введення? (Y/N) "; cin >> flag;
	}
	return Tree;
}

void countHeight(Node* node, int& i, int& height)
{
	if (node->left != NULL) {
		i++;
		if (height < i) {
			height = i;
		}
		countHeight(node->left, i, height);
		i--;
	}
	if (node->right != NULL) {
		i++;
		if (height < i) {
			height = i;
		}
		countHeight(node->right, i, height);
		i--;
	}
}

void findNodesInLevel(Node* node, int level, int i, int& branch, int& count)
{
	if (i == level) {
		branch++; 
		if (node->left != NULL || node->right != NULL) {
			count++;
			cout << "[ " << level << " ; " << branch << " ]\n";
		}
	}
	if (node->left != NULL) {
		i++;
		findNodesInLevel(node->left, level, i, branch, count);
		i--;
	}
	if (node->right != NULL) {
		i++;
		findNodesInLevel(node->right, level, i, branch, count);
		i--;
	}
}

int findNodes(Node* Root)
{
	int count = 0, branch = 1;
	if (Root->left != NULL || Root->right != NULL) {
		count++;
		cout << "[ 0 ; 1 ]\n";
		int i = 0, height = 0;
		countHeight(Root, i, height);
		for (int level = 1; level <= height; ++level) {
			branch = 0;
			findNodesInLevel(Root, level, 0, branch, count);
		}
	}
	return count;
}