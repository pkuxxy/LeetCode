#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
struct BinaryTree
{
	int val;
	BinaryTree* left;
	BinaryTree* right;
};
struct Node
{
	int val;
	Node* next;
	Node(int v)
	{
		val = v;
		next = NULL;
	}
};

struct LRNode
{
	Node* left;
	Node* right;
	LRNode(Node* l, Node* r)
	{
		left = l;
		right = r;
	}
};
LRNode convert(BinaryTree* root)
{
	if(!root)
		return LRNode(NULL, NULL);
	LRNode left = convert(root->left);
	LRNode right = convert(root->right);
	Node* n = new Node(root->val);
	if(left.right)
	{
		left.right->next = n;
	}
	n->next = right.left;
	Node* ln = left.left ? left.left : n;
	Node* rn = right.right ? right.right : n;
	return LRNode(ln, rn);
}
Node* BST2List(BinaryTree* root)
{
	LRNode lr = convert(root);
	return lr.left;
}
int main() {

	getchar();
	return 0;
}