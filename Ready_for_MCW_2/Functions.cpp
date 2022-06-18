#include "Functions.h"
using namespace std;

///					 /
///			*					d
///		a			+
///				b		c

Node* createTree(string nums)
{
	int k1 = nums.find(" "),
		k2 = nums.find(" ", k1 + 1),
		k3 = nums.find(" ", k2 + 1),
		k4 = nums.find(" ", k3 + 1);
	if (k4 == string::npos) {
		k4 = nums.length();
	}
	string a = nums.substr(0, k1),
		b = nums.substr(k1 + 1, k2 - k1 - 1),
		c = nums.substr(k2 + 1, k3 - k2 - 1),
		d = nums.substr(k3 + 1, k4 - k3 - 1);
	Node* Root = new Node("/");
	Node* Rl = new Node("*");
	Root->left = Rl;
	Node* Rr = new Node(d);
	Root->right = Rr;
	Node* Rll = new Node(a);
	Root->left->left = Rll;
	Node* Rlr = new Node("+");
	Root->left->right = Rlr;
	Node* Rlrl = new Node(b);
	Root->left->right->left = Rlrl;
	Node* Rlrr = new Node(c);
	Root->left->right->right = Rlrr;
	return Root;
}

void countHeight(Node* Tree, int& i, int& height)
{
	if (Tree->left != NULL) {
		i++;
		if (height < i) {
			height = i;
		}
		countHeight(Tree->left, i, height);
		i--;
	}
	if (Tree->right != NULL) {
		i++;
		if (height < i) {
			height = i;
		}
		countHeight(Tree->right, i, height);
		i--;
	}
}

void outputTree(Node* Tree, int level)
{
	if (Tree != NULL) {
		outputTree(Tree->right, level + 1);
		for (int i = 0; i < level; ++i) {
			cout << "\t";
		}
		cout << "  " << Tree->getKey() << "\n";
		outputTree(Tree->left, level + 1);
	}
}

void outputLevel(Node* Tree, int level, int& i)
{
	if (i == level) {
		cout << Tree->getKey() << "\t";
	}
	if (Tree->left != NULL) {
		i++;
		outputLevel(Tree->left, level, i);
		i--;
	}
	if (Tree->right != NULL) {
		i++;
		outputLevel(Tree->right, level, i);
		i--;
	}
}

void outputTreeCorrect(Node* Tree)
{
	int height = 0, j = 0;
	countHeight(Tree, j, height);
	for (int level = 0; level <= height; ++level) {
		if (level == 0) {
			cout << "Root (0):\t";
		}
		else {
			cout << "\nLevel " << level << " :\t";
		}
		int i = 0;
		outputLevel(Tree, level, i);
	}
}

void clearMemory(Node* Tree)
{
	if (Tree->left != NULL) {
		clearMemory(Tree->left);
		free(Tree->left);
	}
	if (Tree->right != NULL) {
		clearMemory(Tree->right);
		free(Tree->right);
	}
}