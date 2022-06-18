#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree()
{
	Root = NULL;
}
BinaryTree::BinaryTree(string symbs)
{
	Root = createTree(symbs, 0);
}

void BinaryTree::printTree(Node* node, int level)
{
	if (node != NULL) {
		printTree(node->right, level + 1);
		for (int i = 0; i < level; ++i) {
			cout << "\t";
		}
		cout << "  " << node->getKey() << "\n";
		printTree(node->left, level + 1);
	}
}
void BinaryTree::printTree()
{
	printTree(Root, 0);
}

void BinaryTree::deleteNodes(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	if (node->left != NULL) {
		deleteNodes(node->left);
	}
	if (node->right != NULL) {
		deleteNodes(node->right);
	}
}
void BinaryTree::clearMemory()
{
	deleteNodes(Root);
}

Node* BinaryTree::createTree(string symbs, int index)
{
	Node* node = new Node(symbs[index]);
	if (2 * index + 1 < size(symbs)) {
		node->left = createTree(symbs, 2 * index + 1);
	}
	if (2 * index + 2 < size(symbs)) {
		node->right = createTree(symbs, 2 * index + 2);
	}
	return node;
}

void BinaryTree::countHeight(Node* node, int i, int& height)
{
	if (i > height) {
		height = i;
	}
	if (node->left != NULL) {
		i++;
		countHeight(node->left, i, height);
		i--;
	}
	if (node->right != NULL) {
		i++;
		countHeight(node->right, i, height);
		i--;
	}
}

void BinaryTree::findInlevel(Node* node, int level, int& branch, int i, char& max)
{
	if (i == level) {
		branch++;
		if (node->left == NULL && node->right == NULL) {
			if (node->getKey() >= max) {
				max = node->getKey();
			}
			cout << "[ " << level << " ; " << branch << " ] : " << node->getKey() << "\n";
			return;
		}
	}
	if (node->left != NULL) {
		i++;
		findInlevel(node->left, level, branch, i, max);
		i--;
	}
	if (node->right != NULL) {
		i++;
		findInlevel(node->right, level, branch, i, max);
		i--;
	}
}
char BinaryTree::findLeafs()
{
	int height = 0;
	countHeight(Root, 0, height);
	char max = 0;
	for (int level = 0; level <= height; ++level) {
		int branch = 0;
		findInlevel(Root, level, branch, 0, max);
	}
	return max;
}
