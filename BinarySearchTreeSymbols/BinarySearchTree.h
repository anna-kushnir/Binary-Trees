#pragma once
#include "Node.h"
#include <string>
using namespace std;

class BinarySearchTree
{
	static Node* findMinNode(Node* node);
	static Node* deleteNode(char symb, Node* node);
	static void addNode(char symb, Node* node);
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);

public:
	Node* Root;

	BinarySearchTree(string symbs);

	void printTree();
	void clearMemory();
};
