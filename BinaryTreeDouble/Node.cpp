#include "Node.h"
using namespace std;

Node::Node(double key)
{
	this->key = key;
	left = NULL;
	right = NULL;
}

void Node::setKey(double key)
{
	this->key = key;
}
double Node::getKey()
{
	return key;
}
