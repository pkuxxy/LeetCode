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
BinaryTree* getCloestLarge(BinaryTree* root, int target)
{
	if(!root)
		return NULL;
	if(root->val > target)
	{
		BinaryTree* ll = getCloestLarge(root->left, target);
		return ll ? ll : root;
	}
	else
	{
		return getCloestLarge(root->right, target);
	}
}
int main() {

	getchar();
	return 0;
}