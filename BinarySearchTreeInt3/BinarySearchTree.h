#pragma once
#include "Node.h"
using namespace  std;

class BinarySearchTree
{
	static void addNode(Node* node, int num);
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);

	static void countNodes(Node* node, int& count);
	static void countHeight(Node* node, int& height, int i);
	static void printNodeCoordInLevel(Node* node, int level, int i, int& branch);

public:
	Node* Root;

	BinarySearchTree(int* nums, int n);

	void printTree();
	void clearMemory();
	int countNodes();
	void printNodeCoordinates();
};
