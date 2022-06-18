#pragma once
#include <iostream>
class Node
{
	char key;

public:
	Node* left,
		* right;

	Node(char key);

	void setKey(char key);
	char getKey();
};
