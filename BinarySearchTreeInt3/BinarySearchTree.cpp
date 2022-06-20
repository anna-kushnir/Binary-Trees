#include "BinarySearchTree.h"
using namespace std;

void BinarySearchTree::addNode(Node * node, int num)
{
	if (num > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(num);
		}
		else {
			addNode(node->right, num);
		}
	}
	else if (num < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(num);
		}
		else {
			addNode(node->left, num);
		}
	}
}
BinarySearchTree::BinarySearchTree(int* nums, int n)
{
	Root = new Node(nums[0]);
	for (int i = 1; i < n; ++i) {
		addNode(Root, nums[i]);
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

void BinarySearchTree::countNodes(Node* node, int& count)
{
	if (node->left != NULL || node->right != NULL) {
		count++;
	}
	if (node->left != NULL) {
		countNodes(node->left, count);
	}
	if (node->right != NULL) {
		countNodes(node->right, count);
	}
}
int BinarySearchTree::countNodes()
{
	int count = 0;
	countNodes(Root, count);
	return count;
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
void BinarySearchTree::printNodeCoordInLevel(Node* node, int level, int i, int& branch)
{
	if (i == level) {
		branch++;
		if (node->left != NULL || node->right != NULL) {
			cout << "[ " << level << " ; " << branch << " ]\n";
		}
	}
	if (node->left != NULL) {
		i++;
		printNodeCoordInLevel(node->left, level, i, branch);
		i--;
	}
	if (node->right != NULL) {
		i++;
		printNodeCoordInLevel(node->right, level, i, branch);
		i--;
	}
}
void BinarySearchTree::printNodeCoordinates()
{
	int height = 0;
	countHeight(Root, height, 0);
	for (int level = 0; level <= height; ++level) {
		int branch = 0;
		printNodeCoordInLevel(Root, level, 0, branch);
	}
}
