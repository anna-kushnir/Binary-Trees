#pragma once
#include "Node.h"
using namespace std;

class BinaryTree
{
	static void printTree(Node* node, int level);
	static void clearMemory(Node* node);
	static Node* createTree(Node* root, string symbs, int index);

	static void countOccurences(Node* node, char symb, int& count);

	static void countHeight(Node* node, int& height, int i);
	static void outputInLevel(Node* node, char symb, int level, int i, int& branch);

public:
	Node* Root;

	BinaryTree(string symbs);

	void printTree();
	void clearMemory();
	
	int countOccurrences(char symb);

	void outputSymbPos(char symb);
};
