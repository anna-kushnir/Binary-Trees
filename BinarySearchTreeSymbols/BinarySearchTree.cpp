#include "BinarySearchTree.h"
using namespace std;

void BinarySearchTree::addNode(char symb, Node* node)
{
	if (symb > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(symb);
		}
		else {
			addNode(symb, node->right);
		}
	}
	else if (symb < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(symb);
		}
		else {
			addNode(symb, node->left);
		}
	}
}
BinarySearchTree::BinarySearchTree(string symbs)
{
	Root = new Node(symbs[0]);
	for (int i = 1; i < symbs.size(); ++i) {
		addNode(symbs[i], Root);
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

void BinarySearchTree::countHeight(Node* node, int& height, int i)
{
	if (node->left != NULL) {
		i++;
		if (i > height) {
			height = i;
		}
		countHeight(node->left, height, i);
		i--;
	}
	if (node->right != NULL) {
		i++;
		if (i > height) {
			height = i;
		}
		countHeight(node->right, height, i);
		i--;
	}
}
int BinarySearchTree::countHeight()
{
	int height = 1;
	countHeight(Root, height, 1);
	return height;
}

void BinarySearchTree::countWay(Node* node, char ch, int& way)
{
	if (ch > node->getKey()) {
		if (node->right == NULL) {
			way = -1;
			return;
		}
		way++;
		countWay(node->right, ch, way);
	}
	else if (ch < node->getKey()) {
		if (node->left == NULL) {
			way = -1;
			return;
		}
		way++;
		countWay(node->left, ch, way);
	}
	else {
		return;
	}
}
int BinarySearchTree::countWay(char ch)
{
	int way = 1;
	countWay(Root, ch, way);
	return way;
}
