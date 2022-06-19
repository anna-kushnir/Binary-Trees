#include "Node.h"
using namespace std;

Node::Node(char key)
{
	this->key = key;
	count = 1;
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

void Node::increaseCount()
{
	count++;
}
int Node::getCount()
{
	return count;
}
