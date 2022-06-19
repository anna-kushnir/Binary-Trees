#pragma once
#include "Node.h"
using namespace std;
class BinarySearchTree
{
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);

	static void addNode(Node* node, char symb);
	static Node* findMinNode(Node* node);
	static Node* deleteNode(char symb, Node* node);
	static Node* deleteRecurringNodes(Node* node);

public:
	Node* Root;

	BinarySearchTree(string symbs);

	void printTree();
	void clearMemory();

	void deleteRecurringNodes();
};
