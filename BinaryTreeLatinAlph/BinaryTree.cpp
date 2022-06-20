#include "BinaryTree.h"

BinaryTree::BinaryTree(string symbs)
{
	Root = createTree(Root, symbs, 0);
}
Node* BinaryTree::createTree(Node* root, string symbs, int index)
{
	Node* node = new Node(symbs[index]);
	if (2 * index + 1 < symbs.size()) {
		node->left = createTree(node->left, symbs, 2 * index + 1);
	}
	if (2 * index + 2 < symbs.size()) {
		node->right = createTree(node->left, symbs, 2 * index + 2);
	}
	return node;
}

void BinaryTree::printTree(Node* node, int level)
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
void BinaryTree::printTree()
{
	printTree(Root, 0);
}
void BinaryTree::clearMemory(Node* node)
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
void BinaryTree::clearMemory()
{
	clearMemory(Root);
}


void BinaryTree::countOccurences(Node* node, char symb, int& count)
{
	if (node->getKey() == symb) {
		count++;
	}
	if (node->left != NULL) {
		countOccurences(node->left, symb, count);
	}
	if (node->right != NULL) {
		countOccurences(node->right, symb, count);
	}
}
int BinaryTree::countOccurrences(char symb)
{
	int count = 0;
	countOccurences(Root, symb, count);
	return count;
}

void BinaryTree::countHeight(Node* node, int& height, int i)
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
void BinaryTree::outputInLevel(Node* node, char symb, int level, int i, int& branch)
{
	if (i == level) {
		branch++;
		if (node->getKey() == symb) {
			cout << "[ " << level << " ; " << branch << " ]\n";
		}
	}
	if (node->left != NULL) {
		i++;
		outputInLevel(node->left, symb, level, i, branch);
		i--;
	}
	if (node->right != NULL) {
		i++;
		outputInLevel(node->right, symb, level, i, branch);
		i--;
	}
}
void BinaryTree::outputSymbPos(char symb)
{
	int height = 0;
	countHeight(Root, height, 0);
	for (int level = 0; level <= height; ++level) {
		int branch = 0;
		outputInLevel(Root, symb, level, 0, branch);
	}
}
