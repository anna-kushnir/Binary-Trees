#include "BinarySearchTree.h"

void BinarySearchTree::addNode(Node* node, char symb)
{
	if (symb > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(symb);
		}
		else {
			addNode(node->right, symb);
		}
	}
	if (symb < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(symb);
		}
		else {
			addNode(node->left, symb);
		}
	}
}
BinarySearchTree::BinarySearchTree(string symbs)
{
	Root = new Node(symbs[0]);
	for (int i = 0; i < symbs.size(); ++i) {
		addNode(Root, symbs[i]);
	}
}

void BinarySearchTree::printTree(Node* node, int level)
{
	if (node != NULL) {
		printTree(node->left, level + 1);
		for (int i = 0; i < level; ++i) {
			cout << "\t";
		}
		cout << "  " << node->getKey() << "\n";
		printTree(node->right, level + 1);
	}
}
void BinarySearchTree::printTree()
{
	printTree(Root, 0);
}

void BinarySearchTree::clearMemory(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	if (node->left != NULL) {
		clearMemory(node->left);
	}
	if (node->right != NULL) {
		clearMemory(node->right);
	}
}
void BinarySearchTree::clearMemory()
{
	clearMemory(Root);
}


void BinarySearchTree::countEven(Node* node, int& count)
{
	if (node != NULL) {
		if (isdigit(node->getKey()) && node->getKey() % 2 == 0) {
			count++;
		}
		countEven(node->left, count);
		countEven(node->right, count);
	}
}

int BinarySearchTree::whereMoreEvenNums()
{
	int leftCount = 0, rightCount = 0;
	countEven(Root->left, leftCount);
	countEven(Root->right, rightCount);
	return leftCount > rightCount ? 1 : leftCount < rightCount ? 2 : 0;
}

void BinarySearchTree::printEvenNums(Node* node)
{
	if (node != NULL) {
		if (isdigit(node->getKey()) && node->getKey() % 2 == 0) {
			cout << node->getKey() << "  ";
		}
		printEvenNums(node->left);
		printEvenNums(node->right);
	}
}
