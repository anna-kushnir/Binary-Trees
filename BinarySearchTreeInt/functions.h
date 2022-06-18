#include "BinaryTree.h"
#include <Windows.h>
#include <iostream>

BinaryTree createTree();

void countHeight(Node* node, int& i, int& height);
void findNodesInLevel(Node* node, int level, int i, int& branch, int& count);
int findNodes(Node* Root);
