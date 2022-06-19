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
	else if (symb < node->getKey()) {
		if (node->left == NULL) {
			node->left = new Node(symb);
		}
		else {
			addNode(node->left, symb);
		}
	}
	else {
		node->increaseCount();
	}
}

BinarySearchTree::BinarySearchTree(string symbs)
{
	Root = new Node(symbs[0]);
	for (int i = 1; i < symbs.size(); ++i) {
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


Node* BinarySearchTree::findMinNode(Node* node)
{
	Node* currentNode = node;
	while (currentNode->left != NULL) {
		currentNode = currentNode->left;
	}
	return currentNode;
}
Node* BinarySearchTree::deleteNode(char symb, Node* node)
{
	if (node == NULL) {
		return node;
	}
	if (symb > node->getKey()) {
		node->right = deleteNode(symb, node->right);
	}
	else if (symb < node->getKey()) {
		node->left = deleteNode(symb, node->left);
	}
	else {
		if (node->left == NULL) {
			return node->right;
		}
		else if (node->right == NULL) {
			return node->left;
		}
		Node* temp = findMinNode(node->right);
		node->setKey(temp->getKey());
		node->right = deleteNode(temp->getKey(), node->right);
		free(temp);
	}
	return node;
}
Node* BinarySearchTree::deleteRecurringNodes(Node* node)
{
	if (node != NULL) {
		node->left = deleteRecurringNodes(node->left);
		node->right = deleteRecurringNodes(node->right);
		if (node->getCount() > 1) {
			node = deleteNode(node->getKey(), node);
		}
	}
	return node;
}
void BinarySearchTree::deleteRecurringNodes()
{
	Root = deleteRecurringNodes(Root);
}
