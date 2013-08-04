#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<queue>
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
	bool solve(int l, int r, TreeNode* root)
	{
		if(!root)
			return true;
		if(!(l <= root->val && root->val <= r))
			return false;
		return solve(l, root->val-1, root->left) && solve(root->val+1, r, root->right);
	}
	bool isValidBST(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return solve(1<<31, (1<<31)-1, root);
	}
};