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
BinaryTree::BinaryTree(double* arrayKeys, int n)
{
	this->Root = createTree(arrayKeys, 0, n);
}

Node* BinaryTree::createTree(double* arrayKeys, int index, int n)
{
	Node* node = new Node(arrayKeys[index]);
	if (2 * index + 1 < n) {
		node->left = createTree(arrayKeys, 2 * index + 1, n);
	}
	if (2 * index + 2 < n) {
		node->right = createTree(arrayKeys, 2 * index + 2, n);
	}
	return node;
}

void BinaryTree::deleteNodes(Node* node)
{
	if (node->left != NULL) {
		deleteNodes(node->left);
	}
	if (node->right != NULL) {
		deleteNodes(node->right);
	}
	free(node);
}

void BinaryTree::clearMemory()
{
	deleteNodes(Root);
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
