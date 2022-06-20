#pragma once
#include <string>
#include "Node.h"
using namespace std;

class BinarySearchTree
{
	static void addNode(Node* node, char symb);
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);

	static void countEven(Node* node, int& count);

public:
	Node* Root;

	BinarySearchTree(string symbs);

	void printTree();
	void clearMemory();
	int whereMoreEvenNums();

	static void printEvenNums(Node* node);
};
