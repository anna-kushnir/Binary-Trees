#pragma once
#include <iostream>
class Node
{
	double key;

public:
	Node* left,
		* right;

	Node(double key);

	void setKey(double key);
	double getKey();
};
