// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void dfs(TreeNode* root, int sum, int &ret)
	{
		if(!root)
			return;
		sum = sum*10+root->val;
		if(!root->left && !root->right)
		{
			ret += sum;
		}
		dfs(root->left, sum, ret);
		dfs(root->right, sum ,ret);
	}
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int ret = 0;
		int sum = 0;
		dfs(root, sum, ret);
		return ret;
	}
};
int main() {
	TreeNode root(1);
	TreeNode n1(2);
	TreeNode n2(3);
	root.left = &n1;
	root.right = &n2;
	Solution sol;
	cout<<sol.sumNumbers(&root);
	getchar();
	return 0;
}