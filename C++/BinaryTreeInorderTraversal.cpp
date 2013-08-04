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
	vector<int> ret;
	void solve(TreeNode* root)
	{
		if(!root)
			return;
		solve(root->left);
		ret.push_back(root->val);
		solve(root->right);
	}
	vector<int> inorderTraversal(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		solve(root);
		return ret;
	}
};