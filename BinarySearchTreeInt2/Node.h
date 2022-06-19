#pragma once
#include <iostream>
class Node
{
	int key;

public:
	Node* left,
		* right;

	Node(int key);

	void setKey(int key);
	int getKey();
};
