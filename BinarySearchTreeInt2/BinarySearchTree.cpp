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
	else if (key == node->getKey()) {
		return;
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
