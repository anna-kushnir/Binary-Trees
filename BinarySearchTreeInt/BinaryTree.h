#pragma once
#include "Node.h"
#include <iostream>
class BinaryTree
{
private:
	static void printTree(Node* node, int level);
	static void addNode(int newKey, Node* node);
	static void clearMemory(Node* node);

public:
	Node* Root;

	BinaryTree();
	BinaryTree(Node* Root);
	BinaryTree(int rootKey);

	void addNode(int newKey);
	void printTree();
	void clearMemory();
};
