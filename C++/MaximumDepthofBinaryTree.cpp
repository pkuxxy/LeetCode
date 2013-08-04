#include<iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int max(int a, int b)
	{
		return a>b?a:b;
	}
	int maxDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};