#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int ret;
	int maxSumWithNode(TreeNode* root)
	{
		if(!root)
			return 0;
		int leftMax = maxSumWithNode(root->left);
		int rightMax = maxSumWithNode(root->right);
		int localMax = root->val + max(0,leftMax) + max(0,rightMax);
		if(ret < localMax)
			ret = localMax;
		return root->val + max(max(0,leftMax),rightMax);
	}
	int maxPathSum(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret = INT_MIN;
		if(!root)
			return 0;
		maxSumWithNode(root);
		return ret;
	}
};
int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	Solution sol;
	cout<<sol.maxPathSum(&root);
	getchar();
}