#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isLeaf(TreeNode* root)
	{
		if(root == NULL)
			return false;
		else if(root->left == NULL && root->right == NULL)
			return true;
		return false;
	}
	bool hasPathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return false;
		if(isLeaf(root) && root->val == sum)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

	}
};