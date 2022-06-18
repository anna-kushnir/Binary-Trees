#pragma once
#include <string>
using namespace std;
class Node
{
	string key;

public:
	Node* left,
		* right;

	Node();
	Node(string key);

	void setKey(string key);
	string getKey();
};
