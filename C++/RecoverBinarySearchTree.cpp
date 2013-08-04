#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode* pre;
	void inorderFromLeft(TreeNode* root)
	{
		if(left)
			return;
		if(!root)
			return;
		inorderFromLeft(root->left);
		if(pre)
		{
			if(pre->val >= root->val)
			{
				left = pre;
				return;
			}
		}
		pre = root;
		inorderFromLeft(root->right);
	}
	void inorderFromRight(TreeNode* root)
	{
		if(right)
			return;
		if(!root)
			return;
		inorderFromRight(root->right);
		if(pre)
		{
			if(pre->val <= root->val)
			{
				right = pre;
				return;
			}
		}
		pre = root;
		inorderFromRight(root->left);
	}
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		left = NULL;
		right = NULL;
		pre = NULL;
		inorderFromLeft(root);
		pre = NULL;
		inorderFromRight(root);
		int tmp = left->val;
		left->val = right->val;
		right->val = tmp;
	}
};