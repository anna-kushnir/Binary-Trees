#pragma once
#include "Node.h"
#include <string>
using namespace std;

class BinaryTree
{
	static Node* createTree(string symbs, int index);
	static void printTree(Node* node, int level);
	static void deleteNodes(Node* node);
	static void findInlevel(Node* node, int level, int& branch, int i, char& max);
	static void countHeight(Node* node, int i, int& height);
public:
	Node* Root;

	BinaryTree();
	BinaryTree(string symbs);
	
	void printTree();
	void clearMemory();
	char findLeafs();
};
