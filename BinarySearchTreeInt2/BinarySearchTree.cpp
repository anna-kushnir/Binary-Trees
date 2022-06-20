#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(int* nums, int n)
{
	Root = new Node(nums[0]);
	for (int i = 1; i < n; ++i) {
		addNode(nums[i], Root);
	}
}
void BinarySearchTree::addNode(int key, Node* node)
{
	if (key > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(key);
		}
		else addNode(key, node->right);
	}
	else if (key < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(key);
		}
		else addNode(key, node->left);
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

void BinarySearchTree::deleteNodes(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	if (node->left != NULL) {
		deleteNodes(node->left);
	}
	if (node->right!= NULL) {
		deleteNodes(node->right);
	}
}
void BinarySearchTree::clearMemory()
{
	deleteNodes(Root);
}

void BinarySearchTree::countMaxHeight(Node* node, int i, int& height)
{
	if (node->left != NULL) {
		i++;
		if (i > height) {
			height = i;
		}
		countMaxHeight(node->left, i, height);
		i--;
	}
	if (node->right != NULL) {
		i++;
		if (i > height) {
			height = i;
		}
		countMaxHeight(node->right, i, height);
		i--;
	}
}
void BinarySearchTree::countMinHeight(Node* node, int i, int& height)
{
	if (node->left != NULL) {
		i++;
		countMinHeight(node->left, i, height);
		i--;
	}
	if (node->right != NULL) {
		i++;
		countMinHeight(node->right, i, height);
		i--;
	}
	if (node->left == NULL || node->right == NULL) {
		if (i < height) {
			height = i;
		}
	}
}

bool BinarySearchTree::isBalanced()
{
	int min, max = 0;
	countMaxHeight(Root, 0, max);
	min = max;
	countMinHeight(Root, 0, min);
	return (min + 1 >= max) ? true : false;
}
