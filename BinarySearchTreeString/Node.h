#pragma once
#include <iostream>
#include <string>
class Node
{
	char key;
	int count;

public:
	Node* left,
		* right;

	Node(char key);

	void setKey(char key);
	char getKey();

	void increaseCount();
	int getCount();
};
