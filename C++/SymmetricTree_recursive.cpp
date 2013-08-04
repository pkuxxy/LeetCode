#include<iostream>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isChildSym(TreeNode* left, TreeNode* right)
	{
		if(left == NULL && right == NULL)
			return true;
		else if(left == NULL || right == NULL)
			return false;
		if(left->val != right->val)
			return false;
		return isChildSym(left->left, right->right) && isChildSym(left->right, right->left);
	}
	bool isSymmetric(TreeNode* root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return true;
		return isChildSym(root->left, root->right);
	}
};