#include "Node.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>

Node* createTree(string nums);
void countHeight(Node* Tree, int& i, int& height);

void outputTree(Node* Tree, int level);

void outputLevel(Node* Tree, int level, int& i);
void outputTreeCorrect(Node* Tree);

void clearMemory(Node* Tree);
