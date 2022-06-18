#include "Node.h"

Node::Node()
{
	key = "";
	left = NULL;
	right = NULL;
}
Node::Node(string key)
{
	this->key = key;
	left = NULL;
	right = NULL;
}

void Node::setKey(string key)
{
	this->key = key;
}
string Node::getKey()
{
	return key;
}
