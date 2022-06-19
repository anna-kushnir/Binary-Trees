#pragma once
#include "Node.h"
class BinarySearchTree
{
	static void printTree(Node* node, int level);
	static void deleteNodes(Node* node);
	static void addNode(int key, Node* node);

public:
	Node* Root;

	BinarySearchTree(int* nums, int n);

	void printTree();
	void clearMemory();
};
