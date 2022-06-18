#pragma once
#include "Node.h"
class BinaryTree
{
	static void deleteTree(Node* node);
	static void printTree(Node* node, int level);
	static void findLeafs(Node* node, double* leafs, int& index);

public:
	Node* Root;

	BinaryTree();
	BinaryTree(Node* Root);
	BinaryTree(double* arrayKeys, int n);

	static Node* createTree(double* arrayKeys, int index, int n);
	void printTree();
	void clearMemory();
	double* findLeafs(int m);
};
