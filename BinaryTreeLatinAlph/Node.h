#pragma once
#include <iostream>
using namespace std;

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
