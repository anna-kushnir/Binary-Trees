#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree()
{
	this->Root = NULL;
}
BinaryTree::BinaryTree(Node* Root)
{
	this->Root = Root;
}
BinaryTree::BinaryTree(int rootKey)
{
	this->Root = new Node(rootKey);
}

void BinaryTree::addNode(int newKey, Node* node)
{
	if (newKey > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(newKey);
		}
		else {
			addNode(newKey, node->right);
		}

	}
	else if (newKey < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(newKey);
		}
		else {
			addNode(newKey, node->left);
		}
	}
	else if (newKey == node->getKey()) {
		return;
	}
}
void BinaryTree::addNode(int newKey)
{
	addNode(newKey, Root);
}

void BinaryTree::printTree(Node* node, int level)
{
	if (node != NULL) {
		printTree(node->right, level + 1);
		for (int i = 0; i < level; ++i) {
			cout << "\t";
		}
		cout << "  " << node->getKey() << "\n\n";
		printTree(node->left, level + 1);
	}
}
void BinaryTree::printTree()
{
	if (Root != NULL) {
		printTree(Root, 0);
	}
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
	if (node->right != NULL){
		clearMemory(node->right);
	}
}

void BinaryTree::clearMemory()
{
	clearMemory(Root);
	free(Root);
}
