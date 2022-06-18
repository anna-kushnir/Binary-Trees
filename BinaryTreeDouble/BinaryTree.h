#pragma once
#include "Node.h"
class BinaryTree
{
	static void deleteNodes(Node* node);
	static void printTree(Node* node, int level);
public:
	Node* Root;

	BinaryTree();
	BinaryTree(Node* Root);
	BinaryTree(double* arrayKeys, int n);

	static Node* createTree(double* arrayKeys, int index, int n);
	void printTree();
	void clearMemory();
};
