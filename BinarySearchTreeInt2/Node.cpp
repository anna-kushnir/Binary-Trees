#include "Node.h"
using namespace std;

Node::Node(int key)
{
	this->key = key;
	left = NULL;
	right = NULL;
}

void Node::setKey(int key)
{
	this->key = key;
}
int Node::getKey()
{
	return key;
}
