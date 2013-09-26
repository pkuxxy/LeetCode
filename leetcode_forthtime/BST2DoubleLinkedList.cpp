#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
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
LRNode convert(Node* root)
{
	if(!root)
		return LRNode(NULL, NULL);
	LRNode left = convert(root->left);
	LRNode right = convert(root->right);
	root->left = left.right;
	if(left.right)
		left.right->right = root;
	root->right = right.left;
	if(right.left)
		right.left->left = root;
	Node* leftNode = left.left? left.left : root;
	Node* rightNode = right.right ? right.right : root;
	return LRNode(leftNode, rightNode);
}
Node* BST2List(Node* root)
{
	LRNode lr = convert(root);
	return lr.left;
}
int main() {

	getchar();
	return 0;
}