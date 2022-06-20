#pragma once
#include "Node.h"
#include <string>
using namespace std;

class BinarySearchTree
{
	static void addNode(char symb, Node* node);
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);

	static void countHeight(Node* node, int& height, int i);
	static void countWay(Node* node, char ch, int& way);
public:
	Node* Root;

	BinarySearchTree(string symbs);

	void printTree();
	void clearMemory();

	int countHeight();
	int countWay(char ch);
};
