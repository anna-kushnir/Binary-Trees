#include "Node.h"
using namespace std;

Node::Node(char key)
{
	this->key = key;
	left = NULL;
	right = NULL;
}

void Node::setKey(char key)
{
	this->key = key;
}
char Node::getKey()
{
	return key;
}
