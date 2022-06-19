#include "BinarySearchTree.h"

Node* BinarySearchTree::findMinNode(Node* node)
{
	Node* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

Node* BinarySearchTree::deleteNode(char symb, Node* node)
{
	if (node == NULL) {
		return node;
	}
	if (symb > node->getKey()) {
		node->right = deleteNode(symb, node->right);
	}
	if (symb < node->getKey()) {
		node->left = deleteNode(symb, node->left);
	}
	else {
		if (node->left == NULL) {
			return node->right;
		}
		if (node->right == NULL) {
			return node->left;
		}
		Node* temp = findMinNode(node->right);
		node->setKey(temp->getKey());
		node->right = deleteNode(temp->getKey(), node->right);
		free(temp);
	}
	return node;
}
void BinarySearchTree::addNode(char symb, Node* node)
{
	if (symb > node->getKey()) {
		if (node->right == NULL) {
			node->right = new Node(symb);
			return;
		}
		else {
			addNode(symb, node->right);
		}
	}
	else if (symb < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(symb);
			return;
		}
		else {
			addNode(symb, node->left);
		}
	}
	else {
		node = deleteNode(symb, node);
		return;
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
		printTree(node->left, level + 1);
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
